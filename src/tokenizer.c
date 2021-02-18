#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c==' ' || c == '\t') return 1;
  return 0;
}

int non_space_char(char c)
{
  if(space_char(c) || c == '\0') return 0;
  return 1;
}

char *word_start(char *str)
{
  while(*str != '\0')
  {
    char curr_char = str[0];
    if(space_char(curr_char) && non_space_char(str[1]))
    {
      *str++;
      break;
    }
    *str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while(*word != '\0') word++;
  return word;
}

int count_words(char *str)
{
  int count = 0;
  while(*str != '\0')
  {
    str = word_start(str);
    count++;
  }
  return count;
}
