/*

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Note :
The binary tree will be consisting of only unique elements.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1


Sample Output 1:
2
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include <climits>

bool isBST(BinaryTreeNode<int>*root, int mini, int maxi){
	if(root == NULL) return true;
	if(root->data < mini || root->data>maxi) return false;
	else return isBST(root->left, mini, root->data-1) && isBST(root->right, root->data, maxi);
}

int findHeight(BinaryTreeNode<int>*root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	return max(findHeight(root->left), findHeight(root->right))+1;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here

	if(root == NULL) return 0;
	if(isBST(root,INT_MIN, INT_MAX)){
		return findHeight(root);
	}
	else{
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
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
    cout << largestBSTSubtree(root);
    delete root;
}