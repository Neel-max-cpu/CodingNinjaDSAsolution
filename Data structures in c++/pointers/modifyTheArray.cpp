/*

Given an array ar of n integers, find the minimum and maximum value in the array and store their addresses in separate pointer variables. Then, modify the values at the addresses pointed by these pointers setting the minimum value to 0 and maximum value to 100.
Input Format
The first line of input consists of the number of elements of array n.
The second line contains the elements of the array separated by space.
Output format
A single line containing the modified array elements separated by space.
Constraints
 1<= n <=1000
-10^6  ar[i] <=10^6
Note
You don't have to write the entire code. Just complete the definition of modify function listed in the editor.
Sample Input 1
 2
-56 10
Sample Output 1
0 100
Sample Input 2
4
1 2 3 4
Sample Output 2
0 2 3 100
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
void modify(int *ar,int n)
{
	//write your code here

	// METHOD 1
	/*
	int mini = ar[0], maxi = ar[0];
	int mini_x = 0, maxi_x = 0;
	for(int i=1; i<n; i++){
		if(ar[i]>maxi){
			maxi = ar[i];
			maxi_x = i;
		}
		if(ar[i]<mini){
			mini = ar[i];
			mini_x = i;
		}
	}

	*(ar+mini_x) = 0;
	*(ar + maxi_x) = 100;
	*/

	// METHOD 2
	int *mini = ar;
	int *maxi = ar;

	for(int i=1; i<n; i++){
		if(ar[i]<*mini){
			mini = &ar[i];
		}
		if(ar[i]>*maxi){
			maxi = &ar[i];
		}
	}

	*mini = 0;
	*maxi = 100;
	
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