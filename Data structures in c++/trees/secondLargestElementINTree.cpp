/*


Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. Also, value of data at each level is distinct.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
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
#include <climits>
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
#include <queue>


// METHOD 1 ---------------
/*
bool flag = true;
bool checkSimilar(TreeNode<int>*root){
    for(int i=0; i<root->children.size(); i++){
        if(root->data != root->children[i]->data){
            flag = false;
            return flag;
        }
        else{
            checkSimilar(root->children[i]);
        }
    }
    return flag;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    
    if(root == NULL) return NULL;

    // edge case check if all the nodes are equal or not if yes NULL else continue -----
    if(checkSimilar(root) == true) return NULL;
    else {
        int childCount = root->children.size();
        if(childCount == 0) return NULL;
        TreeNode<int> *largest = root, *secondLargest = root->children[0];
        if(largest->data < secondLargest->data){
            secondLargest = root;
            largest = root->children[0];
        }
  
    

        queue<TreeNode<int>*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode<int>*curr = q.front();
            q.pop();
            childCount = curr->children.size();
            for(int i=0; i<childCount; i++){
                q.push(curr->children[i]);
                if(curr->children[i]->data > secondLargest->data){
                    if(curr->children[i]->data > largest->data){
                    secondLargest = largest;
                        largest = curr->children[i];
                    }
                    else {
                        secondLargest = curr->children[i];
                    }
                }
            }
        }
        return secondLargest;
    }
}
*/



// METHOD 2 ----------
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) return NULL;
    int childCount = root->children.size();
    if(childCount == 0) return NULL;
    
    TreeNode<int> *largest = root;
    // or don't initiallize the second largest ------------
    TreeNode<int> *secondLargest = new TreeNode<int>(INT_MIN);
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>*curr = q.front();
        if(curr->data > largest->data){
                    secondLargest = largest;
                    largest = curr;                
            }else if(curr->data!=largest->data&&curr->data>secondLargest->data){
                secondLargest = curr;
            }
        q.pop();
        childCount = curr->children.size();
        for(int i=0; i<childCount; i++){
            q.push(curr->children[i]);
        }
    }
    // if secondLargest == INT_MIN return Null else return second largest
    return secondLargest->data==INT_MIN?NULL:secondLargest;
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}