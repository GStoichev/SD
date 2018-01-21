#pragma once

template <typename T> struct Node
{
	T value;
	Node<T>* left;
	Node<T>* right;
};

template <typename T> class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void insert(const T& element);
	bool search(const T& element);
	void destroy();

private:
	Node<T>* root;

	void insert(const T& element, Node<T>*& node);
	bool search(const T& element, Node<T>* node);
	void destroy(Node<T>*& node);
};

//Methods
template <typename T> BinaryTree<T>::BinaryTree()
{
	this->root = nullptr;
}
template <typename T> void BinaryTree<T>::insert(const T& element)
{
	this->insert(element, this->root);
}
template <typename T> bool BinaryTree<T>::search(const T& element)
{
	return this->search(element, this->root);
}
template <typename T> void BinaryTree<T>::destroy()
{
	this->destroy(this->root);
}

//Private Functions
template <typename T> void BinaryTree<T>::insert(const T& element, Node<T>*& node)
{
	if (node == nullptr)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = element;
		newNode->right = nullptr;
		newNode->left = nullptr;
		node = newNode;
		return;
	}
	if (element < node->value)
	{
		this->insert(element, node->left);
	}
	else
	{
		this->insert(element, node->right);
	}
}
template <typename T> bool BinaryTree<T>::search(const T& element,  Node<T>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->value == element)
	{
		return true;
	}
	if (element < node->value)
	{
		return this->search(element, node->left);
	}
	else 
	{
		return this->search(element, node->right);
	}
}
template <typename T> void BinaryTree<T>::destroy(Node<T>*& node)
{
	if (node == nullptr)
	{
		return;
	}
	this->destroy(node->left);
	this->destroy(node->right);
	if (node == this->root)
	{
		delete node;
		node = nullptr;
	}
	else
	{
		delete node;
		
	}
}


//Destructor
template <typename T> BinaryTree<T>::~BinaryTree()
{
	this->destroy();
}