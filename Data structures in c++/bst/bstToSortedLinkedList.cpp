/*

Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
1<=n<=10^5
Note:
In case if you are facing any issue to solve this problem, please prefer to use the helper function.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1


Sample Output 1:
2 5 6 7 8 10
/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;






*/

#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/

pair<Node<int>*, Node<int>*> helper(BinaryTreeNode<int>* root){
	//  if root is null -- return null
	if(root == NULL){
		pair<Node<int>*, Node<int>*> ans;
		ans.first = NULL;
		ans.second = NULL;
		return ans;
	}

	// HERE .first = HEAD and .second = TAIL


	// NOW THERE ARE 4 CASES ---
	// 1) if both left and right are not null then ======= left/root->data/right
	// 2) if both are null then ======== root->data as head and tail both
	// 3) if left is null and right is not null then ====== root->data/right
	// 4) if right is null and left is not null then ====== left/root->data

	// if both left and right is not null -- then starting is leftHead and ending is rightTail
	if(root -> left != NULL && root -> right != NULL){
		pair<Node<int>*, Node<int>*> left = helper(root -> left);
		pair<Node<int>*, Node<int>*> right = helper(root -> right);

		Node<int>* head = left.first;

		// middle will be root data
		Node<int>* middle = new Node<int>(root -> data);
		
		// next of tail of left will be root data 
		left.second -> next = middle;
		// and root data's next is right's head
		middle -> next = right.first;

		pair<Node<int>*, Node<int>*> ans;
		ans.first = head;					//head	 
		ans.second = right.second;		// tail
		return ans;
	}

	// left is null and right is null --- then both head and tail  = root data
	else if(root -> left == NULL && root -> right == NULL){
		pair<Node<int>*, Node<int>*> ans;
		Node<int>* middle = new Node<int>(root -> data);
		ans.first = middle;
		ans.second = middle;
		return ans;
	}

	// if left is null and right is not null
	else if(root -> left == NULL && root -> right != NULL){
		pair<Node<int>*, Node<int>*> right = helper(root -> right);

		pair<Node<int>*, Node<int>*> ans;
		Node<int>* middle = new Node<int>(root -> data);

		middle -> next = right.first;
		
		ans.first = middle;						// head will be root's data
		ans.second = right.second;		// tail right.second
		return ans;
	}

	// if left is not null and right is null
	else if(root -> left != NULL && root -> right == NULL){
		pair<Node<int>*, Node<int>*> left = helper(root -> left);

		pair<Node<int>*, Node<int>*> ans;
		Node<int>* middle = new Node<int>(root -> data);

		Node<int>* head = left.first;
		left.second -> next = middle;
		// middle -> next == NULL;

		ans.first = head;				// head would be left.first
		ans.second = middle;		//tail would be middle
		return ans;
	}	
}


pair<Node<int>*, Node<int>*> helper2(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<Node<int>*, Node<int>*>ans;
		ans.first = NULL;
		ans.second = NULL;
		return ans;
	}
	
	pair<Node<int>*, Node<int>*>left = helper2(root->left);
	pair<Node<int>*, Node<int>*>right = helper2(root->right);

	Node<int>* temp = new Node<int>(root->data);

	if(left.first == NULL && left.second == NULL){
		pair<Node<int>*, Node<int>*>ans;
		ans.first = temp;
		ans.second = temp;
		return ans;
	}
	else{
		left.second->next = temp;
		temp->next = right.first;
	}

	pair<Node<int>*, Node<int>*>res;
	res.first = left.first;
	res.second = right.second;

	return res;
}


Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	pair<Node<int>*, Node<int>*> ans = helper(root);
	return ans.first;

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
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
