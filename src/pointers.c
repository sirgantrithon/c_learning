#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Behavior of checking for null pointers using the unary ! operator
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

  return EXIT_SUCCESS;
}
