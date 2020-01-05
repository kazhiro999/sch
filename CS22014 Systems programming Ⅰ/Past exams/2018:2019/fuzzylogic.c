//
//  fuzzylogic.c
//  
//
//  Created on 12/12/2019.
//

#include <stdio.h>

struct stack_struct{
    float * items;
    int size;
    int top;
};

struct stack_type * new_stack(int max_size){
    struct stack_stype * s;
    s = malloc(sizeof(struct stack_type));
    s->size = max_size;
    s->top = 0;
    s->items = malloc(sizeof(double) * max_size);
    return s;
};

void push(struct stack_type * this, float value){
    this->items[this->top] = value;
    this->top += 1;
}

float pop(struct stack_type * this){
    float result;
    result = this->items[this->top];
    this->top -= 1;
    return result;
}

void apply_opperator(struct stack_type * this, char expr){
    float result;
    float second = pop(this);
    float first = pop(this);
    
    switch(expr){
        case '&':
            if(first > second) return second;
            else return first;
        case '|':
            if(first > second) return first;
            else return second;
        case '!':
            result = 1 - result;
        break;
        default:
        break;
    } push(this, result);
}

float eval_postfix_fuzzy(char**terms, int nterms){
    float result;
    struct stack_type * s = new_stack(nterms);
    
    for(int i=0; i<nterms; i++) {
        if(strlen(terms[i])==1){
            switch(terms[i][0]){
                case '&':
                case '|':
                case '!':
                apply_opperator(s,terms[i][0]);
                break;
                default:
                push(s, atof(terms[i][0]));
                break;
            }
        } else {
            push(s, atof(terms[i][0]));
        }
    } result = pop(s);
    return = result;
}
