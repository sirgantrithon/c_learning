#include <stdbool.h>
#include <stdc-predef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// A bunch of macros that test for floating point support
#if !defined(__STDC_IEC_559__)
#define __STDC_IEC_559__ 0
#endif

#if !defined(__STDC_IEC_60559_BFP__)
#define __STDC_IEC_60559_BFP__ 0L
#endif

#if !defined(__STDC_IEC_60559_DFP__)
#define __STDC_IEC_60559_DFP__ 0L
#endif

// A union that has a float and a struct that can be used to inspect the raw
// parts of the float
typedef union inspector {
  float value;
  struct raw {
    uint32_t significand : 23;
    uint8_t exponent : 8;
    bool sign : 1;
  } raw;
} inspector;

// Prints the float and it's raw parts
void print_inspector(inspector thang) {
  printf("Float: %f\n", thang.value);
  printf("Negative: %s\n", thang.raw.sign ? "true" : "false");
  printf("Exponent: %d\n", thang.raw.exponent);
  printf("Significand: %d\n\n", thang.raw.significand);
}

int main(void) {
  printf("Binary support: %ld\n", __STDC_IEC_60559_BFP__);
  printf("Double support: %ld\n", __STDC_IEC_60559_DFP__);
  printf("Legacy double support: %d\n\n", __STDC_IEC_559__);

  inspector thang;
  thang.value = -5;
  print_inspector(thang);

  // [thang2] is equal to -5 by setting the raw parts
  inspector thang2;
  thang2.raw.sign = 1;
  thang2.raw.exponent = 192;
  thang2.raw.significand = 2097152;
  print_inspector(thang2);

  return EXIT_SUCCESS;
}
