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
struct Node* mergeUtil(struct Node* h1, 
                       struct Node* h2) 
{ 
    if (!h1->next) { 
        h1->next = h2; 
        return h1; 
    } 
    struct Node *curr1 = h1, *next1 = h1->next; 
    struct Node *curr2 = h2, *next2 = h2->next; 
  
    while (next1 && curr2) { 
        if ((curr2->value) >= (curr1->value) && (curr2->value) <= (next1->value)) { 
            next2 = curr2->next; 
            curr1->next = curr2; 
            curr2->next = next1; 
  
            curr1 = curr2; 
            curr2 = next2; 
        } 
        else { 
            
            if (next1->next) { 
                next1 = next1->next; 
                curr1 = curr1->next; 
            } 
            else { 
                next1->next = curr2; 
                return h1; 
            } 
        } 
    } 
    return h1; 
} 
struct Node* merge(struct Node* h1, struct Node* h2) { 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
    if (h1->value < h2->value) 
        return mergeUtil(h1, h2); 
    else
        return mergeUtil(h2, h1); 
} 
void printList(struct Node* node){
    while (node != NULL) {
        printf("%d  ", node->value);
        node = node->next;
    }
}

int main(){
    struct Node* head = createNode(10);
    head->next = createNode(13);
    head->next->next = createNode(17);
    struct Node* tail = createNode(12);
    tail->next = createNode(14);
    tail->next->next = createNode(16);

    struct Node* Combined = merge(head,tail);
    printList(Combined);
    return 0;
}