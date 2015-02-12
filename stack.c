#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void StackNew(Stack *s, int elemSize){
  s->length = 0;
  s->allocLength = 4;
  s->elemSize = elemSize;
  s->elements = malloc(s->elemSize*s->allocLength);
  assert(s->elements != NULL && "Error on StackNew, no more memory");
}

void StackNewWithSize(Stack *s, int elemSize, int startingSpace){
  s->length = 0;
  s->allocLength = startingSpace;
  s->elemSize = elemSize;
  s->elements = malloc(s->elemSize*s->allocLength);
  assert(s->elements != NULL && "Error on StackNew, no more memory");
}

void StackPush (Stack *s, void *elemAddr){
  if (s->length == s->allocLength){
    s->allocLength =s->allocLength*2;
    s->elements = realloc (s->elements, s->allocLength*s->elemSize);
    assert(s->elements != NULL && "Error on StackPush, no more memory");
  }
  else{
    memcpy((char*)s->elements+(s->length*s->elemSize), &elemAddr, s->elemSize);
    s->length++;
  }
}
void StackPop(Stack *s, void *elemAddr){
  assert(s->length>0 && "No more elements on the stack");
  s->length -=1;
  memcpy(elemAddr, (char*)s->elements+(s->length*s->elemSize), s->elemSize);
}

void StackPeek(Stack *s, void *elemAddr){
  assert(s->length>0 && "No more elements on the stack");
  memcpy(elemAddr, (char*)s->elements+((s->length-1)*s->elemSize), s->elemSize);
}
void StackDispose(Stack *s){
  free(s->elements);
}
