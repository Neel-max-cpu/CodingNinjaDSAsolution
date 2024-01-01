/*


Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)







*/

#include <iostream>

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
/****************************************************************
 
    Following is the class structure of the Node class:

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

*****************************************************************/

class Pair{
	public:
		Node *head;
		Node *tail;
};


Pair reversal(Node *head){
	if(head == NULL || head->next  == NULL){
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}

	Pair smallAns = reversal(head->next);
	smallAns.tail -> next = head;
	head->next = NULL;
	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;
	return ans;
}

Node *reverseLinkedListRec(Node *head)
{	

	// METHOD 4 --- best for recursion
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node *smallAns = reverseLinkedListRec(head->next);

	Node *tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallAns;


	// METHOD 3
	/* pair reversal in this one
	*/
	// return reversal(head).head;


	// METHOD 2
	// time complexity = n^2 ------- 
	/*
	if(head==NULL || head->next == NULL) return head;
	Node *smallAns = reverseLinkedListRec(head->next);

	Node *temp = smallAns;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	
	return smallAns;
	*/


	/*
	// 1 WAY	METHOD 1
	
	if(head == NULL || head->next == NULL) return head;

	Node *smallhead = reverseLinkedListRec(head->next);
	head->next->next = head;
	head->next = NULL;

	return smallhead;
	*/






	// ITERATIVELY ---
	/*
    //Write your code here
	Node *current = head;
	Node *prev = NULL, *next = NULL;

	while(current != NULL){
		// store the next
		next = current->next;

		// point the current's next to prev
		current->next = prev;

		// prev updated
		prev = current;
		current = next;
	}
	// now finally current is null and prev is the last ele so it should be the head, so update the head
	head = prev;
	return head;
	*/
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}