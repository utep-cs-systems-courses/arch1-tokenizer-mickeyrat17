#include <stdio.h>
#include "tokenizer.h"
#define MAX 50

int main()
{
  
  puts("Enter a Word");
  printf("%s", "$ ");
  char buf[MAX];
  char *c = fgets(buf, MAX, stdin);
  printf("%s", c);
  return 0;

}