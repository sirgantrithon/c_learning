#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // A 65 bit integer (1 bit for sign and 64 for data). Takes up 8 bytes + 1 bit
  // but has an alignment of 16 bytes.
  _BitInt(65) thang = 2;
  printf("Size of _BitInt(65): %lu", sizeof(thang));
  return EXIT_SUCCESS;
}
