#include "foo.h"

int bar();

int nesting = 0;

int main() {
  nprint("main calling foo\n");
  CALL(foo());
  nprint("main calling foo returned\n");
  nprint("main calling bar\n");
  CALL(bar());
  nprint("main calling bar returned\n");
}
