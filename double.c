#include <stdc-predef.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined(__STDC_IEC_559__)
#define __STDC_IEC_559__ 0
#endif

#if !defined(__STDC_IEC_60559_BFP__)
#define __STDC_IEC_60559_BFP__ 0L
#endif

#if !defined(__STDC_IEC_60559_DFP__)
#define __STDC_IEC_60559_DFP__ 0L
#endif

int main(void) {
  printf("Binary support: %ld\n", __STDC_IEC_60559_BFP__);
  printf("Double support: %ld\n", __STDC_IEC_60559_DFP__);
  printf("Legacy double support: %d\n", __STDC_IEC_559__);

  return EXIT_SUCCESS;
}
