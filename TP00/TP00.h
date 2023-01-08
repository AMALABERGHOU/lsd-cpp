#ifndef TP00_H
# define TP00_H

struct node {
    int element;
    struct node * next;
    // int * prev;
};
typedef struct node node;
typedef node * stackList;

//fucntions prototypes:
stackList stack_empty();
void stackPrint(stackList S);
void push(stackList * S , int x);
void pop(stackList * S);
int lengthList(stackList L);
void deleteFirst(stackList* S);
stackList copy(stackList S);
stackList slice(stackList S,int i,int j);
int check_is_in(int x, stackList L);
stackList removeDuplicates(stackList L);

#endif
