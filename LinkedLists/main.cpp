#include <iostream>

using namespace std;

struct node {
    int n;
    node* next;
    node(int n) : n(n), next(0) {}
};

int main() {
    node* head = 0;
    node* tail = 0;

    for (int i = 0; i < 10; i++) {
        if (!head) {
            head = new node(i);
            tail = head;
        }
        else {
            node* newNode = new node(i);
            tail->next = newNode;
            tail = newNode;
        }
    }

    node* currNode = head;
    while (currNode) {
        cout << currNode->n << " ";
        currNode = currNode->next;
    }
    cout << endl;

    if (head && head != tail) {
        currNode = head;
        while (currNode->next != tail) {
            currNode = currNode->next;
        }
        delete tail;
        currNode->next = 0;
        tail = currNode;
    }
    else if (head == tail) {
        delete head;
        head = 0;
        tail = 0;
    }

    currNode = head;
    while (currNode) {
        cout << currNode->n << " ";
        currNode = currNode->next;
    }
    cout << endl;
}