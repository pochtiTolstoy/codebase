#include <stdio.h>

typedef struct hmm {
  int a;
} Hmm;

int main(void) {
  Hmm hm = { 0 }; 
  Hmm* ptr = &hm;
  printf("%d\n", ptr->a);
  ++ptr->a;
  printf("%d\n", ptr->a);
  return 0;
}
