#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int key;
    struct node *next;
};

void addFirst(int key);
struct node* removeFirst();
bool isEmpty();
int length();
struct node* find(int key);
struct node* deleteByKey(int key);
void swap(struct node* firstPrevious, struct node* secondPrevious);
void clear(); 
void reverse();

extern struct node* head;
extern struct node* current; 

#endif
