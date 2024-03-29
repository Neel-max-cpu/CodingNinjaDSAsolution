/*

Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Example:
In this example, the green coloured node is the LCA to A and B.
Alt Text

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
Example:
Alt Text

Note:
1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains two integers, denoting the value of data of two nodes of given binary tree.
Output Format:
The first and only line of output contains the data associated with the lowest common ancestor node.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
Sample Output 1:
10
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78
Sample Output 3:
-1
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



#include <vector>
#include <algorithm>

void check1(BinaryTreeNode<int>*root, int a, vector<int>&v){
	if(root==NULL) return;
	if(root->data == a){
		v.push_back(root->data);
		return;
	}
	if(root->data >a){
		v.push_back(root->data);
		check1(root->left, a, v);
	}
	else{
		v.push_back(root->data);
		check1(root->right, a, v);
	} 
}

void check2(BinaryTreeNode<int>*root, int b, vector<int>&v){
	if(root==NULL) return;
	if(root->data == b){
		v.push_back(root->data);
		return;
	}
	if(root->data >b){
		v.push_back(root->data);
		check1(root->left, b, v);
	}
	else{ 
		v.push_back(root->data);
		check1(root->right, b, v);
	}
}


BinaryTreeNode<int>*helper(BinaryTreeNode<int>*root, int a, int b){
	if(root==NULL)return NULL;

	if(root->data == a || root->data == b) return root;

	BinaryTreeNode<int>*left = helper(root->left, a, b);
	BinaryTreeNode<int>*right = helper(root->right, a, b);

	if(left && right) return root;  // if both ar not null
	if(left) return left;
	return right;
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here

	BinaryTreeNode<int>*node = helper(root,a,b);
	if(node != NULL) return node->data;
	else return -1;

	// METHOD 1 ----- 
	/*
	if(a==b) return a;

	vector<int>a1;
	vector<int>b1;
	check1(root,a,a1);
	check2(root,b,b1);


	int n = a1.size();
	int m= b1.size();

	if(n==0 && m!=0) return b;
	else if(n!=0 && m==0) return a;
	else if(n!=0 && m!=0){
		int s = min(n,m);
		int i = 0;
		for(; i<s; i++){
			if(a1[i]!=b1[i]) return a1[i-1];
		}
		return a1[i-1];
	}
	else
		return -1;
	*/

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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}