/*

Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.
Output Format:
 The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10
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
#include <set>

// void helper(BinaryTreeNode<int>*root, int k1, int k2, vector<int>&v){
void helper(BinaryTreeNode<int>*root, int k1, int k2, set<int>&v){
	if(root == NULL) return;

	int a = root->data;
	if(a>=k1 && a<=k2){
		if(a==k1){
			// v.push_back(a);
			v.insert(a);
			helper(root->right, k1, k2, v);
		}
		else if(a>k1 && a<k2){
			// v.push_back(a);
			v.insert(a);
			helper(root->left, k1, k2, v);
			helper(root->right, k1, k2, v);
		}
		else if(a==k2){
			// v.push_back(a);
			v.insert(a);
			helper(root->left, k1, k2, v);
		}
	}
	else if(a<k1){
		helper(root->right, k1, k2, v);
	}
	else if(a>k2){
		helper(root->left, k1, k2, v);
	}
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here

	// METHOD 1 ----------
	/*
	// vector<int>v;
	set<int>v;
	helper(root, k1,k2, v);
	// sort(v.begin(),v.end());
	// for(auto it:v){
	// 	s.insert(it);
	// }
	for(auto it:v) cout<<it<<" ";
	// for(int i = s.begin(); i!=s.end(); i++) cout<<s[i]<<" ";
	cout<<endl;
	*/


	// METHOD 2 -----------
	if(root == NULL) return;

	int a = root->data;
	if(a>=k1 && a<=k2){
		elementsInRangeK1K2(root->left, k1, k2);
		cout<<a<<" ";
		elementsInRangeK1K2(root->right, k1, k2);
	}
	else if(a<k1){
		elementsInRangeK1K2(root->right, k1, k2);
	}
	else if(a>k2){
		elementsInRangeK1K2(root->left, k1, k2);
	}

}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}