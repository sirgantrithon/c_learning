#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  bool thangs = true;
  _Bool stuff = 1;

  if (thangs && stuff) {
    puts("We've got thangs and stuff");
  }

  return EXIT_SUCCESS;
}
