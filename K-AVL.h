#ifndef _K_AVL_H_
#define _K_AVL_H_

#include <iostream>
using namespace std;

class K_AVLTreeNode {
public:
	pair<int, int> data;
	K_AVLTreeNode *left;
	K_AVLTreeNode *right;
	K_AVLTreeNode(pair<int, int>  value) :
		data(value), left(nullptr), right(nullptr) {}
	K_AVLTreeNode(const K_AVLTreeNode* n) :
	 data(n->data), left(n->left), right(n->right) {}
};

class K_AVL {
private:
	K_AVLTreeNode *root;
	int k;
	bool flag;
private:
	int height(K_AVLTreeNode* node);
	K_AVLTreeNode* minimum(K_AVLTreeNode* node);
	void destroy(K_AVLTreeNode* node);
	void displaydata(const pair<int, int>& val);
	double subtwodata(pair<int, int>& val1, pair<int, int>& val2);
	K_AVLTreeNode* rightRotate(K_AVLTreeNode* node);  //LL
	K_AVLTreeNode* leftRotate(K_AVLTreeNode* node);    //RR
	K_AVLTreeNode* leftRightRotate(K_AVLTreeNode* node); //LR
	K_AVLTreeNode* rightLeftRotate(K_AVLTreeNode* node);  //RL
	int balance_fector(K_AVLTreeNode* node);
	K_AVLTreeNode* rebalance(K_AVLTreeNode* node);
	K_AVLTreeNode* insert(K_AVLTreeNode* node, const pair<int, int>& val);
	K_AVLTreeNode* remove(K_AVLTreeNode* node, const pair<int, int>& val);
	bool contains(const pair<int, int>& x, K_AVLTreeNode* t) const;
	void ApproximateSearch(pair<int, int>& x, K_AVLTreeNode* t, pair<int, int> & data);
	void InOrderPrint(K_AVLTreeNode* t);
	void PreOrderPrint(K_AVLTreeNode* t);
public:
	K_AVL(int k);
	~K_AVL();
	void Insert(pair<int, int> data);
	void Delete(pair<int, int> data);
	void Search(pair<int, int> data);
	void ApproximateSearch(pair<int, int> data);
	void InOrderPrint();
	void PreOrderPrint();
};


#endif
