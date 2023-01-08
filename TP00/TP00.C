#include <stdio.h>
#include<stdlib.h>
#include "TP00.h"

// creating an empty stackList
stackList stack_empty(){
    stackList S=NULL;
    return S;
}
// Printing the stackList
void stackPrint(stackList S){
    stackList temp=S;
    while(temp!=NULL){
        printf("%d  ",temp->element);
        temp=temp->next;
    }
    return ;
}

// pushing an element into the stackList
void push(stackList * S , int x){
    node * N=malloc(sizeof(node));
    N->element=x;
    N->next=NULL;
    if(*S==NULL){
        *S=N;
        return ;
    }
    node * temp=*S;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=N;
    return;
}

// popping an element out of the stackList
void pop(stackList * S){
    if(S==NULL){
        return;
    }
    stackList temp=*S;
    stackList temp2=*S;
    while(temp2->next!=NULL){
        temp=temp->next;
        temp2=temp->next;
    }
    temp->next=NULL;
    free(temp2);
    return;
}

// getting the length of the stackList
int lengthList(stackList L){
    stackList temp=L;
    int l=0;
    while(temp!=NULL){
        l+=1;
        temp=temp->next;
    }
    return l;
}

// deleting the 1st element of the stackList
void deleteFirst(stackList* S){
   if(*S==NULL){
       return;
   }
   stackList temp=*S;
   *S=(*S)->next;
   free(temp);
   return;
}

// creating a copy of teh stackList
stackList copy(stackList S){
    stackList temp=S;
    stackList S_copy=stack_empty();
    while(temp!=NULL){
        int x=temp->element;
        push(&S_copy,x);
        temp=temp->next;
    }
    return S_copy;
}

// slicing the linked list from index i to j (0,length-1)
stackList slice(stackList S,int i,int j){
    stackList S_ij=copy(S);
    stackList temp=S_ij;
    stackList temp2=S_ij;
    for(int k=0;k<i;k++ ){
        temp= temp-> next;
        free(temp2);
        temp2=temp;
    }
    S_ij=temp;
    stackList tempo=S_ij;
    stackList tempo2=tempo;
    for(int l=0; l<lengthList(S_ij)-i;l++){
        tempo2=tempo;
        tempo=tempo->next;
        if(l==j-i){
            tempo2->next=NULL;
        }
        if(l>j-i){
            free(tempo);
    }
    
}
return S_ij ;
}

// checking if an int x is in the stackList L
int check_is_in(int x, stackList L){
    stackList temp=L;
    while(temp!=NULL){
        if(temp->element==x){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

// EX3: removing duplicates from the stackList
stackList removeDuplicates(stackList L){
    stackList L2=stack_empty();
    stackList temp=L;
    while(temp!=NULL){
        int x=temp->element;
        if(!check_is_in(x,L2)){
            push(&L2,x);
        }
        temp=temp->next;
        
    }
    return L2;
}
int main (){
    stackList S=stack_empty();
    push(&S,1);
    push(&S,3);
    push(&S,1);
    push(&S,1);
    push(&S,0);
    push(&S,3);
    stackPrint(S);
    printf("\n");
    // pop(&S);
    stackList S2=removeDuplicates(S);
    stackPrint(S2);
    
    
}
