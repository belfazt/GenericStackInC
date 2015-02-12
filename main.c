#include <stdio.h>
#include "stack.h"

int main(){
  Stack s;
  int b;
  StackNew(&s, sizeof(int));
  int i;
  for (i = 0; i < 6; i++){
    StackPush(&s, (int*)5);
  }
  StackPop(&s, &b);
  printf("Pop: %d\n", b);
  StackPeek(&s, &b);
  printf("Peek: %d\n", b);
  printf("%d, %d",s.length, s.allocLength);
}