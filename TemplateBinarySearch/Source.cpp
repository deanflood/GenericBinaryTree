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
	charTree.add('b');
	charTree.add('a');
	charTree.add('d');
	charTree.add('e');
	charTree.add('f');

	charTree.inorder();
	cout << endl << boolalpha << charTree.find('a');
	cout << endl << boolalpha << charTree.find('d');
	cout << endl;

	cout << charTree.height() << endl;

	cout << "MIN: " << intTree.findMin() << endl;
	cout << "MAX: " << doubleTree.findMax() << endl;

	charTree.printTree();

	cout << endl << endl;

	charTree.deleteNode('e');

	charTree.printTree();

	system("pause");
}