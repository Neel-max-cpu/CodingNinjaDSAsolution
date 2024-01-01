/*

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
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


#include <vector>
#include <algorithm>

Node *reverse(Node *head){
	Node *current = head;
	Node *prev = NULL, *next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}


bool isPalindrome(Node *head){
	if(head == NULL) return true;

	Node *current = head;
	int n = 0;

	// creating a new linkedlist
	Node *head_rev = NULL, *tail_rev = NULL;
	while(current!=NULL){
		Node *newNode = new Node(current->data);
		if(head_rev == NULL){
			head_rev = newNode;
			tail_rev = newNode;
		}
		else{
			tail_rev->next = newNode;
			tail_rev = newNode;
		}
		current= current->next;
		n++;
	}

	// reversing the new linked list
	head_rev = reverse(head_rev);

	for(int i=0; i<n/2; i++){
		if(head->data != head_rev->data) return false;
		else {
			head = head->next;
			head_rev = head_rev->next;
		}
	}
	return true;


}



// METHOD 1-------
/*
bool isPalindrome(Node *head)
{
    //Write your code here
	if(head == NULL) return true;

	vector<int>v;
	while(head!=NULL){
		v.push_back(head->data);
		head= head->next;
	}

	int n = v.size();

	for(int i=0; i<n/2; i++){
		if(v[i]!=v[n-i-1]) return false;
	}
	return true;
	
}
*/

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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}