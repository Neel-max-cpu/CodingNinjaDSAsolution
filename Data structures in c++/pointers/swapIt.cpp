/*

Take two numbers as input and swap them and print the swapped values by using the concept of functions and pointers.
Input Format:
The first line of input contains a single integer 't', representing the total number of test cases.

The second line of input contains two integers 'a' and 'b', representing the second number. 
Output Format:
For each test case, print the spaces separated swapped values of a and b in a new line.
Constraints:
1 <= 'T' <= 10^2
-10^5 <= 'a', 'b' <= 10 ^ 5

Time Limit: 1 sec
Note
You don't have to print anything .Just complete the definition of the given function.
Sample Input 1:
2
1 2 
3 4
Sample Output 1:
2 1
4 3
Explanation For Sample Input 1:
The output of the above test case is 2 1 for the first test case.
The output of the 2nd test case is 4 3.
Sample Input 2:
2
5 6
7 8
Sample Output 2:
6 5
8 7
Explanation For Sample Input 2:
The output of the above test case is  6 5 for the first test case.
The output of the 2nd test case is 8 7.
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}





*/


#include <iostream>
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        swap(&a , &b);
        cout<<a<<" "<<b;
        cout<<endl;
    }
}