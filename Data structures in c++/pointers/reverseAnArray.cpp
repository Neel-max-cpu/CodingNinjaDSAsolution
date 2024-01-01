/*

Given an array ar of n integers, reverse the elements of the array by using the concept of pointers.
Input Format:
Enter a number N and take N more inputs in array ar.
Output Format:
Display values of the reversed array (separated by space)
Constraints
1<= n <=10^6
-10^6<= ar[i] <= 10^6
Note
 You only have to complete the definition of the given function named "reverse". Input has already been taken for you.
Sample Input :
4
1
2
3
4
Sample Output :
4 3 2 1 
#include <iostream>
#include "solution.h"
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





*/

#include <iostream>
void reverse(int *ar,int n)
{
	//write your code here

	// first element
	int *first = ar;
	// last element 
	int *last = ar+n-1;

	while(first<last){
		int temp = *first;
		*first = *last;
		*last = temp;
		first++;
		last--;
	}
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