#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitset.h"
#include <stdbool.h>


// create a new, empty bit vector set with a universe of 'size' items
struct bitset * bitset_new(int size) {
  struct bitset * tmp;
  tmp = malloc(sizeof(struct bitset));
  tmp->size_in_words = 0;
  tmp->universe_size = size;
  tmp->bits = malloc(sizeof (int) * size);
  return tmp;
};

// get the size of the universe of items that could be stored in the set
int bitset_size(struct bitset * this) {
  return this->universe_size;
}

// get the number of items that are stored in the set
int bitset_cardinality(struct bitset * this){
  return this->size_in_words;
}

// check to see if an item is in the set
int bitset_lookup(struct bitset * this, int item) {
    if(item<0 || item>=this->universe_size){
        return -1;
    }
    else {
        for(int i=0; i<this->size_in_words; i++) {
           if(this->bits[i] == item) return 1;
        }
    }
    return 0;
}

// add an item, with number 'item' to the set
// has no effect if the item is already in the set
void bitset_add(struct bitset * this, int item) {
  * (this->bits + this->size_in_words) = item;
  this->size_in_words++;
}
  
// remove an item with number 'item' from the set
void bitset_remove(struct bitset * this, int item) {
  for(int i=0; i<this->size_in_words; i++) {
     if(this->bits[i]==item) {
         for(int j=i; j<size_in_words-i ; j++) {
            this->bits[j] = this->bits[j+1];
         } this->size_in_words--;
     }
  }
}
  
// place the union of src1 and src2 into dest;
// all of src1, src2, and dest must have the same size universe
void bitset_union(struct bitset * dest, struct bitset * src1,
		  struct bitset * src2) {
   for(int i=0; i<src1->size_in_words; i++) {
      if(bitset_lookup(dest, src1->bits[i]) == 0) bitset_add(dest, src1->bits[i]);
      if(bitset_lookup(dest, src2->bits[i]) == 0) bitset_add(dest, src2->bits[i]);
   }
   for(int i=0; i<src1->size_in_words; i++) {
      for(int j=i+1; k<src2->size_in_words-i; j++) {
         if(src1->bits[i] == src2->bits[j]) {
            bitset_remove(dest,src2->bits[j]);
         }
      }
   }
   for(int i=0; i<src1->size_in_words; i++) {
     for(int j=i+1; j<src1->size_in_words-i; j++) {
        if(src1->bits[i] == src1->bits[j]) {
          bitset_remove(dest,src1->bits[j]);
        }
     }
  }
}

// place the intersection of src1 and src2 into dest
// all of src1, src2, and dest must have the same size universe
void bitset_intersect(struct bitset * dest, struct bitset * src1,
		      struct bitset * src2) {
   for(int i=0; i<src1->size_in_words; i++) {
      if(bitset_lookup(dest,src1->bits[i])==0) bitset_add(dest, src1->bits[i]);
   }
   struct bitset * difference = bitset_new(256);
   for(int i=0;i<src1->size_in_words;i++) {
      if(bitset_lookup(src2,src1->bits[i])==0) bitset_add(difference, src1->bits[i]);
   }
}





