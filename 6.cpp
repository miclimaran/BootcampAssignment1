#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
  int value; 
  Node *next; 
} *head, *tail, *curr; 

struct Node *createNode(int value) {
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL; 
  return temp;
}

void pushHead(int value) {
  Node *temp = createNode(value);

  if(!head) { 
    head = tail = temp;
  } else { 
    temp->next = head; 
    head = temp; 
  }
}

void pushTail(int value) {
  Node *temp = createNode(value);

  if(!head) { 
    head = tail = temp;
  } else { 
    tail->next = temp; 
    tail = temp; 
  }
}
void popHead() {
  if(!head) {
    return; 
  } else if(head == tail) {
    head = tail = NULL; 
    free(head);
  } else {
    Node *temp = head->next; 
    head->next = NULL; 
    free(head); 
    head = temp; 
  }
}

void popTail() {
  if(!head) {
    return; 
  } else if(head == tail) {
    head = tail = NULL; 
    free(head);
  } else {
    curr = head; 
    while(curr) { 
      if(curr->next == tail) { 
        curr->next = NULL; 
        free(tail); 
        tail = curr; 
        break;
      }
      curr = curr->next;
    }
  }
}
void printList(struct Node* node){
    while (node != NULL) {
        printf("%d  ", node->value);
        node = node->next;
    }
}
void SortedInsert(struct Node** head, struct Node* newNode)
{
    struct Node temp1;
    struct Node* now = &temp1;
    temp1.next = *head;
 
    while (now->next != NULL && now->next->value < newNode->value)
        now = now->next;
 
    newNode->next = now->next;
    now->next = newNode;
    *head = temp1.next;
}
void InsertSort(struct Node** head)
{
    struct Node* result = NULL;  
    struct Node* now = *head; 
    struct Node* next;
    while (now != NULL){
        next = now->next;
 
        SortedInsert(&result, now);
        now = next;
    }
    *head = result;
}


int main(){
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(1);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(5);
    printList(head);
    printf("\n");
    InsertSort(&head);
    printList(head);
}