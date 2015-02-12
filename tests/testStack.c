/*
 * File:   testStack.c
 * Author: vagrant
 *
 * Created on Feb 12, 2015, 1:47:34 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../stack.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
  return 0;
}

int clean_suite(void) {
  return 0;
}

void testStackNew() {
  Stack s;
  int elemSize = sizeof(int);
  StackNew(&s, elemSize);
  CU_ASSERT(1);
  
}

void testStackPop() {
  Stack s;
  int b;
  StackNew(&s, sizeof(int));
  StackPush(&s, (int*)5);
  StackPop(&s, &b);
  CU_ASSERT(s.length == 0);
  
}

void testStackPush() {
 Stack s;
  StackNew(&s, sizeof(int));
  int i;
  for (i = 0; i < 6; i++){
    StackPush(&s, (int*)5);
  }
  CU_ASSERT(s.length == 5 && s.allocLength == 8);
}

void testStackDispose() {
  Stack s;
  StackNew(&s, sizeof(int));
  StackDispose(&s);
  CU_ASSERT(1);
}

int main() {
  CU_pSuite pSuite = NULL;

  /* Initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* Add a suite to the registry */
  pSuite = CU_add_suite("testStack", init_suite, clean_suite);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Add the tests to the suite */
  if ((NULL == CU_add_test(pSuite, "testStackNew", testStackNew)) ||
          (NULL == CU_add_test(pSuite, "testStackPop", testStackPop)) ||
          (NULL == CU_add_test(pSuite, "testStackPush", testStackPush)) ||
          (NULL == CU_add_test(pSuite, "testStackDispose", testStackDispose))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
