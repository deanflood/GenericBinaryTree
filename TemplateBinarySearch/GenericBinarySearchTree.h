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
	~GenericBinarySearchTree();
	void add(T);
	void inorder();
	void preorder();
	void postorder();
	bool find(T);
private:
	bool find(TreeNode<T>*, T);
	TreeNode<T> *root;
	void add(TreeNode<T> *, TreeNode<T> *);
	void inorder(TreeNode<T> *);
	void preorder(TreeNode<T> *);
	void postorder(TreeNode<T> *);
	void destroy(TreeNode<T> *);

};

template<class T>
inline GenericBinarySearchTree<T>::GenericBinarySearchTree()
{
	root = nullptr;
}

template<class T>
inline GenericBinarySearchTree<T>::~GenericBinarySearchTree()
{
	destroy(root);
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
inline void GenericBinarySearchTree<T>::preorder()
{
	preorder(root);
}

template<class T>
inline void GenericBinarySearchTree<T>::postorder()
{
	postorder(root);
}

template<class T>
inline bool GenericBinarySearchTree<T>::find(T data)
{
	return find(root, data);
}

template<class T>
inline bool GenericBinarySearchTree<T>::find(TreeNode<T>* node, T data)
{
	if (node != nullptr) {
		if (data == node->data) {
			return true;
		}
		else if (data < node->data) {
			return find(node->left, data);
		}
		else {
			return find(node->right, data);
		}
	}
	else {
		return false;
	}
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

template<class T>
inline void GenericBinarySearchTree<T>::preorder(TreeNode<T>* node)
{ 
	if (node != nullptr) {
		cout << node->data;
		preorder(node->left);
		preorder(node->right);
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::postorder(TreeNode<T>* node)
{
	if (node != nullptr) {
		preorder(node->left);
		preorder(node->right);
		cout << node->data;
	}
}

template<class T>
inline void GenericBinarySearchTree<T>::destroy(TreeNode<T>* node)
{
	if (node != nullptr) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

