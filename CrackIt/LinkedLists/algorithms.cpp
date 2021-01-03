#include <iostream>
#include <vector>

using namespace std;

namespace LinkedListFunctions {

// Singly linked list
struct Node {
  Node* next;
  int data;

  Node() { next = NULL; }

  Node(int nData) {
    next = NULL;
    data = nData;
  }

  void appendToTail(int nData) {
    Node* it = this;
    while (it->next != NULL) {
      it = it->next;
    }

    Node* newNode = new Node(nData);
    it->next = newNode;
  }
};

// Doubly linked list
struct DNode {
  DNode* next;
  DNode* prev;
  int data;

  DNode() {
    next = NULL;
    prev = NULL;
  }

  DNode(int nData) {
    next = NULL;
    prev = NULL;
    data = nData;
  }

  void appendToTail(int nData) {
    DNode* it = this;
    while (it->next != NULL) {
      it = it->next;
    }

    DNode* newNode = new DNode(nData);
    newNode->prev = it;
    it->next = newNode;
  }
};

// Delete node based on value
Node* deleteNode(Node* head, int d) {
  if (!head) return NULL;

  if (head->data == d) {
    Node* newHead = head->next;
    // delete head;  // memory management
    return deleteNode(newHead, d);
  }

  Node* it = head;

  while (it->next != NULL && it != NULL) {
    if (it->next->data == d) {
      it->next = it->next->next;
      continue;
      // delete it -> next;
    }
    it = it->next;
  }

  return head;
}

// create linkedlist given vector
Node* createLinkedList(vector<int> data) {
  if (data.size() == 0) return NULL;

  Node* head = new Node(data[0]);

  for (int i = 1; i < data.size(); i++) {
    head->appendToTail(data[i]);
  }
  return head;
}

// print linked list
void printLinkedList(Node* head) {
  if (!head) return;

  Node* it = head;

  while (it != NULL) {
    cout << it->data << " -> ";
    it = it->next;
  }
  cout << endl;
}

// Node deleteNode(Node head, Node node) {}

}  // namespace LinkedListFunctions