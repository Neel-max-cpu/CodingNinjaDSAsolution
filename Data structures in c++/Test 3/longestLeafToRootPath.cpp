/*

Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output format :
Line 1 : Binary Tree 1 (separated by space)
Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Input Graph

Sample Output 1 :
9
3
6
5
Input Graph

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;






*/

#include <iostream>
#include <vector>
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
// Following is the Binary Tree node structure
/**************
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
***************/
#include <vector>

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if(root == NULL) return NULL;
    if(!root->left && !root->right){                        // or root->left == NULL && root->right == NULL
        vector<int>*output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>*leftans = longestPath(root->left);
    vector<int>*rightans = longestPath(root->right);

    if(!leftans){       // if there is no left subtree put it in the right  or leftans == NULL
        rightans->push_back(root->data);
        return rightans;
    }
    else if(!rightans){                 // if there is no right subtree put it in the right -- basically checking if its null or not
        leftans->push_back(root->data);
        return leftans;
    }
    else{
        if(leftans->size() < rightans->size()){
            rightans->push_back(root->data);
            delete leftans;
            return rightans;
        }
        else{
            leftans->push_back(root->data);
            delete rightans;
            return leftans;
        }
    }



}


// METHOD 1 --------
/*
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if (root == NULL) {
        vector<int>*temp = new vector<int>;
        // vector<int> temp;
        return temp;
    }
 
    // Recursive call on root->right
    vector<int> *rightvect = new vector<int>;
    rightvect = longestPath(root->right);
 
    // Recursive call on root->left
    vector<int> *leftvect = new vector<int>();
    leftvect = longestPath(root->left);
 
    // Compare the size of the two vectors
    // and insert current node accordingly
    if (leftvect->size() > rightvect->size())
        leftvect->push_back(root->data);
 
    else
        rightvect->push_back(root->data);
 
    // Return the appropriate vector
    return (leftvect->size() > rightvect->size()? leftvect: rightvect);

}
*/

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
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
