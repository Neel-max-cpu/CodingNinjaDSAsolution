/*

Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.
#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }







*/

#include <iostream>
#include <climits>
using namespace std;

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here

        // METHOD 1:---
        
        // saving the min ele
        // if(isEmpty()) return isEmpty();
        // else{
        //     int ans = pq[0];
        //     int n = pq.size();
        //     // swaping the last ele and root ele
        //     pq[0] = pq[n-1];
        //     // deleting the last ele
        //     pq.pop_back();

        //     int parent_index = 0;
      
        //     while(parent_index<=n-1){
        //         int leftchild_index = 2*parent_index+1;
        //         int righchild_index = 2*parent_index+2;
        //         // check whether left and right are inside n or not
        //         if(leftchild_index >=n && righchild_index>=n) {
        //             break;
        //         }
        //         else if(leftchild_index>=n && righchild_index<n){
        //             if(pq[parent_index]<pq[righchild_index]){
        //                 int temp = pq[parent_index];
        //                 pq[parent_index] = pq[righchild_index];
        //                 pq[righchild_index] = temp;
        //                 parent_index = righchild_index;
        //                 }
        //             else break;
        //         }
        //         else if(leftchild_index<n && righchild_index>=n){
        //             if(pq[parent_index]<pq[leftchild_index]){
        //                 int temp = pq[parent_index];
        //                 pq[parent_index] = pq[leftchild_index];
        //                 pq[leftchild_index] = temp;
        //                 parent_index = leftchild_index;
        //             }
        //             else break;
        //         }
        //         // both are inside n
        //         else{
        //             if(pq[leftchild_index]>pq[righchild_index]){
        //                 // go right
        //                 if(pq[parent_index]>pq[righchild_index]){
        //                     int temp = pq[parent_index];
        //                     pq[parent_index] = pq[righchild_index];
        //                     pq[righchild_index] = temp;
        //                     parent_index = righchild_index;
        //                 }
        //                 else break;
        //             }
            
        //             else if(pq[leftchild_index]<pq[righchild_index]){
        //                 // go left
        //                 if (pq[parent_index] > pq[leftchild_index]) {
        //                     int temp = pq[parent_index];
        //                     pq[parent_index] = pq[leftchild_index];
        //                     pq[leftchild_index] = temp;
        //                     parent_index = leftchild_index;
        //                 } else
        //                     break;
        //             } else
        //                 break;
        //         }
        //     }
        //     return ans;
        // }

        // METHOD 2:---
        if(isEmpty()) return 0;
        int ans = pq[0];
        int n = pq.size();
        pq[0] = pq[n-1];
        pq.pop_back();
        int parent_index = 0;
        int leftchild_index = 2*parent_index+1;
        int rightchild_index = 2*parent_index+2;
        while(leftchild_index<n){
            int min_index = parent_index;
            if(pq[min_index] > pq[leftchild_index])
                min_index = leftchild_index;
            if(rightchild_index<n){
                if(pq[min_index]>pq[rightchild_index])
                    min_index = rightchild_index;
            }

            if(min_index == parent_index) return ans;

            int temp = pq[parent_index];
            pq[parent_index] = pq[min_index];
            pq[min_index] = temp;

            parent_index = min_index;
            leftchild_index = 2*parent_index+1;
            rightchild_index = 2*parent_index+2;
        }
        return ans;

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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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