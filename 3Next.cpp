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
void printMiddle(struct Node* head){ 
    int count = 0; 
    struct Node* mid = head; 
  
    while (head != NULL) { 
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 
  
    if (mid != NULL) 
        printf("The middle element is [%d]\n\n", mid->value); 
} 

int main(){

    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printMiddle(head);

}