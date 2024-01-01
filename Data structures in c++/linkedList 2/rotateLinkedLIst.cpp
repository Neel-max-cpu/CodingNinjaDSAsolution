/*


You are given a linked list having ‘n’ nodes and an integer ‘k’.


You have to rotate the linked list to the right by ‘k’ positions .


Example :
Input: linked list = [1 2 3 4] , k = 2

Output: 3 4 1 2

Explanation:
We have to rotate the given linked list to the right 2 times. After rotating it to the right once it becomes 4->1->2->3. After rotating it to the right again, it becomes 3->4->1->2. 


Input Format :
The first line of the input contains a single integer 'n', denoting the number of nodes in the linked list.

The next line contains 'n' space-separated integers, denoting the elements of the linked list.

The next line contains an integer ‘k’, representing the number of positions up to the given linked list that has to rotate.


Output Format :
Return the head of the linked list after rotating it.


Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. Elements of your returned linked list will be printed in a single line.


Sample Input 1 :
6
1 2 3 4 5 6
2


Sample Output 1 :
5 6 1 2 3 4


Explanation For Sample Input 1 :
For the first test case, after 1st clockwise rotation the modified linked list will be : 6->1->2->3->4->5
After, 2nd clockwise rotated the modified linked list will be : 5->6->1->2->3->4.
Thus the output is: 5 6 1 2 3 4.


Sample Input 2 :
3
3 6 9 
0


Sample Output 2:
3 6 9


Explanation For Sample Input 2 :
In this test case, ‘k’ is 0 therefore there will be no rotation, so the linked list remains unchanged.


Expected Time Complexity:
Try to do this in O(n).


Constraints :
1 <= n <= 10^5
0 <= Node.data <= 10^9 
0 <= k <= 10^5

Time Limit: 1 sec


/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };







*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.

     if(head == NULL) return head;

     int n = 1;
     Node *temp = head;

     while(temp->next != NULL){
          temp = temp->next;
          n++;
     }

     k = k%n;

     if(k == n || k==0) return head;

     temp->next = head;
     temp = head;

     for(int i = 0; i<abs(n-k-1); i++){
          temp = temp->next;
     }

     head = temp->next;
     temp->next = NULL;

     return head;
}

/*
Node *rotate(Node *head, int k) {
      // If the linked list is empty
    if (head==NULL)
        return head;
 
    // len is used to store length of the linked list
    // tmp will point to the last node after this loop
    Node* tmp = head;
    int len = 1;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        len++;
    }
 
    // If k is greater than the size
    // of the linked list
    if (k > len)
        k = k % len;
 
    // Subtract from length to convert
    // it into left rotation
    k = len - k;
 
    // If no rotation needed then
    // return the head node
    if (k == 0 || k == len)
        return head;
 
    // current will either point to
    // kth or NULL after this loop
    Node* current = head;
    int cnt = 1;
    while (cnt < k && current != NULL) {
        current = current->next;
        cnt++;
    }
 
    // If current is NULL then k is equal to the
    // count of nodes in the list
    // Don't change the list in this case
    if (current == NULL)
        return head;
 
    // current points to the kth node
    Node* kthnode = current;
 
    // Change next of last node to previous head
    tmp->next = head;
 
    // Change head to (k+1)th node
    head = kthnode->next;
 
    // Change next of kth node to NULL
    kthnode->next = NULL;
 
    // Return the updated head pointer
    return head;
}
*/

class Runner
{
    int k;
    vector<int> list;

public:
    void takeLLInput(int n)
    {
        while (n--)
        {
            int x;
            cin >> x;
            list.push_back(x);
        }
    }

    void printLL(Node *head)
    {

        while (head)
        {
            Node *temp = head;
            cout << head->data << ' ';
            head = head->next;
            delete temp;
        }
    }
    void takeInput()
    {
        int n;
        cin>>n;
        takeLLInput(n);
        cin >> k;
    }

    void execute()
    {
        Node *head = nullptr, *cur = nullptr;
        for (auto x : list)
        {
            if (x == -1)
                break;
            Node *temp = new Node(x);
            if (head)
            {
                cur->next = temp;
                cur = cur->next;
            }
            else
            {
                head = temp;
                cur = temp;
            }
        }
        Node *ans = rotate(head, k);
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void executeAndPrintOutput()
    {

        Node *head = nullptr, *cur = nullptr;
        for (auto x : list)
        {
            if (x == -1)
                break;
            Node *temp = new Node(x);
            if (head)
            {
                cur->next = temp;
                cur = cur->next;
            }
            else
            {
                head = temp;
                cur = temp;
            }
        }
        Node *ans = rotate(head, k);
        printLL(ans);
    }
};

int main()
{
    // freopen("testcases/large/in/input11.txt", "r", stdin);
    // freopen("testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}