/*

 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
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

// merging left and right --- from previous quesition
Node *merge(Node *head1, Node *head2){
	
	// edge cases
	if( head2==NULL) return head1; 
	else if(head1==NULL ) return head2;
	else{
		Node *finalHead = NULL;
		Node *finalTail = NULL;
		
		Node *temp1 = head1;
		Node *temp2 = head2;
	
		while(temp1!=NULL && temp2!=NULL){
			// 1st case update both tail and head
			if(finalHead==NULL){
				// head1 is bigger so head2 will go 
				if(temp1->data >= temp2->data){
					finalHead = temp2;
					finalTail = temp2;
					temp2= temp2->next;
				}
				// head2 is bigger so head1 will go 
				else{
					finalHead =  temp1;
					finalTail = temp1;
					temp1= temp1->next;
				}
			}
			// next cases only update the tail
			else{
				if(temp1->data >= temp2->data){
					// update the address
					finalTail->next = temp2;
					// update the whole tail
					finalTail = temp2;
					temp2 = temp2->next;
				}	
				else{
					// update the address
					finalTail->next = temp1;
					// update the whole tail
					finalTail = temp1;
					temp1 = temp1->next;
				}
			}
		}

		// and the remaining
		while(temp1!=NULL){
			// update the address
			finalTail->next = temp1;
			// update the whole tail
			finalTail = temp1;
			temp1= temp1->next;
		}

		while(temp2!=NULL){
			// update the address
			finalTail->next = temp2;
			// update the whole tail
			finalTail = temp2;
			temp2 = temp2->next;
		}

		return finalHead;
	}
}



// finding the mid
Node *find_mid(Node *head){
	Node *slow = head;
	Node *fast = head->next;

	while(fast!= NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


Node *mergeSort(Node *head)
{
	//Write your code here
	
	// edge case
	if(head==NULL) return head;

	else{
		// recursive function
		if(head->next==NULL) return head;

		// finding the middle linked list
		Node *mid = find_mid(head);
	

		// mid's next location would be the next list
		Node *rightLocation = mid->next;
		// and making it null so, we got 2 list now
		mid->next = NULL;

		// recursively calling for left and right
		Node *left  = mergeSort(head);
		Node *right = mergeSort(rightLocation);

		Node *newhead = merge(left, right);

		return newhead;
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}