#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int key;
    struct node *next;
};

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
    int len = 0;
    current=head;
    while(current->next!=NULL) {
        current=current->next;
        len++;
    }
    current=head;
    return len;
}

struct node* find(int key) {
    if (head==NULL)
        return NULL;

    current=head;
    while(current->next!=NULL) {
        if(current->key==key) {
            return current;
        }
    }
    printf("Node with key [%d] not found", key);
    return NULL;
}

struct node* delete(int key) {
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
    printf("Node with key [%d] not found", key);
    return NULL;
}

void sort() {

}

void reverse() {

}

int main() {

}

