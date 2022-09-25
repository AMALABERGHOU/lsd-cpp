#include <stdio.h>
#include<stdlib.h>
#include"tp1.h"
int msbSet(int N){// since we use the 8 bit representation N must be <=127 to keep the 8th bit for the sign of the num
    int msb;

    msb = 1 << (totalBits- 1);

    if(N & msb){
        return 1;// msb is set
    }
    else{
        return 0;
    }
}
void printBits(unsigned n)
{
    // we got 32bits
    unsigned i;
    for (i = 1 << totalBits-1; i > 0; i = i >> 1){
        if(n&i){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    return ;
}
void print_nth_bit(int num, int i){
    int a=1<<totalBits-i;
    // printBits(num&a);
    if(num&a){
        printf("1");
    }
    else{
        printf("0");
    }
    return ;
    
}

int main(){
    int N;
    printf("enter a random integer: ");
    scanf("%d",&N);
    printf("Most Significant Bit is: %d",msbSet(N));
    printf("\n");
    printBits(abs(N)); // since printBits() takes an unsigned int we use the absolute value of N
    printf("\n");
    int i;
    printf("Give a number from 1 to 8:  ");
    scanf("%d",&i);
    print_nth_bit(abs(N),i);
    return 0;
}
