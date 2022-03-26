#include <stdio.h>

int main() {

  char *word = "nice";
  int k = 0;

  for (char *p = word; *p && k >= 0; ++p) {
    printf("%c\n", *p);
  }

  return 0;
}