/*
 * http://www.bien-programmer.fr/codage.php#bibliotheque
 * http://depinfo.mines.inpl-nancy.fr/Members/thomas.darcet/ascenseur/projetascenseur
 * http://www.c-cplusplus.com/c-program-using-arrays-to-implement-working-of-lift-in-multi-story-buildings
 * http://www.angelfire.com/trek/software/elevator.html
 */



#include <cstdlib>
#include<iostream>
#include <assert.h>
#include <list>

using namespace std;

struct node {
    int data;
    struct node *next;
};


struct node * buildOneTwoThree() {

    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    assert(head   = (struct node*) malloc(sizeof(struct node)));
    assert(second = (struct node*) malloc(sizeof(struct node)));
    assert(third  = (struct node*) malloc(sizeof(struct node)));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

int length(struct node* head) {
    int count = 0;
    struct node* current = head;
    if (head == NULL) {
        cout <<"Empty list ! "<<endl;
    }
    while(current != NULL) {
        count ++;
        current = current->next;
    }
    return count;
}

void pushAtHead(struct node *& head, int data) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

void pushAtEnd(struct node*& head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    struct node *current = NULL;
    current = head;
    /*special case for an insert in an empty list*/
    if (current == NULL) {
        head = newNode;
    }
    else {
        
        while (current->next != NULL){
        current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct node* head) {
    struct node * current = NULL;
    current = head;
    cout <<"\n- - - - - - List- - - - - - - - "<<endl;
    while (current != NULL){
        cout <<current->data<<" ";
        current = current->next;
    }
    cout <<"\n- - - - - - - - - - - - - - - - -"<<endl;
}

struct node * copyList(struct node * &head) {
    struct node* current = head;
    struct node* newList = NULL;
    struct node* tail = NULL;

    while (current != NULL) {
        if (newList == NULL) {
            newList = (struct node*)malloc (sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = (struct node*)malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
    return newList;
}

struct node* copyListRecursive(struct node* &head) {
    
    struct node* current = head;

    if (current == NULL) {
        return NULL;
    }
    else {
        struct node* newList = (struct node*)malloc(sizeof(struct node));
        newList->data = current->data;
        newList->next = copyListRecursive(current->next);
    return newList;
    }
}

int count(struct node*& head, int search) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        if (current->data == search) {
            count ++;
        }
    current = current->next;       
    }
    return count;
}

int getNTh(struct node* &head, int index) {
    struct node* current = head;
    int listSize = length(head);
    int i, count = 0;
    assert(index <= listSize && index > -1);

    while (current != NULL && (index != count)) {
        count ++;
        current = current->next;
    }
    return (current->data);
}

void deleteList(struct node* &head) {
    struct node *current = head;
    struct node* next;
    while (current != NULL) {
        next =  current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int pop(struct node* &head) {
    struct node* current = head;
    struct node* newHead = NULL;

    int data = current->data;

    newHead = current->next;
    free(current);
    head = newHead; 
    
    return (data);
}

void insertNTh(struct node* &head, int index, int data) {

    if(index == 0) {
        pushAtHead(head, data);
    }
    else {
        struct node *current = head;

        for(int i = 0; i< index - 1; i++) {
            assert(current->next != NULL);
            current = current->next;
        }
        assert(current != NULL);
        pushAtHead(current->next, data);
    }
}

void sortedInsert(struct node* &head, struct node* newNode) {
    struct node* current = head;
    while (current != NULL && current->data <= newNode->data ) {
        if (current->data <= newNode->data) {
            current = current->next;
            cout << "INSIDE loop Current is pointing to " << current->data << endl;
        }
    }
    cout << "Current is pointing to " << current->data << endl;
    pushAtHead(current->next, newNode->data);
}
/*===========================================================================*/
/*                          MAIN PROGRAM                                     */
/*===========================================================================*/

int main(int argc, char** argv) {

    struct node* head = buildOneTwoThree();
    cout <<"longueur de la liste: "<<length(head)<<endl;

    pushAtHead(head, 9);
    pushAtEnd(head, 71);
    printList(head);
    pushAtEnd(head, 71);


    struct node* myList = NULL;
//    myList = copyList(head);
//    printList(myList);
    myList = copyListRecursive(head);
    printList(myList);

    int search = 71;
    int nbOccurence = count(head, search);
    cout <<"Number of occurance of "<<search<<" = "<<nbOccurence<<endl;

    int index = 1;
    int nth = getNTh(head, index);
    cout <<"The data of "<<index<<"th node = "<<nth<<endl;
    cout <<"longueur de la liste: "<<length(head)<<endl;

    
    int first = pop(head);
    cout <<"Poping one element : "<<first<<endl;
    printList(head);
    cout <<"longueur de la liste: "<<length(head)<<endl;

    cout <<"Deleting the hole list "<<endl;
    deleteList(head);
    printList(head);

    insertNTh(head, 0, 13);
    insertNTh(head, 1, 42);
    insertNTh(head, 1, 5);
    printList(head);

    cout <<"This is a sorted list"<<endl;
    deleteList(head);
    for(int i = 0; i < 5; i++) {
        pushAtEnd(head, i * 2);
    }
    printList(head);
    cout <<"given an element, insert it in a sorted list"<<endl;
    int value = 3;
    struct node* newNode = (struct node*)malloc(sizeof (struct node));
    newNode->data = value;
    sortedInsert(head, newNode);
    printList(head);

    cout<<" ===== Quick using of lists using STL ====="<<endl;

    list<char> listObject;
    for (int i = 0; i < 10; i++) {
        listObject.push_back('A'+i);
    }
    cout <<"Size of listObject = "<<listObject.size()<<endl;

    list<char>::iterator ii;
    cout<<"Contents: ";

    while(!listObject.empty()) {
       ii = listObject.begin();
        cout<< *ii<<" ";
        listObject.pop_front();
    }
    
    return 0;
}

