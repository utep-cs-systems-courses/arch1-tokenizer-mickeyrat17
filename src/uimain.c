#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 50

int main()
{
  //initializes linked list
  List *inputHistory = init_history();
  
  
    while (1)
    {
      printf("Select which process you'd like to execute: \nTokenize = t\nView all history = h\nView a specific history id = !i#\nQuit = q\n > ");
      char inputChar[2];
      fgets(inputChar, 3, stdin);
      // Given the user answer, select which method to call
      switch (inputChar[0]) {
      case 't':
	//takes user input
	//tokenizes, prints text(in tokenized form, and frees tokens
	puts("You selected tokenize.");
	puts("Enter a Word");
	printf("%s", "$ ");
	char currInput[MAX];
	fgets(currInput, MAX, stdin);
	char **tokens = tokenize(currInput);
	print_tokens(tokens);
	free_tokens(tokens);
	puts("Tokens freed");
	//copies inputted string and saves it to history
	short len;
	for (len=0;currInput[len]!='\0';++len);
	char *wordCopy = copy_str(currInput, len);
	add_history(inputHistory, wordCopy);
	break;
      case 'h':
	//Displays all history
	puts("You selected to view ALL history:");
	print_history(inputHistory);
	break;
      case '!': ;
	//id is the character that follows the exclmation point
	//calculated by subtracting char by '0' character
	int id = inputChar[1]-'0';
	printf("You selected to view history at id %c\n", inputChar[1]);
	printf("%s\n", get_history(inputHistory, id));
	break;
      case 'q':
	//frees all memory when quitting
	puts("Freed history");
	free_history(inputHistory);
	goto done; 		/* terminate */
      case '\n':
	break;
      default:
	printf("Unrecognized option '%s', please try again!\n", inputChar);
      }
      printf("\n");
    }
    
 done:
    return 0;
}
