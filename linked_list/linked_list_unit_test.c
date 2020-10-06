#include "linked_list.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void clearTest() {
    clear();
    assert(head == NULL);
    assert(current == NULL);

    head = (struct node *) malloc(sizeof(struct node));
    head->key = 3;
    assert(head != NULL);
    clear();
    assert(head == NULL);

    current = (struct node *) malloc(sizeof(struct node));
    current->key = 3;
    assert(current != NULL);
    clear();
    assert(current == NULL);
    printf("clearTest is passed\n");
}

void lengthTest() {
    clear();

    assert(length() == 0);

    head = (struct node *) malloc(sizeof(struct node));
    head->key = 10;
    assert(length() == 1);

    head->next = (struct node *) malloc(sizeof(struct node));
    head->next->key = 12;
    assert(length() == 2);

    printf("lengthTest is passed\n");
}

void addFirstTest() {
    clear();

    addFirst(10);
    assert(length() == 1);
    assert(head != NULL);
    assert(head->key == 10);
    assert(head->next == NULL);

    addFirst(-10);
    assert(length() == 2);
    assert(head->key == -10);

    addFirst(0);
    assert(length() == 3);
    assert(head->key == 0);
    printf("addFirstTest is passed\n");
}

void removeFirstTest() {
    clear();
    addFirst(1);

    struct node* tmp = removeFirst();
    assert(length() == 0);
    assert(tmp->key == 1);
    assert(head == NULL);

    addFirst(2);
    addFirst(10);
    //HEAD is 10

    tmp = removeFirst();
    assert(length() == 1);
    assert(tmp->key == 10);
    assert(head->key == 2);
    printf("removeFirstTest is passed\n");
}

void isEmptyTest() {
    clear();
    assert(isEmpty());

    clear();
    addFirst(10);
    assert(!isEmpty());

    clear();
    addFirst(1);
    addFirst(2);
    addFirst(3);
    removeFirst();
    removeFirst();
    removeFirst();
    assert(isEmpty());

    clear();
    addFirst(1);
    addFirst(2);
    addFirst(3);
    removeFirst();
    removeFirst();
    assert(!isEmpty());

    printf("isEmptyTest is passed\n");
}

void findTest() {
    clear();

    assert(find(10) == NULL); 

    addFirst(10);
    addFirst(1);
    addFirst(2);

    struct node* tmp = find(1);
    assert(tmp != NULL);
    assert(tmp->key == 1);

    tmp = find(12);
    assert(tmp == NULL);

    printf("findTest is passed\n");
}

void swapTest() {
    clear();
    addFirst(10);
    addFirst(12);
    swap(find(10), find(12));
    assert(head->key==10);
    assert(head->next->key=12);
    printf("swapTest is passed\n");
}

void reverseTest() {
    clear();

    reverse();
    assert(head == NULL);

    addFirst(1);
    reverse();
    assert(head->key == 1);

    clear();
    addFirst(1);
    addFirst(2);
    addFirst(3);
    addFirst(4);
    reverse();
    assert(head->key == 1);
    assert(head->next->key == 2);
    assert(head->next->next->key == 3);
    assert(head->next->next->next->key == 4);
    printf("reverseTest is passed\n");
}

int main() {
    clearTest();
    lengthTest();
    addFirstTest();
    removeFirstTest();
    isEmptyTest();
    findTest();
    swapTest();
    reverseTest();
}
