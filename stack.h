#ifndef STACK_H
#define	STACK_H

typedef struct{
    void *elements;
    int elemSize;
    int length;
    int allocLength;
}Stack;


void StackNew(Stack *s, int elemSize);
void StackNewWithSize(Stack *s, int elemSize, int startingSpace);
void StackPush (Stack *s, void *elemAddr);
void StackPop(Stack *s, void *elemAddr);
void StackPeek(Stack *s, void *elemAddr);
void StackDispose(Stack *s);
#endif	/* STACK_H */

