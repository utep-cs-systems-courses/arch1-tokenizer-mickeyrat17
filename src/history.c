#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List* root = (List*)malloc(sizeof(List));
  return root;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *newNode = (Item*)malloc(sizeof(Item));
  newNode->str = str;
  newNode->next = NULL;
  
  if (list->root == NULL) {
    newNode->id = 1;
    list->root = newNode;
  }
  else{
    Item *currNode = list->root;
    int count = 2;
    while (currNode->next != NULL){
      currNode = currNode->next;
      count++;
    }
    newNode->id = count;
    currNode->next = newNode;
  }
}

char *get_history(List *list, int id) {
  Item *currNode = list->root;
  while (currNode!=NULL){
    if (currNode->id == id){
      return currNode->str;
    }
    currNode = currNode->next;
  }
  return "ID doesn't exist";
}

void print_history(List *list)
{
  Item *currNode = list->root;

  while (currNode != NULL){
    printf("%i: %s",currNode->id, currNode->str);
    currNode = currNode->next;
  }
}
  
void free_history(List *list) {
  Item *currNode = list->root;
  while (currNode != NULL){
    Item *tempNode = currNode->next;
    free(currNode);
    currNode = tempNode;
  }
  free(list);
}
