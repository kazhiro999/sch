// code for a huffman coder

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "huff.h"
#include "bitfile.h"

#include <stdint.h>


int num_chars = 256;

struct huffcoder * huffcoder_new() {
   struct huffcoder * temp = malloc(sizeof(struct huffcoder));
   for(int i=0; i<256; i++) {
  	temp->freqs[i] = 0;
  	temp->code_lengths[i]=0;
  	temp->codes[i]=0;
   }
   return temp;
};


void huffcoder_count(struct huffcoder * this, char * filename) {
   unsigned char c;  // we need the character to be unsigned to use it as an index
   FILE * file;

   file = fopen(filename, "r");
   assert( file != NULL );
   c = fgetc(file);	// attempt to read a byte

   while( !feof(file) ) {
 	printf("%c", c);
 	this->freqs[c]++;
 	c = fgetc(file);
   }
   fclose(file);

   for(int j=0; j<NUM_CHARS; j++) {
  	if(this->freqs[j]==0) this->freqs[j]=1;
   }
}

//create a leaf node for each character
struct huffchar * huffchar_createSimpleNode(int i, int freqs) {
   struct huffchar * node = malloc(sizeof(struct huffchar));
   node->freq = freqs;
   node->is_compound = 0;

   node->seqno = i;
   node->u.c = i;
   node->u.compound.left = NULL;
   node->u.compound.right = NULL;
   return node;
}

struct huffchar * huffchar_find_remove_smallest(struct huffchar ** list, int nchars) {
   struct huffchar * result = malloc(sizeof(struct huffchar));
   int smallest = 0;
   for(int i=0; i<nchars; i++) {
  	if(list[i]->freq < list[smallest]->freq) {
     	smallest=i;
  	}
  	else if((list[i]->freq == list[smallest]->freq) && (list[i]->seqno < list[smallest]->seqno)) {
     	smallest=i;
  	}
   }
   result = list[smallest];
   list[smallest] = list[nchars-1];
   return result;
}

struct huffchar * huffchar_createCompoundNode(struct huffchar * smallest, struct huffchar * smallestTwo,
                                          	int seqno) {
   struct huffchar * result = malloc(sizeof(struct huffchar));
   
   int sum = smallest->freq + smallestTwo->freq;
   result->freq = sum;
   result->is_compound = 1;
   result->seqno = seqno;
   result->u.c = 0;
   result->u.compound.left = smallest;
   result->u.compound.right = smallestTwo;
   return result;
}

void huffcoder_build_tree(struct huffcoder * this) {
   int nchars = NUM_CHARS; //256
   int newSeqno = NUM_CHARS;
   struct huffchar ** alphabet = malloc(sizeof(struct huffchar *) *nchars);

   for(int i=0; i<nchars; i++) {
  	alphabet[i] = huffchar_createSimpleNode(i, this->freqs[i]);
   }
   
   while(nchars>1) { //do till there is more than one in the queue
  	struct huffchar * smallest = malloc(sizeof(struct huffchar));
  	smallest = huffchar_find_remove_smallest(alphabet, nchars);
  	nchars--;
  	struct huffchar * smallestTwo = malloc(sizeof(struct huffchar));
  	smallestTwo = huffchar_find_remove_smallest(alphabet, nchars);
  	struct huffchar * compound = malloc(sizeof(struct huffchar));
  	compound = huffchar_createCompoundNode(smallest, smallestTwo, newSeqno);
  	newSeqno++;
  	alphabet[nchars-1] = compound;
   }
   this->tree = alphabet[0];
}

void huffcoder_write_code(struct huffcoder * tmp, struct huffchar * this, int * path, int depth) {
   if(this->u.compound.left != NULL) {
  	path[depth] = 0;
  	huffcoder_write_code(tmp,this->u.compound.left, path, depth+1);
   }
   if(this->u.compound.right != NULL) {
  	path[depth] = 1;
  	huffcoder_write_code(tmp,this->u.compound.right, path, depth+1);
   }

   if((this->u.compound.right==NULL)&&(this->u.compound.left==NULL)) {
  	for(int i=depth-1; i>=0; i--) {
     	tmp->codes[this->seqno] = (tmp->codes[this->seqno]<<1 | path[i]);
  	}
  	tmp->code_lengths[this->seqno] = depth;
   }
}

// using the Huffman tree, build a table of the Huffman codes
// with the huffcoder obshowcodes.studentject
void huffcoder_tree2table(struct huffcoder * this) {
   int num_chars = 256;
   int * path[num_chars];
   for(int i=0; i<num_chars; i++) {
  	path[i] = 0;
   }
   int depth = 0;
   
   huffcoder_write_code(this, this->tree, path, depth);
}


// print the Huffman codes for each character in order
void huffcoder_print_codes(struct huffcoder * this) {


   int i, j;
   char buffer[NUM_CHARS];

   for ( i = 0; i < NUM_CHARS; i++ ) {
 	// put the code into a stringe
 	assert(this->code_lengths[i] < NUM_CHARS);
 	for ( j = this->code_lengths[i]-1; j >= 0; j--) {
   	buffer[j] = ((this->codes[i] >> j) & 1) + '0';
 	}
 	// don't forget to add a zero to end of string
 	buffer[this->code_lengths[i]] = '\0';

 	// print the codei
 	printf("char: %d, freq: %d, code: %s\n", i, this->freqs[i], buffer);
   }
}

// encode the input file and write the encoding to the output file
void huffcoder_encode(struct huffcoder * this, char * input_filename,
          	char * output_filename) {
   struct bitfile * bf;
   bf = bitfile_open(output_filename, "w");
   FILE * file;
   file = fopen(input_filename, "r");
   unsigned char c ;
   c = fgetc(file);
   int writecount=0;
   
   while( !feof(file) ) {
  	u_int64_t code = this->codes[c];
  	//printf("code is: %d\n", code);
  	int length = this->code_lengths[c];
  	for(int i=0; i<length; i++) {
     	bitfile_write_bit(bf, (code>>i)&1);
     	writecount++;
  	}
  	c = fgetc(file);
   }

   
   u_int64_t code = this->codes[4];
   int length = this->code_lengths[4];
   for(int i=0; i<length; i++) {
  	bitfile_write_bit(bf, (code>>i)&1);
  	writecount++;
   }
   if(writecount%8 != 0) {
  	int remaincounter = 8-(writecount%8);
  	for(int i=remaincounter; i>0 ;i--) {
     	bitfile_write_bit(bf, 0);
     	remaincounter--;
  	}
   }
   fclose(file);
}


// decode the input file and write the decoding to the output file
void huffcoder_decode(struct huffcoder * this, char * input_filename,
          	char * output_filename) {

   struct bitfile * bf;
   bf = bitfile_open(output_filename, "r");
   FILE * file;
   file = fopen(output_filename, "r");
   unsigned char c;
   c = fgetc(file);

   int bitcounter = 0;

   while ( !feof(file) ) {
        printf("whileeeeee");
  	u_int64_t code = this->codes[c];
  	int length = this->code_lengths[c];

  	c = c<<(bitcounter) & bitfile_read_bit(bf);

  	for(int i=0; i<length; i++){
     	if(this->codes[4] != c) {
        	bitcounter++;
        	if(this->codes[i] == c) {
           	fputc(c, file);
        	}
     	}
     	else if (this->codes[4] == c) {
        	bitfile_end_of_file(bf);
     	} 	 
  	}
  	c = fgetc(file);
   }
}
 





