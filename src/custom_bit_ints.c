#include <stdio.h>
#include <stdlib.h>

int main(void) {

#if defined(__clang__)
  // A 65 bit integer (1 bit for sign and 64 for data). Takes up 8 bytes + 1 bit
  // but has an alignment of 16 bytes.
  _BitInt(65) thang = 2;
  printf("Size of _BitInt(65): %lu", sizeof(thang));
#else
  puts("This program isn't useful unless compiled with clang");
#endif
  return EXIT_SUCCESS;
}
