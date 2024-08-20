#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/// Checks to see if the value pointed at by [pointer] is the same as [value].
/// An example of using a common strategy for dereferencing a null pointer.
/// The logical AND short-circuits if the pointer is null.
bool is_value(int *pointer, int value) { return pointer && *pointer == value; }

/// Examples of checks for null pointers using unary ! operator
void unary_null_pointer_checks(void) {
  // Note that it is really bad to do something with an uninitialized pointer
  int *pointer;
  if (!pointer) {
    puts("pointer is null: uninitialized");
  } else {
    printf("Pointer value: %p\n", (void *)pointer);
  }

  pointer = NULL;
  if (!pointer) {
    puts("pointer is null: NULL");
  }

  int thang = 7;
  pointer = &thang;
  if (!pointer) {
    puts("This really shouldn't be a null pointer");
  } else {
    printf("Pointer value: %p\n", (void *)pointer);
  }
}

int main(void) {

  unary_null_pointer_checks();

  int *pointer = NULL;
  if (!is_value(pointer, 5)) {
    puts("Didn't dereference a null pointer. Whew!");
  }

  int value = 5;
  pointer = &value;
  if (is_value(pointer, 5)) {
    puts("This pointer is definitely pointing at the right value");
  }

  return EXIT_SUCCESS;
}
