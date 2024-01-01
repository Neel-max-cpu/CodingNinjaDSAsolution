/*


You are given a ‘Binary Tree’.


Return the preorder traversal of the Binary Tree.


Example:
Input: Consider the following Binary Tree:
Example

Output: 
Following is the preorder traversal of the given Binary Tree: [1, 2, 5, 3, 6, 4]


Input Format:
The only line contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image will be:
alt text

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1

Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null(-1).

The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1


Output Format:
Return an array representing the preorder traversal of the given binary tree.


Note :
You do not need to print anything; it has already been taken care of. Just implement the given function.
Sample Input 1:
1 2 3 5 4 6 7 -1 -1 -1 -1 -1 -1 -1 -1


 Sample Output 1:
1 2 5 4 3 6 7


Explanation of Sample Input 1:
The Binary Tree given in the input is as follows:
Sample1

Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1


 Sample Output 2:
5 6 2 3 9 10


Explanation of Sample Input 2:
The Binary Tree given in the input is as follows:
Sample2

Expected Time Complexity:
Try to do this in O(n).


Constraints:
1 <= n <= 100000
where 'n' is the number of nodes in the binary tree.

Time Limit: 1 sec
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;






*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~TreeNode()
	{
		if (left != NULL)
		{
			delete left;
		}
		if (right != NULL)
		{
			delete right;
		}
	}
};

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <vector>
#include <algorithm>

void helper(TreeNode<int>*root, vector<int> &v){
    if(root == NULL) return;

    v.push_back(root->data);
    helper(root->left, v);
    helper(root->right, v);

    // return v;
}

vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.

    vector<int>ans ;
    helper(root, ans);
    return ans;
}


class Runner
{
	int t;
	vector<TreeNode<int> *> allTrees;

	TreeNode<int> *takeTreeInput()
	{

		int rootData;
		cin >> rootData;

		if (rootData == -1)
		{
			return NULL;
		}

		TreeNode<int> *root = new TreeNode<int>(rootData);

		queue<TreeNode<int> *> q;
		q.push(root);

		while (q.empty() == false)
		{
			TreeNode<int> *currentNode = q.front();
			q.pop();
			int leftChild, rightChild;

			cin >> leftChild;

			if (leftChild != -1)
			{
				TreeNode<int> *leftNode = new TreeNode<int>(leftChild);

				currentNode->left = leftNode;
				q.push(leftNode);
			}

			cin >> rightChild;

			if (rightChild != -1)
			{
				TreeNode<int> *rightNode = new TreeNode<int>(rightChild);

				currentNode->right = rightNode;
				q.push(rightNode);
			}
		}

		return root;
	}

	TreeNode<int> *copyTree(TreeNode<int> *root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode<int> *copyRoot = new TreeNode<int>(root->data);
		copyRoot->left = copyTree(root->left);
		copyRoot->right = copyTree(root->right);
		return copyRoot;
	}

public:
	void takeInput()
	{
		t = 1;
		allTrees.resize(t);

		for (int i = 0; i < t; i++)
		{
			allTrees[i] = takeTreeInput();
		}
	}

	void execute()
	{
		for (int i = 0; i < t; i++)
		{
			TreeNode<int> *copyRoot = copyTree(allTrees[i]);

			vector<int> ans = preOrder(copyRoot);

			delete copyRoot;
		}
	}

	void executeAndPrintOutput()
	{
		for (int i = 0; i < t; i++)
		{

			vector<int> ans = preOrder(allTrees[i]);
			for (auto i : ans)
				cout << i << " ";
			cout << '\n';
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("testcases/large/in/input11.txt", "r", stdin);
	// freopen("output11.txt", "w", stdout);
#endif
	Runner runner;
	runner.takeInput();
	runner.executeAndPrintOutput();
	return 0;
}
