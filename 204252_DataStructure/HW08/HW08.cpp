#include "BSTNode.cpp"

class BST {

public:
  BSTNode* root;

  BST() {
    root = nullptr;
  }

  BSTNode *createNewNode (int data) {
    BSTNode *newNode = new BSTNode();
    newNode->value = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }

  void insert(int value) {
    BSTNode *p;
    BSTNode *previous;
    BSTNode *newNode = createNewNode(value);
    if (root==nullptr){
      root = newNode;
    } else {
      p = root;
      
      while (p != nullptr) {
        previous = p;
        if (p->value > newNode->value){
          p = p->left;
        } else {
          p = p->right;
        }
      }

      if (previous->value > newNode->value){
        previous->left = newNode;
      } else {
        previous->right = newNode;
      }
    }

  }

  void remove(int value) {
    /*Write your code here*/
    if (root->left==nullptr && root->right==nullptr){
      delete root;
      root = nullptr;
    } else if (root->left==nullptr) {
      BSTNode *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right==nullptr) {
      BSTNode *temp = root;
      root = root->left;
      delete temp;
    }
  }
  

  int get_depth(int value) {
    BSTNode *rootCopy = root; 

    int countDepth = 0;
    while (rootCopy != nullptr) {
        if (rootCopy->value > value) {
          rootCopy = rootCopy->left;
          countDepth++;
        } else if (rootCopy->value < value) {
          rootCopy = rootCopy->right;
          countDepth++;
        } else {
          break;
        }
    }
    if (rootCopy == nullptr) {
      return -1;
    }
    return countDepth;
  }

};
