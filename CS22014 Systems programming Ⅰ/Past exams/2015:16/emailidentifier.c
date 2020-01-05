//
//  emailidentifier.c
//  
//
//  Created by Kazuhiro Tobita on 11/12/2019.
//

#include <stdio.h>

struct list{
    char * character;
    int size;
    int point;
};

struct string_list * string_list_new(int max_size){
    struct string_list * tmp;
    tmp = malloc(sizeof(struct string_list));
    //tmp->size = max_size;
    tmp->point = 0;
    tmp = malloc(sizeof(char) * max_size); //max_sizeないけど
};

int isalphabet(char c) {
}

int isdigit(char c){
    switch(c){
        case '0':
        case '1':
        case '2':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        return 1;
        break;
        default:
        break;
    } return 0;
}

void string_store_push(struct string_list * this, char ){
    string myemail;
    this->point += 1;
    this->character[this->top];
}

int isValidEmailAddress(char email_address[], char * terminators[], int nterms){
    for(int i=0; i< ; i++){
        while(this->next != '@'){
            for(int j=0; j<this->size; j++){
                if(email_address[i] == this->character[j]) return -1;
            }
        }
    }
    
    for(int )
}
