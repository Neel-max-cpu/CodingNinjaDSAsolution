/*

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note:
Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
0 <= Number of edges <= 10^5
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1


Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1


Sample Output 2 :
false
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;








*/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

#include <climits>
#include <algorithm>

// kind of pair but actually a triple
class Pair{
	public:
		int mini;
		int maxi;
		bool flag;
};

Pair helper(BinaryTreeNode<int>*root){
	if(root == NULL){
		Pair p;
		p.mini = INT_MAX;
		p.maxi = INT_MIN;
		p.flag = true;
		return p;
	}

	Pair left = helper(root->left);
	Pair right = helper(root->right);

	int minimum = min(root->data, min(left.mini, right.mini));
	int maximum = max(root->data, max(left.maxi, right.maxi));
	bool f = (root->data > left.maxi) && (root->data < right.mini) && left.flag && right.flag;

	Pair p;
	p.mini = minimum;
	p.maxi = maximum;
	p.flag = f;

	return p;
}

bool helper2(BinaryTreeNode<int>*root, int mini, int maxi){
	if(root == NULL) return true;

	if(root->data > maxi || root->data < mini) return false;
	// here for left side the right side should be max data-1
	// and of right side mini can be data
	

	// return (helper2(root->left, mini, root->data-1) && helper2(root->right, root->data, maxi));
	// or
	bool isLeftOk = helper2(root->left, mini, root->data-1);
	bool isRightOk = helper2(root->right, root->data, maxi);
	return  (isLeftOk && isRightOk);
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here

	// METHOD 1 ----
	// return helper(root).flag;

	// METHOD 2 ----
	return helper2(root, INT_MIN, INT_MAX);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}