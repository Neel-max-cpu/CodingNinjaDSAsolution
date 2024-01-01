/*

You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.


A cycle occurs when a node's next points back to a previous node in the list.


Example:
In the given linked list, there is a cycle, hence we return true.
Sample Example 1

Input format :
The first line of each test case contains the elements of the singly linked list separated by a single space and terminated by -1. Hence -1 would never be a list element.


The second line contains the integer position 'pos', representing the position (0-indexed) in the linked list where the tail connects. If 'pos' is -1, there is no cycle in the linked list.


Output format :
The only output line contains 'true' if the linked list has a cycle or 'false' otherwise.


Note :
You don't have to print by yourself explicitly. It has been taken care of.
Sample Input 1 :
1 2 3 4 -1
1


Sample Output 1 :
true


Explanation of Sample Input 1:
The linked list given in the input is as follows:
Sample Input 1

Sample Input 2 :
1 2 3 4 -1
0


Sample Output 2 :
true


Explanation of Sample Input 2:
The linked list given in the input is as follows:
Sample Input 2

Sample Input 3 :
5 -1
-1


Sample Output 3 :
false


Explanation of Sample Input 3:
 The linked list given in the input is as follows:
Sample Input 3

Expected Time Complexity:
Try to solve this problem in O(n).


Expected Space Complexity:
Try to solve this problem in O(1).


Constraints :
0 <= n <= 10^6
-1 <= pos < n
-10^9 <= data <= 10^9 and data != -1

Where 'n' is the size of the singly linked list, 'pos' represents the position (0-indexed) in the linked list where the tail connects to, and 'data' is the Integer data of the singly linked list.

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

#include <set>
#include <algorithm>


bool detectCycle(Node *head)
{

    if(head == NULL || head->next == NULL) return false;

    Node *slow = head, *fast = head->next;

    while(slow != fast){
        if(fast == NULL || fast->next == NULL) return false;
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;


}


/*

bool detectCycle(Node *head)
{
	//	Write your code here
    if(head == NULL || head->next==NULL) return false;


    // use the set , and set it to Node * , 
    // i used int so, it gave error
    set<Node *>s;

    while(head!=NULL){
        if(s.find(head) != s.end()) return true;

        s.insert(head);
        head = head ->next;
    }
    return false;

}

*/

class Runner
{
    int t;
    vector<Node *> arr;

public:
    Node *takeInput()
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

        int pos;
        cin >> pos;

        if (pos != -1)
        {

            Node *temp = head;
            //  Connecting last element to "pos"th node
            while (pos--)
            {
                temp = temp->next;
            }
            tail->next = temp;
        }

        return head;
    }

    void execute(Node *head)
    {
        bool ans = detectCycle(head);
    }

    void executeAndPrintOutput(Node *head)
    {
        bool ans = detectCycle(head);
        if (ans)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Runner runner;
    Node *head = runner.takeInput();
    runner.executeAndPrintOutput(head);

    return 0;
}

