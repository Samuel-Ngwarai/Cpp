#include <iostream>
#include <stack>
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
    delete head;  // memory management
    return deleteNode(newHead, d);
  }

  Node* it = head;

  while (it->next != NULL && it != NULL) {
    if (it->next->data == d) {
      it->next = it->next->next;
      continue;
      delete it->next;
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
/*

1-2-4-2-54-6-7-4-2-1-34-5

*/
// Node* removeDuplicates(Node* head) {}

// Delete node using direct pointer to node
Node* deleteNode(Node* head, Node* node) {
  if (!node) return head;

  Node* it = node;

  while (it->next != NULL) {
    it->data = it->next->data;
    it = it->next;
  }

  delete it;

  return head;
}

// Delete node using direct pointer to node
void deleteNode(Node* node) {
  Node* it = node;

  while (it->next != NULL) {
    it->data = it->next->data;
    it = it->next;
  }

  delete it;
}

// TEST THESE

// 1 - 2 - 3 - 6 - 5 - 8 - 7
Node* findKthToLast(Node* head, int k) {
  if (!head) return NULL;

  Node *it, *it2 = head;

  for (int i = 0; i < k; i++) {
    if (!it) return NULL;
    it = it->next;
  }

  while (it != NULL) {
    it2 = it2->next;
    it = it->next;
  }

  return it2;
}

void partitionAroundN(Node* head, int n) {
  if (!head) return;

  Node *it, *it2 = head;

  while (it != NULL) {
    if (it->data < n) {
      swap(it, it2);
      it2 = it2->next;
    }
    it = it->next;
  }
}

int countNodes(Node* head) {
  if (!head) return 0;

  int count = 0;
  Node* it = head;

  while (it != NULL) {
    it = it->next;
    count++;
  }

  return count;
}

bool checkPalindrome(Node* head) {
  stack<Node*> nodeStack;

  int count = countNodes(head);
  int stackCount = count % 2 == 0 ? count / 2 : (count - 1) / 2;

  Node* it = head;
  int i = 0;

  while (it != NULL && i < stackCount) {
    nodeStack.push(it);
    it = it->next;
  }

  if (count % 2 != 0) {
    it = it->next;
    // additional check here
  }

  while (it != NULL) {
    Node* it2 = nodeStack.top();

    if (it2->data != it->data) return false;

    it = it->next;
  }
  return true;
}

}  // namespace LinkedListFunctions