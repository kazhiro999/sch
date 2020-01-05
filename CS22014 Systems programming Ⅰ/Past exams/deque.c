//
//  deque.c
//  
//
//  Created by Kazuhiro Tobita on 12/12/2019.
//

#include <stdio.h>



struct node_struct {
    int item;
    struct node_struct prev;
    struct node_struct next;
};

struct deque_struct {
    struct deque_struct head;
    struct deque_struct tail;
};

struct deque_type * deque_new(){
    struct deque_struct * d;
    d = malloc(sizof(struct deque_struct));
    d->head = d->tail = NULL;
    return d;
}

void deque_push_front(struct deque_struct * this, int value) {
    struct node_struct * n;
    n = malloc(sizeof(struct node_struct));
    n->item = value;
    n->prev = this->head;
    n->next = NULL;
    
    if(n->tail == NULL) {
        this->head = this->tail = n;
    } else {
        this->head->prev = n;
        this->head = n;
    }
}

int deque_pop_front(struct deque_struct * this){
    int variance = d->head->value;
    struct node_struct * n = this>head;
    if(this->head == this->tail) this->head = this->tail = NULL;
    else d->head = n->next;
    return variance;
}

void deque_push_back(struct ){
    
}






#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

struct bitset_struct{
    uint64_t * bits;
    int size_in_words; //
    int universe_size; //256
};

struct bitset_type * bitset_new(int size){
    struct bitset_struct * b;
    b = malloc(sizeof(struct bitset_struct));
    b->size_in_words = 0;
    b->universe_size = size;
    b->bits = malloc(sizeof(int) * size);
    return b;
};

int bitset_type * bitset_size(struct bitset_type * this) {
    return this->size_in_words;
}

int bitset_type * bitset_cardinality(struct bitset_type * this) {
    retutn this->universe_size;
}

void bitset_add (struct bitset * this, int item) {
    * (this->bits + this->size_in_words) = item;
}












#include <stdio.h>
#include <string.h>
#include <strlib.h>

struct bitset_struct{
    uint64_t * array;
    int size;
    int numberOfBytes;
};

struct bitset_type * bitset_new(int size){
    struct bitset_struct * b;
    b = malloc(sizeof(struct bitset_struct));
    b->size = size;
    b->numberOfArrays = size/8 + ((size%8==0)? 0: 1);
    b->array = malloc(sizeof(int) * b->numberOfSize);
    for(int i=0; i<numberOfBytes; i++){
        array[i] = 0;
    }
    return b;
}

struct bitset_type * bitset_new (int size) {
    struct bitset_struct * b;
    b->size = size;
    b->numberOfBytes = size/8 + ((size%8)? 0:1);
    
}

int bitset_add(struct bitset_type * this, int item) {
    unsigned char target = this->array[item/8];
    target = target | (128)
}




