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

  point->x = 0;
  point->y = 0;
  point->z = 10000;

  printf("Point:\n\t x: %5d\n\t y: %5d\n\t z: %5d\n", point->x, point->y, point->z);

  return EXIT_SUCCESS;
}
