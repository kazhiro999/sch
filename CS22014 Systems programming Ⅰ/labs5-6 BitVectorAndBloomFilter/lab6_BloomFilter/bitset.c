#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitset.h"
#include <stdbool.h>

// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size) {
   struct bitset * result = malloc(sizeof(struct bitset));
   result->universe_size = size;
   result->size_in_words = 0;
   result->bits = malloc(sizeof (int)* size);
	for(int i = 0; i<result->size_in_words; i++){
	result->bits[i] = 0;
	}
   return result;

}

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this) {
   return this->universe_size; 
}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this){
   return this->size_in_words;
}

// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item){
   if(item<0 || item>=this->universe_size) {
      return -1;
   }
   else {
      for(int i=0; i<this->size_in_words; i++) {
         //printf("the number of size of words is %d",this->size_in_words);
         //printf("this->bits[i] is %ld\n ", this->bits[i]);
         if((this->bits[i]) == item) return 1;
      }

      return 0;
   }
}

// add an item, with number 'item' to the setbitset_lookup
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item) {
   
   *(this->bits + this->size_in_words) = item;
   this->size_in_words++;
}
  
// remove an item withnumber 'item' from the set
void bitset_remove(struct bitset * this, int item) {
   //printf("item is %d\n",item);
   _Bool moreThanSecond = false;
   for(int i=0; i<bitset_cardinality(this); i++) {
      if(this->bits[i]==item){
         //printf("through if\n");
         //printf("this->bits[i] is %d\n",this->bits[i]);
         //printf("item is %d\n", item);
         for(int j=i;j<bitset_cardinality(this)&&moreThanSecond;j++){
            //printf("through for\n");
           this->bits[j]=this->bits[j+1];
           this->size_in_words--;
           //j--;
         }
         moreThanSecond = true;
      }


   }
}
  
// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1,
		  struct bitset * src2) {

   /*for(int i=0; i<src1->size_in_words; i++) {
	//bitset_print(src1);
	
	printf("src2->bits[i] is %ld\n ", src2->bits[i]);
      //dest->bits[i] = src1->bits[i] | src2->bits[i];

      int temp = (dest->bits[i]);
      temp = (src1->bits[i])| (src2->bits[i]);
      printf("temp is %d\n ", temp);
      //int *temp = *(src1->bits)+i | *(src2->bits)+i;
      //(dest->bits)+i = *(src1->bits)+i | *(src2->bits)+i;

//printf("dest->bits[i] is %ld\n ", dest->bits[i]);
   }*/

   
   for(int i=0; i<src1->size_in_words; i++) {
      //printf("src1->bits[i] is %ld\n ", src1->bits[i]);
      if(bitset_lookup(dest,src1->bits[i])==0) bitset_add(dest, src1->bits[i]);
   }
   for(int j=0; j<src2->size_in_words; j++) {
      if(bitset_lookup(dest,src2->bits[j])==0) bitset_add(dest, src2->bits[j]);
     // bitset_add(dest,src2->bits[j]);
   }
   for(int i=0;i<bitset_cardinality(dest);i++){
     //printf("dest->bits[i] is %ld\n ", dest->bits[i]);
   }

   for(int i=0; i<src1->size_in_words; i++) {
      for(int j=0; j<src2->size_in_words; j++) {
         if(src1->bits[i] == src2->bits[j]) {
           //printf("src1->bits[i] is %ld\n ", src1->bits[i]);
           //printf("src2->bits[j] is %ld\n ", src2->bits[j]);
           bitset_remove(dest,src2->bits[j]);
         }
         /*else{
           printf("\n through else\n");
           printf("src1->bits[i] is %ld\n ", src1->bits[i]);
           printf("src2->bits[j] is %ld\n ", src2->bits[j]);
         }*/
      }
   } 
   
   for(int i=0; i<src2->size_in_words; i++) {
      for(int j=0; j<src1->size_in_words; j++) {
         if(src2->bits[i] == src1->bits[j]) {
           //printf("src1->bits[i] is %ld\n ", src1->bits[i]);
           //printf("src2->bits[j] is %ld\n ", src2->bits[j]);
           bitset_remove(dest,src1->bits[j]);
         }
         /*else{
           printf("\n through else\n");
           printf("src1->bits[i] is %ld\n ", src1->bits[i]);
           printf("src2->bits[j] is %ld\n ", src2->bits[j]);
         }*/
      }
   } 
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,
		      struct bitset * src2) {
/*for(int i=0; i<src1->size_in_words; i++) {
      dest->bits[i] = src1->bits[i] & src2->bits[i];
   }*/

  for(int i=0; i<src1->size_in_words; i++) {
      //printf("src1->bits[i] is %ld\n ", src1->bits[i]);
      if(bitset_lookup(dest,src1->bits[i])==0) bitset_add(dest, src1->bits[i]);
   }

  struct bitset * difference = bitset_new(256);
  for(int i=0;i<src1->size_in_words;i++){
    if(bitset_lookup(src2,src1->bits[i])==0) bitset_add(difference, src1->bits[i]);
  }
  
  for(int i=0;i<difference->size_in_words;i++){
    //printf("difference->bits[i]) is %d\n",difference->bits[i]);
  }

  for(int i=0;i<difference->size_in_words;i++){
    if(bitset_lookup(dest,difference->bits[i])==1){
      //printf("difference->bits[i]) is %d\n",difference->bits[i]);
      bitset_remove(dest,difference->bits[i]);
    }
  }
  

}

