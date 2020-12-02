#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node *left;
  Node *right;
  int val;
  Node(int nval) {
    val = nval;
    left = NULL;
    right = NULL;
  }
  Node() {
    left = NULL;
    right = NULL
  }
}

void inOrderInsertion(Node* node, vector<Node*>& input, int & pos) {
    if (pos >= input.size()) {
        return;
    }

    node -> left = input[pos];
    pos++;

    if (pos == input.size()) return;
    node -> right = input[pos];

    if (node -> left) {
        inOrderInsertion(node -> left, input, pos);
    }
    if (node -> right) {
        inOrderInsertion(node -> right, input, pos);
    }
}

/**
 * Create a tree given values provided in a vector
 * 
 * 1 null 2 3 null 4
 * 
 **/
Node* inOrderInsertion(vector<Node*>& input) {
    if (!input.size()) {
        return NULL;
    }
    if (input[0] == NULL) {
        return NULL;
    }

    Node* root = input[0];
    int pos = 1;

    inOrderInsertion(root, input, pos);
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int val: values) {

    }
}