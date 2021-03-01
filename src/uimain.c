#include <stdio.h>
#include "tokenizer.h"
#define MAX 50

int main()
{
  
  puts("Enter a Word");
  printf("%s", "$ ");
  char c[MAX];
  fgets(c, MAX, stdin);

  char **tokens = tokenize(c);
  //print_tokens(tokens);
  return 0;

}
