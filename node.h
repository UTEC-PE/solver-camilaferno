#include <iostream>
using namespace std;

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(char data){
  struct node* newNode = new struct node;
  newNode -> data = data;
  newNode -> left = nullptr;
  newNode -> right = nullptr;

  return newNode;
}
