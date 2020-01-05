// C code file for  a file ADT where we can read a single bit at a
// time, or write a single bit at a time

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "bitfile.h"

// open a bit file in "r" (read) mode or "w" (write) mode
struct bitfile * bitfile_open(char * filename, char * mode) {
   struct bitfile * bf;
   bf = malloc(sizeof(struct bitfile));
   bf->file = fopen(filename, mode);

   if(bf->file != NULL) {
  	bf->buffer = 0;
  	bf->index = 0;
  	bf->is_read_mode = (int)&mode;
  	bf->is_EOF = 0;
   }
   return bf;
}

// write a bit to a file; the file must have been opened in write mode
void bitfile_write_bit(struct bitfile * this, int bit) {
   this->buffer = this->buffer | bit<<(this->index);
   this->index++;
   if(this->index==8) {
  	fputc( this->buffer, this->file);
  	this->buffer = 0;
  	this->index = 0;
   }
   else {
  	//printf("else\n");
   }
}

// read a bit from a file; the file must have been opened in read mode
int bitfile_read_bit(struct bitfile * this) { //decode only
   printf("readdddd");
   this->buffer = this->buffer | 0;
   printf("buffer is: %d\n", this->buffer);
   return this->buffer;
}

// close a bitfile; flush any partially-filled buffer if file is open
// in write mode
void bitfile_close(struct bitfile * this) {
}

// check for end of files
int bitfile_end_of_file(struct bitfile * this) {
  	return this->is_EOF = 1;
}








