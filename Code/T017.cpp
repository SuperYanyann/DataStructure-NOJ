#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct BTreeNode
{
	char element;
	BTreeNode* LChild;
	BTreeNode* RChild;
};

BTreeNode* getTree()
{
	char temp = getchar();
	if (temp == '#')
		return NULL;
	BTreeNode* treeRoot = new BTreeNode;

	treeRoot->element = temp;
	treeRoot->LChild = getTree();
	treeRoot->RChild = getTree();

	return treeRoot;
}

void inOrder(BTreeNode* tree)
{
	if (tree == NULL)
		return;
	inOrder(tree->LChild);
	cout << tree->element;
	inOrder(tree->RChild);
}

int main()
{
	BTreeNode* expression;
	expression = getTree();
	inOrder(expression);

	return 0;
}