#include <stdio.h>
#include <stdlib.h>
#include "history.h"

//Simply initializes the reference to the Linked List
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

  //checks to see if there are currently any nodes in the list
  //if not then the newNode is made to be the root node
  if (list->root == NULL) {
    newNode->id = 1;
    list->root = newNode;
  }
  //else: the linked list is traversed to the end and
  //the new node is added to the end of the list
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

//uses the inputted id number
//if the end of the list is reached the user is notified
//that the id does not exist
//else the string at that id is returned
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

//prints all the string saved into the linked list
void print_history(List *list)
{
  Item *currNode = list->root;

  while (currNode != NULL){
    printf("%i: %s",currNode->id, currNode->str);
    currNode = currNode->next;
  }
}

//frees each node and reference to linked list
void free_history(List *list) {
  Item *currNode = list->root;
  while (currNode != NULL){
    Item *tempNode = currNode->next;
    free(currNode);
    currNode = tempNode;
  }
  free(list);
}
