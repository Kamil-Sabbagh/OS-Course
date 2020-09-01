#include <stdio.h>
struct Node { 
    int data; 
    struct Node* next; 
};
struct Node* head = NULL;
void print_list() {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node = head ;
  while (node != NULL) 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
  printf("\n") ; 
}
//this will give a new node on the fron of the list givin 
//a referecnce to the head of the list and an int value
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    new_node->data  = new_data; 
  
    new_node->next = (*head_ref); 
  
    (*head_ref)    = new_node; 
} 
void deleteNode(struct Node **head_ref, int key) 
{ 
    struct Node* temp = *head_ref, *prev; 
  
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   
        free(temp);              
        return; 
    } 
  
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) return; 
  
    prev->next = temp->next; 
  
    free(temp); 
} 
int main(void) {
  
  head = (struct Node*)malloc(sizeof(struct Node)); 
  struct Node* second = (struct Node*)malloc(sizeof(struct Node)); 
  struct Node* third = (struct Node*)malloc(sizeof(struct Node)); 
  head->data = 5;
  head -> next = second ; 
  second -> next = third ; 
  second -> data = 8 ; 
  third -> data = 7 ;
  print_list() ; 
  push(&head, 3);
  push(&head, 4);
  push(&head, 99);
  print_list() ;
  deleteNode(&head, 7); 
  deleteNode(&head, 8); 
  deleteNode(&head, 3); 
  print_list() ;
  return 0;
}
