/*

Implement the class for Max Priority Queue which includes following functions -


1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.


2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.


3. insert -
Given an element, insert that element in the priority queue at the correct position.


4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.


5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.


Note : main function is given for your reference which we are using internally to test the class.
class PriorityQueue {
    // Declare the data members here

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/







*/

#include <iostream>
using namespace std;



#include <vector>
#include <climits>
class PriorityQueue {
    // Declare the data members here
    vector<int>pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex>0){
            int parent_index = (childIndex-1)/2;
            if(pq[childIndex] > pq[parent_index]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parent_index];
                pq[parent_index] = temp;
            }
            else break;
            childIndex = parent_index;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()) return INT_MAX;
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()) return INT_MAX;

        int ans = pq[0];
        int n = pq.size();
        pq[0] = pq[n-1];
        pq.pop_back();

        int parent_index = 0;
        int leftchild_index = 2*parent_index+1;
        int rightchild_index = 2*parent_index+2;

        while(leftchild_index<n){
            int max_index = parent_index;

            if(pq[max_index] < pq[leftchild_index])
                max_index  = leftchild_index;

            if(rightchild_index<n && (pq[max_index] < pq[rightchild_index]))
                max_index = rightchild_index;

            if(max_index == parent_index) break;

            int temp = pq[parent_index];
            pq[parent_index] = pq[max_index];
            pq[max_index] = temp;

            parent_index = max_index;
            leftchild_index = 2*parent_index + 1;
            rightchild_index = 2*parent_index + 2;
        }

        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}