/*


Given a singly linked list of integers and position 'i', insert the given node at the 'i-th' position in the linked list recursively.
 Note :
Assume that the Indexing for the linked list always starts from 0.

No need to print the list, it has already been taken care. Only return the new head to the list.
 input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'i'.
The third line of input contains the data of the node to be inserted.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M

Time Limit:  1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
4
Sample Output 1 :
3 4 5 4 2 6 1 9
Sample Input 2 :
2
30 -1
0
2
10 20 30 50 60 -1
5
6
Sample Output 2 :
2 30
10 20 30 50 60 6
Node* InsertNode(Node *head, int pos, Node* newNode)
{
    
   
}





*/

#include <iostream>
#include<stdio.h>


class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

void helper(Node *temp, int pos, Node *newNode){
    if(temp == NULL && pos!=0) return;
    else if(temp != NULL && pos == 0){
        // i save the address of the next ele here, [currect ele hold the address of the next ele]
        Node *address = temp->next;
        // [currect ele hold the address of the next ele], then next address updated to new Node's address
        temp->next = newNode;
        // new Node's next address directed to the next element's address
        newNode->next = address;
        return;
    }
    else
        helper(temp->next, pos-1, newNode);
}


Node* InsertNode(Node *head, int pos, Node* newNode)
{
    // edge case
    if(pos == 0){
        Node *temp = head;
        newNode->next = temp;
        head = newNode;
        return head;
    }

    Node *temp = head;
    helper(temp, pos-1, newNode);
    return head;
   
}

/*  
    Time Complexity : O(n)
    Space Complexity : O(n)
    where n is the size of singly linked list
*/



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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
    
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
        int val;
        cin>>val;
        Node* newNode = new Node(val);
		head = InsertNode(head, pos,newNode);
		print(head);
	}

	return 0;
}