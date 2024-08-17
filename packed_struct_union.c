#include <stdio.h>
#include <stdlib.h>

/// Specifies the node type stored in a [node].
///
/// __attribute__((__packed__)) packs the enum to use only one byte instead of
/// four.
enum __attribute__((__packed__)) node_type {
  integer_type,
  float_type,
  double_float_type,
  long_double_type
};

/// Struct that contains a union of a bunch of different types and a [node_type]
/// enum for specifying which of the union types is used.
///
/// __attribute__((__packed__, __aligned__(4))) packs the struct and sets the
/// alignment to four bytes thus reducing the size in memory from 16 + 16 bytes
/// to 4 + 16 bytes. It is 4 + 16 because while the [node_type] enum is packed
/// to only use a single byte it has to align to 4 bytes. The union is 16 bytes
/// because that is the size of the largest member (long double). 
typedef struct __attribute__((__packed__, __aligned__(4))) node {
  enum node_type type;
  union {
    int inode;
    float fnode;
    double dnode;
    long double ldnode;
  } u;
} node;

/// Struct that is similar to [node] but does not use a union thus allowing for
/// all fields to be set but may take up more memory. Takes up 4 + 4 + 8 + 16
/// (32) bytes of memory.
typedef struct no_union_node {
  int inode;
  float fnode;
  double dnode;
  long double ldnode;
} no_union_node;

int main(void) {
  node n;
  n.type = double_float_type;
  n.u.dnode = 0.1;

  no_union_node n2 = {0, 0.1, 0.1, 0.1};

  printf("sizeof(node) = %lu, sizeof(no_union_node) = %lu\n", sizeof(struct node),
         sizeof(struct no_union_node));

  printf("sizeof(enum): %lu\n", sizeof(enum node_type));
  printf("sizeof(union): %lu\n", sizeof(n.u));

  printf("sizeof(int): %lu, sizeof(float): %lu, sizof(double): %lu, "
         "sizeof(long double): %lu\n",
         sizeof(n2.inode), sizeof(n2.fnode), sizeof(n2.dnode),
         sizeof(n2.ldnode));

  return EXIT_SUCCESS;
}
