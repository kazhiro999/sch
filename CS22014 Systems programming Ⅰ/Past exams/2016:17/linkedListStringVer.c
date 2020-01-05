 //
//  linkedListStringVer.c
//
//  Created by Kazuhiro Tobita on 11/12/2019.
//

#include <stdio.h>
#define string txt1 = "airpods"
#define string txt2 = "is a kind of eyerphones"

struct node_struct {
    char character;
    struct node * next;
    struct node * prev;
};

struct mystring_struct {
    struct node * head;
    struct node * tail;
};

struct node_type * node_new(char expr) {
    node_struct * n;
    n = malloc(sizeof(struct node_struct));
    n->character = expr;
    n->prev = n->prev = NULL;
    return n;
};

struct mystring_type * empty_string_new(){
    struct mystring_struct * s;
    s = malloc(sizeof(struct mystring_type));
    s->head = s->tail = NULL;
    return s;
};

struct mystring_type * put_string(char * str) { //create a new empty string
    struct mystring_struct * s;
    s = empty_string_new();
    
    for(int i=0; str->[i] != '\0'; i++){
        if(s->head == NULL) s->head = node_new(str[i]);
        
        /*
        else {
            s->tail = node_new(str[i]);
            s->tail->next = s->tail;
            s->tail = s->tail;
        }
        */
    }
    return s;
};

int compare_string(struct mystring_type * ms1, struct mystring_type * ms2) {
    int result = 0;
    len1 = stlren(ms1);
    len2 = strlen(ms2);
    if(len1 > len2) result 1;
    else if(len1 == len2) result 0;
    else result -1;
    return result;
}

int search_string(struct mystring_type * txt, struct mystring_type * terms) {
    int result = 1;
        for(int i=0; txt[i] != '\n'; i++) {
            struct node_struct * n1;
            n1 = node_new(txt[i]);
            for(int j=0; terms[j] != '\n'; j++) {
                struct node_struct n2;
                n2 = node_new(terms[j]);
                if(n1 != n2){
                    result = 0;
                    break;
                }
            }
        }
        return result;
    }
}
