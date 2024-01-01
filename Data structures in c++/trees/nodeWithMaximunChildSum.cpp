/*

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
0 < Node's val <= 10^5
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0


Sample Output 1 :
1
/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;







*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

#include <climits>

int findsum(TreeNode<int>*root){
    int sum =root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += root->children[i]->data;
    }
    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here

    if(root==NULL) return NULL;

    int sumRoot = findsum(root);
    int maxi = INT_MIN;
    TreeNode<int>*maxNode = NULL;
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>*maxNode1 = maxSumNode(root->children[i]);
        int sum = findsum(maxNode1);
        if(sum>maxi){
            maxi = sum;
            maxNode = maxNode1;
        }
    }

    if(sumRoot>maxi) return root;
    else return maxNode;


    
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}