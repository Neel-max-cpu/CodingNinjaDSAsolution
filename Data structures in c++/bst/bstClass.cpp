/*

Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
2. search
Given an element, find if that is present in BST or not. Return true or false.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
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
using namespace std;

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

    
#include <queue>

class BST {
    // Define the data members
    BinaryTreeNode<int>*root;
   public:
    BST() { 
        // Implement the Constructor 
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
    
    private:
    ~BST(){
        delete root;
    }
    BinaryTreeNode<int>*findmin(BinaryTreeNode<int>*node){
        if(node->left == NULL) return node;
        findmin(node->left);
    }
      BinaryTreeNode<int>*findmax(BinaryTreeNode<int>*node){
        if(node->right == NULL) return node;
        findmin(node->right);
    }

    BinaryTreeNode<int>* removeHelper(int data, BinaryTreeNode<int>*node){
        if(node == NULL) return NULL;
        
        if(node->data == data){
            // case 1 if both null
            if(node->left == NULL && node->right == NULL){
                free(node);

                // insted of free we can use delete
                // delete node;
                return NULL;
            }
            // case if any one is null
            else if(node->left == NULL || node->right == NULL){
                // here left is null
                if(node->left == NULL){
                    BinaryTreeNode<int>*temp = node->right;
                    node->right = NULL;
                    // free node;
                    delete node;
                    
                    return temp;
                }
                // here right is null
                else{
                    BinaryTreeNode<int>*temp = node->left;
                    node = temp;
                    node->left = NULL;
                    delete node;
                    // free(temp);

                    return temp;
                }
            }
            // case 3 if both are not null --- one problem like  test case 3 where the whole tree is same ------ so it will recursively call the whole
            // tree and delete every thing
            else if(node->left != NULL && node->right != NULL){
                // BinaryTreeNode<int>*temp = findmin(node->right);
                // BinaryTreeNode<int>*temp = findmax(node->left);
                if(node->right != NULL){
                    BinaryTreeNode<int>*minNode = node->right;
                    while(minNode->left != NULL){
                        minNode = minNode->left;
                    }

                    // since minNode is smallest in the right
                    int rightMin = minNode->data;
                    node->data = rightMin;
                    // now what is happening here is that minNode is the lowest, so its left and right are both NULL so 1st case will take
                    // place and we can easily delete the node using recursive
                    // but that might change the structure so return the right

                    // similarly we can use maximum of node->left, instead of minimum of node->right
                    node->right = removeHelper(rightMin, node->right);
                    return node;
                }
                else if(node->left != NULL){
                    // using left maximum
                     BinaryTreeNode<int>*maxNode = node->left;
                    while(maxNode->right != NULL){
                        maxNode = maxNode->right;
                    }

                    int leftMax = maxNode->data;
                    node->data = leftMax;
                    
                    node->left = removeHelper(leftMax, node->left);
                    return node;
                }
                // then basically the data is deleted;
            }
        }
        else if(node->data > data){
            node->left = removeHelper(data, node->left);
            
        }
        else{ 
            node->right = removeHelper(data, node->right);
        }
    }
    
    BinaryTreeNode<int>*removeHelper2(int data, BinaryTreeNode<int>*node){
        if(node == NULL) return NULL;

        if(node->data == data){
            if(node->left != NULL && root->right == NULL){
                return node->left;
            }
            else if(node->left == NULL && root->right != NULL){
                return node->right;
            }
            else if(node->left == NULL && root->right == NULL)
                return NULL;
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                node->data = minNode->data;
                node->right = removeHelper2(minNode->data, node->right);
                return  node;
            }
        }
    }

    public:
    void remove(int data) { 
        // Implement the remove() function 
        
        // there are 3 case if both left and right child are null then no problen
        // if there is one child of the data then place the child's data in place of parent's
        // if it has both then either put smallest of the right in place or parent or largest of the left in place of parent
        
        // root = removeHelper(data, root);
        root = removeHelper2(data,root);

    }


    private:
    void helperPrint(BinaryTreeNode<int>*node){
        // BinaryTreeNode<int>*node = root;
        if(node == NULL) return;
        cout<<node->data<<":";
        if(node->left != NULL){
            cout<<"L:"<<node->left->data<<",";
        }
        if(node->right != NULL) {
            cout<<"R:"<<node->right->data;
        }
        cout<<endl;

        helperPrint(node->left);
        helperPrint(node->right);

    }

    public:
    void print() { 
        // Implement the print() function
       helperPrint(root);
        
    }

    private:
    BinaryTreeNode<int>* insertHelper(int data, BinaryTreeNode<int>*node){
        if(node == NULL) {
            BinaryTreeNode<int>*temp = new BinaryTreeNode<int>(data);
            return temp;
        }
        if(data <= node->data){
            node->left = insertHelper(data, node->left);
        }
        else node->right = insertHelper(data, node->right);

        return node;
    }

    public:
    void insert(int data) { 
        // Implement the insert() function 
        this->root = insertHelper(data, this->root);
    }

    

    private:
    bool searchHelper(int data, BinaryTreeNode<int>*node){
        if(node == NULL) return false;
        if(node->data == data) return true;

        else if(data < node->data){
            searchHelper(data, node->left);
        }
        else searchHelper(data, node->right);
    }


    public:
    bool search(int data) {
		// Implement the search() function 
        return searchHelper(data, root);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}