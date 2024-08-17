#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/// Specifies the node type stored in a [node]
enum node_type : char {
  integer_type,
  float_type,
  double_float_type,
  long_double_type
};

/// Struct that contains a union of a bunch of different types and a [node_type]
/// enum for specifying which of the union types is used
struct node {
  enum node_type type;
  union {
    int inode;
    float fnode;
    double dnode;
    long double ldnode;
  } u;
};

/// Struct that is similar to [node] but does not use a union thus allowing for
/// all fields to be set but may take up more memory
struct no_union_node {
  int inode;
  float fnode;
  double dnode;
  long double ldnode;
};

int main(void) {
  int a = 0b10111;
  int b = 17;

  struct node n;
  n.type = double_float_type;
  n.u.dnode = 0.1;

  struct no_union_node n2 = {0, 0.1, 0.1, 0.1};

  printf("sizeof(node) = %lu, sizeof(no_union_node) = %lu\n", sizeof(n),
         sizeof(n2));

  printf("sizeof(enum): %lu\n", sizeof(n.type));
  printf("sizeof(union): %lu\n", sizeof(n.u));

  printf("sizeof(int): %lu, sizeof(float): %lu, sizof(double): %lu, "
         "sizeof(long double): %lu\n",
         sizeof(n2.inode), sizeof(n2.fnode), sizeof(n2.dnode),
         sizeof(n2.ldnode));

  bool bub = true;
  _Bool bubba = 0;

  _BitInt(12) six_bit;

  printf("sizeof(_BitInt(12)): %lu\n", sizeof(six_bit));

  #if defined (__STD_IEC_559__)
    puts("IEC_559");
  #endif

  return EXIT_SUCCESS;
}
