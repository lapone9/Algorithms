#include "linked_list.h"

struct node* head = NULL;
struct node* current = NULL;

void addFirst(int key) {
    //O(1)
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->next = head;
    head = link;
}

struct node* removeFirst() {
    //O(1)
    struct node* tmpLink = head;
    head = head->next;
    return tmpLink;
}

bool isEmpty() {
    return head==NULL;
}

int length() {
    //O(n)
    if(head == NULL)
        return 0;
    current=head;
    int len = 1;
    while(current->next!=NULL) {
        current=current->next;
        len++;
    }
    return len;
}

struct node* find(int key) {
    if (head==NULL)
        return NULL;

    current=head;
    while(current!=NULL) {
        if(current->key==key) {
            return current;
        }
        current = current->next;
    }
    printf("Node with key [%d] not found\n", key);
    return NULL;
}

struct node* deleteByKey(int key) {
    struct node* previous=head;
    if (head==NULL)
        return NULL;
    current = head;
    while(current->next!=NULL) {
        if(current->key==key){
            previous->next = current->next;            
            return current;
        }
        previous = current;
    }
    printf("Node with key [%d] not found\n", key);
    return NULL;
}

void clear() {
    head = NULL;
    current = NULL;
}

void swap (struct node* first, struct node* second) {
    int tmp = first->key;
    first->key = second->key;
    second->key = tmp;
}

void sort() {
}

void reverse() {
    if (head==NULL || head->next==NULL)
       return;
    struct node* prev = NULL;
    struct node* next = NULL;
    current = head;
    while(current!=NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


