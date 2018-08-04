#include <cstdio>
#include <iostream>
#include <string.h>
using namespace::std;

typedef struct treeNode{
	char key;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
}treeNode;

int findIndex(string tree, char ch, int n){
	for (int i = 0; i < n; i++)
		if (tree[i] == ch)
			return i;
	return -1;
}

treeNode* build_tree(char tree1[], char tree2[], int lenTree, treeNode* &newTree){
	if (lenTree == 0) 
		return NULL;
	else{
		char ch = tree1[0];
		int i = findIndex(tree2, ch, lenTree);
		newTree = new treeNode;

		newTree->key = ch;
		newTree->leftChild = build_tree(tree1 + 1, tree2, i, newTree->leftChild);
		newTree->rightChild = build_tree(tree1 + i + 1, tree2 + i + 1, lenTree - i - 1, newTree->rightChild);
	}
	return newTree;
}

void traverBack(treeNode* T){
	if (T){
		traverBack(T->leftChild);
		traverBack(T->rightChild);
		cout <<T->key;
	}
}
int main()
{
	treeNode* treeBackOrder= NULL;
	char treePreOrder[100];
	char treeInOrder[100];
	char temp;
	int lenTree = 0;

	cin >> treePreOrder;
	cin >> treeInOrder;

	lenTree = strlen(treeInOrder);
	build_tree(treePreOrder, treeInOrder, lenTree, treeBackOrder);

	traverBack(treeBackOrder);

	return 0;
}