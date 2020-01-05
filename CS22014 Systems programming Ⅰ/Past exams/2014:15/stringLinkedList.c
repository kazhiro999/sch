//
//  stringLinkedList.c
//  
//
//  Created by Kazuhiro Tobita on 12/12/2019.
//

#include <stdio.h>

struct node_struct {
    char * words;
    struct node_struct * prev;
    struct node_struct * next;
};

struct set_struct {
    struct set_struct * head;
    struct set_struct * tail;
};

struct node_type * node_new() {
    struct node_type * n;
    n = malloc(sizeof(struct node_type));
    n->words = "";
    n->prev = n->next = NULL;
    return n;
};

struct set_type * new_set(){
    struct set_struct * s;
    s = malloc(sizeof(struct set_struct));
    s->head = s->tail = node_new();
    return s;
};

void add_set(struct set_type * this, char * mystr){
    struct node_struct * n;
    n = malloc(sizeof(struct node_struct));
    n->words = mystr;
    n->prev = thid->head;
    n->next = NULL;
    
    if(this->tail == NULL) {
        this->head = this->tail = n;
    } else {
        this->head->prev = n;
        this->head = n;
    }
}

void remove_set(struct set_type * this, char * mystr){
    struct node_struct * targetNode;
    targetNode = malloc(sizeof(struct node_struct));
    targetNode->words = mystr;
    targetNode->prev = targetNode->next = NULL;
    
    prevNode = targetnode->prev;
    nextNode = targetNode->next;
    
    if(this->head == this->tail){
        this->head = this->tail = NULL;
    }
    else if(targetNode == this->head){
        this->head = this->head->next;
        head->prev = NULL;
    }
    else if(targetNode == this->tail){
        this->tail = this->tail->prev;
        this->tail->next = NULL;
    }
    else {
        node_type * current = head;
        while(current != targetNode){
            current = current.next;
        }
        current->prev->next = current->next;
    }
}

int check_set(){}

string union_set(){}

string intersection_se(){}

struct free_mem(){}
