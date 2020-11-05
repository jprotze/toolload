#include "foo.h"

__attribute__((constructor(102))) void inittool() {
  nprint("begin TOOL constructor\n");
  CALL(foo_register());
  nprint("end TOOL constructor\n");
}

int foo() {
  nprint("TOOL foo\n");
  CALL(pfoo());
}
