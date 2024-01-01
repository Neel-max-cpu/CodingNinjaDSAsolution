/*

Given the head of a singly linked list of integers, find and return its length.

Example:
Sample Linked List

The length of the list is 4. Hence we return 4.

Note:
Exercise caution when dealing with edge cases, such as when the head is NULL. Failing to handle these edge cases appropriately may result in a runtime error in your code.


Input format :
The first and only line contains elements of the singly linked list separated by a single space, -1 indicates the end of the singly linked list and hence, would never be a list element.


Output format :
Return a single integer denoting the length of the linked list.
Sample Input 1 :
3 4 5 2 6 1 9 -1


Sample Output 1 :
7


Explanation of sample input 1 :
The number of nodes in the given linked list is 7.
Hence we return 7.


Sample Input 2 :
10 76 39 -3 2 9 -23 9 -1

Sample Output 2 :
8


Expected Time Complexity:
Try to do this in O(n).


 Constraints :
0 <= N <= 10^5
Time Limit: 1 sec
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()







*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

int length(Node *head)
{
	//Write your code here

    // edge case
    if(head == NULL) return 0;
    else{
        int n = 0;
        Node *temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        return n;
    }
}


class Runner
{
    int t;
    vector<int>X;
    vector<vector<int>> a;


public:
    Node *takeinput()
    {
        int data;
        cin >> data;
        Node *head = NULL, *tail = NULL;
        while (data != -1)
        {
            Node *newNode = new Node(data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            cin >> data;
        }
        return head;
    }
    void execute(Node *head)
    {
        length(head);
    }

    void executeAndPrintOutput(Node *head)
    {
        cout << length(head) << endl;
    }
};


int main()
{
    Runner runner;
    Node *head = runner.takeinput();
    runner.executeAndPrintOutput(head);
}