#include "GenericBinarySearchTree.h"
#include <iostream>

using namespace std;

void main() {
	GenericBinarySearchTree<int> intTree;
	intTree.add(1);
	intTree.add(3);
	intTree.add(2);
	intTree.inorder();
	cout << endl;


	GenericBinarySearchTree<double> doubleTree;
	doubleTree.add(1.1);
	doubleTree.add(3.1);
	doubleTree.add(2.1);
	doubleTree.inorder();
	cout << endl;

	GenericBinarySearchTree<char> charTree;
	charTree.add('a');
	charTree.add('c');
	charTree.add('b');
	charTree.inorder();
	cout << endl;


	system("pause");
	
}