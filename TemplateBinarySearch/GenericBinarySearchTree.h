#pragma once
template <class T>
class TreeNode {
	template <class T>
	friend class GenericBinarySearchTree;
	T data;
	TreeNode * left;
	TreeNode * right;
	TreeNode(T val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

template <class T>
class GenericBinarySearchTree
{
	
public:
	GenericBinarySearchTree();
	void add(T);
	void inorder();
private:
	TreeNode<T> *root;
	void add(TreeNode<T> *, TreeNode<T> *);
	void inorder(TreeNode<T> *);
};

template<class T>
inline GenericBinarySearchTree<T>::GenericBinarySearchTree()
{
	root = nullptr;
}

template<class T>
inline void GenericBinarySearchTree<T>::add(T data)
{
	TreeNode<T> * toAdd = new TreeNode<T>(data);
	if (root == nullptr) {
		root = toAdd;
	}
	else {
		add(toAdd, root);
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::inorder()
{
	inorder(root);
}

template<class T>
inline void GenericBinarySearchTree<T>::add(TreeNode<T>* toAdd, TreeNode<T>* addHere)
{
	if (toAdd->data < addHere->data) {
		if (addHere->left == nullptr) {
			addHere->left = toAdd;
		}
		else {
			add(toAdd, addHere->left);
		}
	}
	else if (toAdd->data > addHere->data) {
		if (addHere->right == nullptr) {
			addHere->right = toAdd;
		}
		else {
			add(toAdd, addHere->right);
		}
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::inorder(TreeNode<T>* node)
{
	if (node != nullptr) {
		inorder(node->left);
		cout << node->data;
		inorder(node->right);
	}
}
