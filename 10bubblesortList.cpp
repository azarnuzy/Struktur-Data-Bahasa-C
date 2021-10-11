#include <iostream>
using namespace std;

class node {
    int data;
    node* next;
    node(int d):data(d),next(NULL) {

    }
};

node* createLL() {
    node* head = NULL;
    int d;
    cin >> d;
    while(d!=-1) {
        node* n = new node(d);
        n->next = head;
        head = n;
        cin >> d;
    }

    return head;
};

int length(node* head) {
    int count = 0;
    while(head!= NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void BubbleSort(node* head) {
    int n=length(head);
    for(int i=0; i<n-1; i++) {
        node* prev = NULL;
        node* current = head;
        node* n;
        while(current != NULL && current -> next != NULL) {
            if(current->data > current->next->data) {
                if(prev == NULL) {
                    n = current -> next;
                    current-> next = n -> next;
                    n-> next = current;
                    head = prev = n;
                }
            }
        }
    }
}

void print(node* head) {
    while(head!=NULL) {
        cout << head->data<< "-->";
        head = head->next;
    }
    cout <<endl;
}

int main() {

    return 0;
}