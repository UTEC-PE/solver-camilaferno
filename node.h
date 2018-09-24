#include <iostream>
#include <string.h>
using namespace std;

struct node{
  string data;
  struct node* left;
  struct node* right;
};

struct node* newNode(string data){
  struct node* newNode = new struct node;
  newNode -> data = data;
  newNode -> left = nullptr;
  newNode -> right = nullptr;

  return newNode;
}
