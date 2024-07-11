/*

Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.
Input Format :
Integer n
Output Format :
Numbers from 1 to n (separated by space)
Constraints :
1 <= n <= 10000
Sample Input 1 :
 6
Sample Output 1 :
1 2 3 4 5 6
Sample Input 2 :
 4
Sample Output 2 :
1 2 3 4
void print(int n){
    //write your code here
}







*/


#include<iostream>
using namespace std;

void fun(int n, int i){
    if(i>n) return;
    cout<<i<<" ";
    fun(n,i+1);
}



void print(int n){
    //write your code here
 // METHOD1 ---
    fun(n,1);
    // return;
 // METHOD2 ---
 if (n > 0) {
        print(n - 1);  // Recursive call before printing
        cout << n << " ";
    }
}


int main(){
    int n;
    cin >> n;
  
    print(n);
}


