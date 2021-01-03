#include <assert.h>

#include <iostream>

#include "algorithms.cpp"

using namespace std;

void testNodeFunctionality() {
  // test LinkedList creation
  LinkedListFunctions::Node* list =
      LinkedListFunctions::createLinkedList({1, 2, 3, 4, 5, 1, 6, 4, 2, 5});
  cout << "creating linkedList" << endl;
  LinkedListFunctions::printLinkedList(list);

  // test multi Node deletion
  list = LinkedListFunctions::deleteNode(list, 4);
  cout << "deleting 4 (random multi node)" << endl;
  LinkedListFunctions::printLinkedList(list);

  // test starting node deletion
  list = LinkedListFunctions::deleteNode(list, 1);
  cout << "deleting 1 (staring node)" << endl;

  LinkedListFunctions::printLinkedList(list);

  // test stopping node deletion
  list = LinkedListFunctions::deleteNode(list, 5);
  cout << "deleting 5 (last node)" << endl;

  LinkedListFunctions::printLinkedList(list);

  // test single node deletion
  list = LinkedListFunctions::deleteNode(list, 3);
  cout << "deleting 3 (single node)" << endl;

  LinkedListFunctions::printLinkedList(list);
}

int main() {
  cout << endl << endl;
  cout << "----- STARTING Linked list TESTS -----" << endl;
  testNodeFunctionality();
  cout << "----- FINISHED Arrays and Strings TESTS -----" << endl;
  return 0;
}