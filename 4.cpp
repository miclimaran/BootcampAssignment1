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
void duplicates(struct Node* head) 
{ 
    struct Node* now = head; 
  
    struct Node* next2;  
    
    if (now == NULL){
        return;  
    }  
    while (now->next != NULL)  
    { 
       if (now->value == now->next->value)  
       {       
           next2 = now->next->next; 
           free(now->next); 
           now->next = next2;   
       } 
       else 
       { 
          now = now->next;  
       } 
    } 
} 

int main(){
    struct Node* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(3);
    head->next->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next->next = createNode(4);
    printList(head);
    printf("\n");
    duplicates(head);
    printList(head);

    
}