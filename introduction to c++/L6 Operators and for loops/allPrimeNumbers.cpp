/*
Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.
Input Format :
Integer N
Output Format :
Prime numbers in different lines
Constraints :
1 <= N <= 100
Sample Input 1:
9
Sample Output 1:
2
3
5
7
Sample Input 2:
20
Sample Output 2:
2
3
5
7
11
13
17
19

*/

#include <iostream>
using namespace std;

bool check(int n){
	int f= 0;
	for(int i=2; i<n; i++){
		if(n%i==0) {f = 1; break;}
	}

	if(f==1) return false;
	else return true;
}

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
	int n;cin>>n;
	
	for(int i=2; i<=n; i++){
		if(check(i)==true) cout<<i<<endl;
		else continue;
	}
}


