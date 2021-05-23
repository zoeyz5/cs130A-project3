#include<iostream>
#include<algorithm>
#include<cmath>
#include "K-AVL.h"

int K_AVL::height(K_AVLTreeNode * node)
{
	if (node == nullptr)
		return 0;
	return std::max(height(node->left), height(node->right)) + 1;
}

K_AVLTreeNode * K_AVL::rightRotate(K_AVLTreeNode * node)
{
	K_AVLTreeNode* left = node->left;
	node->left = left->right;
	left->right = node;
	return left;
}

K_AVLTreeNode * K_AVL::leftRotate(K_AVLTreeNode * node)
{
	K_AVLTreeNode* right = node->right;
	node->right = right->left;
	right->left = node;
	return right;
}

K_AVLTreeNode * K_AVL::leftRightRotate(K_AVLTreeNode * node)
{
	node->left = leftRotate(node->left);
	return rightRotate(node);
}

K_AVLTreeNode * K_AVL::rightLeftRotate(K_AVLTreeNode * node)
{
	node->right = rightRotate(node->right);
	return leftRotate(node);
}

int K_AVL::balance_fector(K_AVLTreeNode * node)
{
	if (node == nullptr)
		return 0;
	return height(node->left) - height(node->right);
}

K_AVLTreeNode * K_AVL::rebalance(K_AVLTreeNode * node)
{
	int fector = balance_fector(node);
	if (fector > k)
	{
		if (balance_fector(node->left) >= 0) 
			node = rightRotate(node);  //LL
		else
			node = leftRightRotate(node); //LR
	}
	if (fector < -k)
	{
		if (balance_fector(node->right) <= 0)  //RR
			node = leftRotate(node);
		else
			node = rightLeftRotate(node);  //RL
	}
	return node;
}

K_AVLTreeNode * K_AVL::insert(K_AVLTreeNode * node, const pair<int, int>& val)
{
	if (node == nullptr)
		return new K_AVLTreeNode(val);
	if (val == node->data)
		return node;
	if (val < node->data)
		node->left = insert(node->left, val);
	else
		node->right = insert(node->right, val);
	return rebalance(node);
}

K_AVLTreeNode * K_AVL::remove(K_AVLTreeNode * node, const pair<int, int>& val)
{
	if (node == nullptr) return node;
	if (val < node->data)
	{
		node->left = remove(node->left, val);
	}
	else if (val > node->data)
	{
		node->right = remove(node->right, val);
	}
	else
	{
		if (node->left == nullptr)
		{
			K_AVLTreeNode* del = node;
			node = node->right;
			delete del;
		}
		else if (node->right == nullptr)
		{
			K_AVLTreeNode* del = node;
			node = node->left;
			delete del;
		}
		else
		{
			K_AVLTreeNode* successor = new K_AVLTreeNode(minimum(node->left));
			node->left = remove(node->left, successor->data);
			successor->left = node->left;
			successor->right = node->right;
			delete node;
			node = successor;
		}
	}
	return rebalance(node);
}

bool K_AVL::contains(const pair<int, int>& x, K_AVLTreeNode * t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->data)
		return contains(x, t->left);
	else if (t->data < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void K_AVL::ApproximateSearch(pair<int, int>& x, K_AVLTreeNode * t, pair<int, int> & data) 
{
	if (t != nullptr)
	{
		ApproximateSearch(x, t->left, data);
		double data1 = subtwodata(x, t->data);
		double data2 = subtwodata(x, data);
		if (fabs(data1 - data2) <= 1e-6)
		{
			if (t->data<data)
			{
				data = t->data;
			}
		}
		else if (data1 < data2)
		{
			data = t->data;
		}
		ApproximateSearch(x, t->right, data);
	}
}

void K_AVL::InOrderPrint(K_AVLTreeNode * t)
{
	if (t != nullptr)
	{
		InOrderPrint(t->left);
		if (flag == true)
		{
			cout << " ";
		}
		else
		{
			flag = true;
		}
		displaydata(t->data);
		InOrderPrint(t->right);
	}
}

void K_AVL::PreOrderPrint(K_AVLTreeNode * t)
{
	if (t != nullptr)
	{
		if (flag == true)
		{
			cout << " ";
		}
		else
		{
			flag = true;
		}
		displaydata(t->data);
		PreOrderPrint(t->left);
		PreOrderPrint(t->right);
	}
}

K_AVLTreeNode * K_AVL::minimum(K_AVLTreeNode * node)
{
	while (node->right)
	{
		node = node->right;
	}
	return node;
}
void K_AVL::destroy(K_AVLTreeNode * node)
{
	if (node != nullptr)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}
void K_AVL::displaydata(const pair<int, int>& val)
{
	cout << val.first << "." << val.second;
}
double K_AVL::subtwodata(pair<int, int>& val1, pair<int, int>& val2)
{
	double getdata;
	getdata = val1.first + (double)val1.second / 10 - val2.first - (double)val2.second/10;
	return fabs(getdata);
}
K_AVL::K_AVL(int k):root(nullptr)
{
	this->k = k;
}

K_AVL::~K_AVL()
{
	destroy(root);
}

void K_AVL::Insert(pair<int, int> data)
{
	if (contains(data, root) == false)
	{
		root = insert(root, data);
		displaydata(data);
		cout << " inserted" << endl;
	}
}

void K_AVL::Delete(pair<int, int> data)
{
	if (contains(data, root) == true)
	{
		root = remove(root, data);
		displaydata(data);
		cout << " deleted" << endl;
	}
}

void K_AVL::Search(pair<int, int> data)
{
	displaydata(data);
	if (contains(data, root))
	{
		cout << " found" << endl;
	}
	else
	{
		cout << " not found" << endl;
	}
}

void K_AVL::ApproximateSearch(pair<int, int> data)
{
	if (root != nullptr)
	{
		pair<int, int> finddata = root->data;
		ApproximateSearch(data, root, finddata);
		cout << "closest to ";
		displaydata(data);
		cout << " is ";
		displaydata(finddata);
		cout << endl;
	}
	
}

void K_AVL::InOrderPrint()
{
	if (root != nullptr)
	{
		flag = false;
		InOrderPrint(root);
		cout << endl;
	}
}

void K_AVL::PreOrderPrint()
{
	if (root != nullptr)
	{
		flag = false;
		PreOrderPrint(root);
		cout << endl;
	}
}
