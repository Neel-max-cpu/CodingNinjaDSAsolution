/*
Write a program that generates a multiplication table for a given integer.
Input Format :
A single integer, n, where 0 <= n <= 10,000.
Output Format :
The first 10 multiples of n, each printed on a new line.
Constraints :
The input integer n is non-negative and less than or equal to 10,000.

Note: The program should take an integer as input and print the first 10 multiples of the input integer. Each multiple should be printed on a new line. The program should not print anything else. The program should handle the case where the input integer is 0. In this case, the program should print ten lines of 0. The program does not need to handle invalid input. It can assume that the input will always be a valid integer within the specified constraints.

Sample Input 1 :
2
Sample Output 1 :
2
4
6
8
10
12
14
16
18
20
Sample Input 2 :
5
Sample Output 2 :
5
10
15
20
25
30
35
40
45
50



*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long int
const unsigned int mod = 1e9+7;


//(x^y)%mod, use to calculate mod power
// O(log n) -- return  , stl power function O(n)
//power function
int Modpower(int a, int b){
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll res = 1;
    while(b){
        if(b%2==0){
            ll ans = Modpower(a,b/2);
            return (ans*ans)%mod;
        }
        else{
            ll ans = Modpower(a,(b-1)/2);
            return ((a*ans)%mod *ans)%mod;
        }
    }
    return res;
}

void sol(){
	int n;cin>>n;
	int i=1; 
	while(i<=10){
		cout<<i*n<<endl;
		i++;
	}
    
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //this is fast I/O (inputput output) use header file <cstdio>
    // ll t;cin>>t;
    // while(t--){
        sol();
    // }
    return 0;
}