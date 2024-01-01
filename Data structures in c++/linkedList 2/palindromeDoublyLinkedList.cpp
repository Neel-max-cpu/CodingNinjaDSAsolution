/*

You have been given a head to a doubly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
Note:
There is no requirement for input or output handling. Your task is to implement a function that returns whether the given doubly linked list is a palindrome or not. The nodes in the doubly linked list are connected to its previous nodes using a 'prev' pointer in addition to the usual next pointer.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the doubly linked list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the doubly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
			Node *prev;







*/

#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node* prev;
	Node(int data)
	{
		
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};


/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
			Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
				this->prev = NULL;
	        }
        };

*****************************************************************/
bool palindromeDLL(Node* head){
	// METHOD 2
	if(head == NULL) return true;

	Node *front = head;
	Node *last = head;

	// why n = 1, since we are going till last ele not pointing to null
	int n  =1;
	while(last->next != NULL){
		last = last->next;
		n++;
	}

	n = n/2;
	while(n--){
		if(front->data != last->data) return false;
		else{
			front = front->next;
			last = last->prev;
		}
	}
	return true;
	






	// METHOD 1

	// if(head == NULL) return true;

    // Node *front = head;
    // Node *temp = head;
	// Node *last = NULL;

	// int n = 0;

	// while(temp!=NULL){
	// 	last = temp;
	// 	temp = temp->next;
	// 	n++;
	// }

	// n = n/2;
	// while(n--){
	// 	if(front->data != last->data) return  false;
	// 	else {
	// 		front = front->next;
	// 		last = last->prev;
	// 	}
	// }
	// return true;

}

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
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}



int main()
{
    
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		bool ans = palindromeDLL(head);
		
		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}
	return 0;
}