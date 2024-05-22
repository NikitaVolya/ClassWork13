#pragma once

#include <iostream>

template <typename T>
class Node
{
public:
	T value;
	Node<T>* left;
	Node<T>* right;

	Node(const T& pValue, Node<T>* pLeft = nullptr, Node<T>* pRight = nullptr) : value(pValue), left(pLeft), right(pRight) {};

	void clearRoot();
	std::ostream& printINFIX(std::ostream& out) const;
};

template<typename T>
inline void Node<T>::clearRoot()
{
	if (left)
		left->clearRoot();
	if (right)
		right->clearRoot();
	delete this;
}

template<typename T>
inline std::ostream& Node<T>::printINFIX(std::ostream& out) const
{
	if (left)
		left->printINFIX(out);
	out << value << ", ";
	if (right)
		right->printINFIX(out);
	return out;
};



template <typename T>
class BinaryTree
{
private:
	Node<T>* root;
	size_t number;

public:
	BinaryTree() : root(nullptr), number(0) {};
	~BinaryTree();

	size_t size() const {return number;}

	void add(const T& value);
	bool find(const T& value) const;

	std::ostream& printINFIX(std::ostream& out) const { if (root) root->printINFIX(out); return out; };
};

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	if (root)
		root->clearRoot();
}

template<typename T>
inline void BinaryTree<T>::add(const T& value)
{
	number++;
	
	if (!root)
	{
		root = new Node<T>{ value };
		return;
	}

	Node<T>* tmp = root;
	Node<T>* newNode = new Node<T>{ value };
	
	while (tmp)
	{
		if (tmp->value > value)
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				tmp->left = newNode;
				return;
			}
		if (tmp->value <= value)
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				tmp->right = newNode;
				return;
			}
	}
}

template<typename T>
inline bool BinaryTree<T>::find(const T& value) const
{
	Node<T>* tmp = root;
	while (tmp)
	{
		if (tmp->value == value)
			return true;
		else if (tmp->value > value)
			tmp = tmp->left;
		else if (tmp->value <= value)
			tmp = tmp->right;
	}
	return false;
}