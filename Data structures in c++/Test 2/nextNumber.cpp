/*
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;







*/


#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

#include <vector>
#include <algorithm>
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head == NULL) return head;

    Node *temp = head;
    vector<int>v;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }
    reverse(v.begin(), v.end());
    int carry = 0;
    v[0]++;
    if(v[0]==10){
        v[0] = 0;
        carry = 1;
        for(int i=1; i<v.size(); i++){
            v[i] = v[i]+carry;
            if(v[i]==10){
                v[i] = 0;
                carry = 1;
            }
            else break;
        }
        if(carry!=0)  v.push_back(carry);
    }    


    reverse(v.begin(), v.end());

    Node *newHead = NULL, *newTail = NULL;
    int n =v.size();
    int i = 0;
    while(i<n){
        Node *newNode = new Node(v[i]);
        if(newHead == NULL){
            newHead = newNode;
            newTail = newNode;
            i++;
        }
        else{
            newTail->next = newNode;
            newTail = newNode;
            i++;
        }
    }

    return newHead;
}




Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}



