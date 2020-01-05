//
//  deque.c
//  
//
//  Created by Kazuhiro Tobita on 05/12/2019.
//

#include "deque.h"

struct node_struct {
    int value;
    struct * node = prev;
    struct * node = next;
};

struct deque_struct {
    struct * head;
    struct * tail;
};

struct deque_type * deque_new() {
    struct deque_type * d;
    d = malloc(sizeof(struct deque));
    d->head = NULL;
    d->tail = NULL;
    return d;
}

void push_front_deque (struct deque_type * this, int value) {
    struct node_struct * n;
    n = malloc(sizeof(struct node_struct));
    n->value = value;
    n->prev = this->head;
    n->next = NULL;
    
    if(this->tail == NULL) { //if deque is empty
        this->head = this->tail = n;
    }
    else { // Inserts node at the front end
        this->head->prev = n;
        this->head = n;
    }
}

int pop_front_deque(struct deque_type * d) {
    int variance = d->head->value;
    struct node_struct * n = d->head;
    
    if(d->head == d->tail) d->head = d->tail = NULL;
    else d->head = n->next;
    return variance;
}

void push_back_deque(struct deque*this, int value) {
    struct node_struct * n;
    n = malloc(sizeof(struct node_struct));
    n->value = value;
    n->prev = this->tail;
    n->next = NULL;
    
    if(this->head == NULL){
        this->head = this->tail = n;
    }
    else{
        this->tail->next = n;
        thid->tail = n;
    }
};

int pop_back_deque(struct deque * this) {
    int variance = this->tail->value;
    struct node_struct * n = this->tail;
    
    if(this->tail == this->head) this->tail = thid->head = NULL;
    else this->tail = n->prev;
    return variance;
}

void free_deque(struct deque_struct * this){
    free(this);
}
