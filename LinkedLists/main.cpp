#include <iostream>

using namespace std;

// This is the example code for two (three) operations that are essential to Linked Lists.
// I will not explain any of the code, rather you will look at it and **DRAW** it out and form your own understanding
// You are given permission to take *Inspiration* from and/or "copy" (without copy pasting) this code under two conditions:
	// *** You need to be able to explain what the code is doing either in a high-end level perspective or line-by-line. ***
		// If you can't, but you copy this code anyways, it will be considered academic dishonesty.
	// You will need to be able to implement it yourself by coding it *WITHOUT* looking at this code.
// Copying doesn’t help you, especially if you can’t understand and learn from it. You will only suffer in the long run by doing this.

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