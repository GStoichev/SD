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
	bool remove(const T& element);
	void destroy();


	void printTree();

private:

	void print(Node<T> *root);
	Node<T>* root;

	bool remove(const T& element, Node<T>*& node);
	Node<T>*& remove_swap(Node<T>*& node);
	void insert(const T& element, Node<T>*& node);
	bool search(const T& element, Node<T>* node);
	void destroy(Node<T>*& node);
};


template <typename T>
void BinaryTree<T>::print(Node<T> *root)
{
	if (root)
	{
		print(root->left);
		std::cout << root->value << " ";
		print(root->right);
		std::cout<<std::endl;
	}
}

template <typename T>
void BinaryTree<T>::printTree()
{
	print(root);
}





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
template <typename T> bool BinaryTree<T>::remove(const T& element)
{
	return this->remove(element, this->root);
}


//Private Functions
template <typename T> bool BinaryTree<T>::remove(const T& element, Node<T>*& node)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->value == element)
	{
		if (node->right == nullptr && node->left == nullptr)
		{
			delete node;
			node = nullptr;
			return true;
		}
		if (node->right == nullptr)
		{
			Node<T>* temp = node->left;
			delete node;
			node = temp;
			return true;
		}
		else
		{
			Node<T>*& temp = this->remove_swap(node->right);
			node->value = temp->value;
			delete temp;
			temp = nullptr;
			return true;
		}
	}
	if (node->value < element)
	{
		return this->remove(element, node->right);
	}
	else
	{
		return this->remove(element, node->left);
	}
}

template <typename T> Node<T>*& BinaryTree<T>::remove_swap(Node<T>*& node)
{
	if (node->left == nullptr)
	{
		return node;
	}
	return this->remove_swap(node->left);
}
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
	if (node->value < element)
	{
		this->insert(element, node->right);
	}
	else
	{
		this->insert(element, node->left);
	}
}
template <typename T> bool BinaryTree<T>::search(const T& element, Node<T>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->value == element)
	{
		return true;
	}
	if (node->value < element)
	{
		return this->search(element, node->right);
	}
	else
	{
		return this->search(element, node->left);
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