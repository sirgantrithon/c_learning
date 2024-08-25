#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
  int x, y, z;
} Point;

int main(void) {

  // Allocate the amount of memory needed for the struct
  Point *point = malloc(sizeof *point);

  // Failure to allocate is indicated by the pointer pointing at NULL
  if (point == NULL) {
    puts("Failed to allocate");
    return EXIT_FAILURE;
  }

  puts("We are good to go");
  return EXIT_SUCCESS;
}
