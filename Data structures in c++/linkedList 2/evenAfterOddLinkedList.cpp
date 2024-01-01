/*

For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.
Note :
1. No need to print the linked list, it has already been taken care. Only return the new head to the list.
2. Don't create a new linked list.
3.  Just change the data, instead rearrange the provided list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
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

Node *evenAfterOdd(Node *head){

	//write your code here
	if(head == NULL || head->next == NULL) return head;


	// basically creating new linkedlist odd and even and after odd we are attaching even one

	Node *head_odd = NULL, *tail_odd = NULL;
	Node *head_even = NULL , *tail_even = NULL;
	
	int count_odd = 0, count_even = 0;
	Node *temp = head;
	while(temp!=NULL){
		// EVEN
		if(temp->data %2 == 0){
			Node *newNode = new Node(temp->data);
			if(head_even == NULL){
				head_even = newNode;
				tail_even = newNode;
			}
			else{
				tail_even ->next = newNode;
				tail_even = newNode;
			}
			temp = temp->next;
			count_even++;
		}
		// ODD
		else{
			Node *newNode = new Node(temp->data);
			if(head_odd == NULL){
				head_odd = newNode;
				tail_odd = newNode;
			}
			else{
				tail_odd->next = newNode;
				tail_odd = newNode;
			}
			temp = temp->next;
			count_odd++;
		}
	}
	if(count_odd==0){
		head = head_even;
		return head;
	}
	else if(count_even == 0){
		head  =head_odd;
		return head_odd;
	}
	else{
		head = head_odd;
		tail_odd->next = head_even;
		return head;
	}
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
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}