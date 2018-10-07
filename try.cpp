#include <iostream>
#include <string.h>
#include <map>
#include "node.h"
using namespace std;

map<char, int> hierarchy = {
	{'+',1},
	{'-',2},
	{'*',3},
	{'/',4},
	{'^',5},
	{'$',6},
};

int buscarKing(string thystring){ 
	int count=0;
	char myking='$';
	int posOfKing=0;

	for(int i=0; i<thystring.length(); i++){
		char current= thystring[i]; // Current? Debería buscar operadores

		if(thystring[i]=='('){
			count+=1;
		}
		else if(thystring[i]==')'){
			count-=1;
		}

		if(count==0 && hierarchy.find(current)!=hierarchy.end()){
			if(hierarchy[current] < hierarchy[myking]){
				myking=current;
				posOfKing=i;
			}
		}

	}
	return posOfKing;
}

node* constructTree(string thystring){ // Esto no va a construir el árbol
	node* root=nullptr;

	int posOfKing=buscarKing(thystring); // Qué es king?


	if(!root){
		root = newNode(string(1,thystring[posOfKing]));
	}
	root->right = newNode(thystring.substr(posOfKing+1));
	root->left = newNode(thystring.substr(0, posOfKing));
	//root -> right = rootright;
	cout << root->left->data;
}


int main(int argc, char const *argv[]) {
	string a="(3*3)^4/5";
	buscarKing(a);
	constructTree(a);


	return 0;
}
