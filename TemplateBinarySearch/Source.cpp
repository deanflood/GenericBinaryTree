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
	intTree.preorder();
	cout << endl;
	intTree.postorder();
	cout << endl << boolalpha << intTree.find(3);
	cout << endl << boolalpha << intTree.find(4);
	cout << endl;

	GenericBinarySearchTree<double> doubleTree;
	doubleTree.add(1.1);
	doubleTree.add(3.1);
	doubleTree.add(2.1);
	doubleTree.inorder();
	cout << endl << boolalpha << doubleTree.find(3.1);
	cout << endl << boolalpha << doubleTree.find(3.2);
	cout << endl;

	GenericBinarySearchTree<char> charTree;
	charTree.add('a');
	charTree.add('c');
	charTree.add('b');
	charTree.inorder();
	cout << endl << boolalpha << charTree.find('a');
	cout << endl << boolalpha << charTree.find('d');
	cout << endl;

	system("pause");
}