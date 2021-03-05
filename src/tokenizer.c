#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//added \n since fgets adds a new line to the end of string
int space_char (char c)
{
  if(c==' ' || c == '\t' || c=='\n') return 1;
  return 0;
}

int non_space_char(char c)
{
  if(space_char(c) || c == '\0') return 0;
  return 1;
}

char *word_start(char *str)
{
  while (*str != '\0') {
    char curr_char = str[0];
    if(space_char(curr_char) && non_space_char(str[1])) {
      *str++;
      break;
    }
    *str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word)) word++;
  return word;
}

int count_words(char *str)
{
  int count = 0;
  while(*str != '\0') {
    str = word_start(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  // NOTE: this implementation uses fgets, 1 is subtracted from the len
  // in uimain.c since a \n char is added to the string
  char *ptr=(char*)malloc((len+1)*sizeof(char));
  if (ptr == NULL) printf("Memory not allocated.\n");

  for (int i = 0; i < len; i++) {
    *(ptr+i) = *(inStr+i);
  }
  *(ptr+len) = '\0';
  return ptr;
}

char **tokenize(char *s)
{
  int numWords = count_words(s);
  char **tokens=(char**)malloc((numWords+1)*sizeof(char*));
  if (tokens == NULL) printf("Memory not allocated.\n");

  if (space_char(*s)) s = word_start(s);
  for(int i = 0; i < numWords; i++) {
    char *wordHead = s;
    char *wordTail = word_terminator(wordHead);
    short wordLen = wordTail-wordHead;
    char *wordToken = copy_str(wordHead, wordLen);
    *(tokens+i) = wordToken;
    s=word_start(s);
    }
  char *wordTerminator = copy_str('\0', 0);
  *(tokens+numWords) = wordTerminator;
  return tokens;
}


void print_tokens(char **s)
{
  int count = 0;
  while (**s != '\0') {
    char *currWord = *s;
    printf("tokens[%i] = \"%s\"\n", count,currWord);
    s++;
    count++;
  }
}

void free_tokens(char **s)
{
  char **head = s;
  while (**s != '\0') {
    free(*s);
    s++;
  }
  free(head);
}

