#include <stdio.h>
#include <stdlib.h>

/// This is a function that will be used inside another function
int some_func(int i) {
  puts("Inside some_func()");
  return i + 1;
}

/// This function takes a function pointer to a function that takes an int as a
/// parameter and returns an int in return
int outer_func(int (*inner_func)(int i)) {
  puts("Before inner function");
  int return_value = inner_func(8);
  puts("After inner_function");
  return return_value;
}

int main(void) {
  int return_value = outer_func(some_func);
  printf("return value: %d", return_value);

  return EXIT_SUCCESS;
}
