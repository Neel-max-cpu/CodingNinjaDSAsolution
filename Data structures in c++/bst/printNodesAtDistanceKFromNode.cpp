/*

You are given a Binary Tree of type integer, a integer value of target node's data, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2
alt txt

Starting from the target node 5, the nodes at distance K are 7 4 and 1.
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
Output Format:
All the node data at distance K from the target node will be printed on a new line.

The order in which the data is printed doesn't matter.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.
1 ≤ data of node ≤ 10^9
1 ≤ target ≤ 10^9

Time Limit: 1 sec
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5
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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
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

// https://www.youtube.com/watch?v=f-oTsCUCiXk -----------tutorial

// case 1
void printNodesAtDistanceK(BinaryTreeNode<int>*root , int k){
        if(root == NULL || k<0) return;
        if(k==0){
                cout<<root->data<<endl;
                return;
        }
        printNodesAtDistanceK(root->left, k-1);
        printNodesAtDistanceK(root->right, k-1);
}

int print(BinaryTreeNode<int>*root, int node, int k){
        if(root == NULL) return -1;
        int rootData = root->data;
        if(rootData == node){
                //  basically printing here after the target node that we get ----- case 1 just go down from the target and find which needs to be printed
                // easier case -- eg see 5 with dist 2 , just call in the left and right and sub the dist(k) each time we go if we find k==0 
                // print then return
                // else if we don't get any node or k<0 then also return
                printNodesAtDistanceK(root, k);
                // since we have already printed the subtree node so the distance will be 0 or -1 depending on whether there
                // are valid roots present in the subtree or not
                // in any case whether is valid node available or not is not our lookout, our lookout is that we have gone in the subtree
                // so our k become 0
                // so we return 0 , (since int type and we are returning our dist)
                return 0;
        }

        // case 2 where we have to see above , given eg see 5 is target and print dist at 2, so 1 will also get printed so we need to go reverse
        // i.e.find the dist of all ancestors from target node ---
        // and for all ancestors search other subtree nodes at (k-d) = where k = distance from target node
        int leftSubTreeDist=0,rightSubTreeDist=0;
        
        // check whether the target node is present in the left subtree or not
        leftSubTreeDist=print(root->left,node,k);
        if (leftSubTreeDist!=-1)
        {
            if(leftSubTreeDist+1==k)
            {   
                // that means the current node is at kth distance from our target
                cout<<rootData<<endl;
            }
            // if its not the case then now we have to go toward to right subtree -- cause leftsubtree can also contain right subtree
            else
            {   
                // now since root is our ancestor call in the right subtree
                // right =k-(left+2)  ----- how did 2 come , first we are travelling now in right so +1 and additionally we add +1 to the distance
                rightSubTreeDist=k-(leftSubTreeDist+1)-1;
                printNodesAtDistanceK(root->right, rightSubTreeDist);
            }
            return leftSubTreeDist+1;
        }
        
        // similarly do for right
        rightSubTreeDist=print(root->right , node, k);
        if (rightSubTreeDist!=-1)
        {
            if(rightSubTreeDist+1==k)
            {
                // System.out.println(rootData);
                cout<<root->data<<endl;
            }
            else
            {
                leftSubTreeDist=k-(rightSubTreeDist+1)-1;
                // printNodesAtDistanceK(root.left, leftSubTreeDist);
                printNodesAtDistanceK(root->left, leftSubTreeDist);
            }
            return rightSubTreeDist+1;
        }
        return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    print(root, node, k);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
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
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}