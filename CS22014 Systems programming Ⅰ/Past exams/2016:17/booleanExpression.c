//
//  booleanExpression.c
//  
//
//  Created by Kazuhiro Tobita on 11/12/2019.
//

#include "booleanExpression.h"

struct stack_struct {
    char * items;
    int size;
    int top;
};

struct stack_struct * stack_new (int max_size){
    struct stack_struct * s;
    s = malloc(sizeof(struct cahr_stack));
    s->size = max_size;
    s->top = 0;
    s->items = malloc(sizeof(char) * max_size);
    return s;
};

void push(struct stack_type * this, char character) {
    this->top += 1;
    this->items[this->top] = character;
}

char pop(struct stack_type * this) {
    char expr;
    this->items[this->top] = expr;
    this->top -= 1;
    return expr;
}

void apply_operator(struct stack_type * this, char expr) {
    char second = pop(this);
    char first = pop(this);
    char result;
    
    switch(expr){
        case '&&':
            if (first == 'F' && second == 'F') result = 'F';
            else result = 'T';
            break;
        case '||':
            if (first == 'T' && second == 'T') result = 'T';
            else result = 'F';
            break;
        case '!':
            if (result = 'T') return 'F';
            else if(result = 'F') return 'T';
            break;
        default:
        break;
    }
    push(this, result);
}

char char_stack_postfix(char ** args, int nargs) {
    struct stack_struct * stack = stack_new (int nargs);
    char result;
    
    for(int i=0; i<nargs; i++) {
        char(args[i][0]){
           case '&&':
           case '||':
           case '!':
           apply_operator(stack,args[i][0]);
           break;
           default:
           push(stack,args[i][0])
           break;
        }
    }
    result = pop(stack);
    return = result;
}




