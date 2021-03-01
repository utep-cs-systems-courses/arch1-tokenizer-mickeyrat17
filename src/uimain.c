#include <stdio.h>
#include "tokenizer.h"
#define MAX 50

int main()
{
  
  puts("Enter a Word");
  printf("%s", "$ ");
  char c[MAX];
  fgets(c, MAX, stdin);

  short len = word_terminator(c)-c;
  char *strCopy = copy_str(c, len);
  printf("Memory allocated: %i.  ", len);
  printf("%s\n", strCopy);
  return 0;

}
