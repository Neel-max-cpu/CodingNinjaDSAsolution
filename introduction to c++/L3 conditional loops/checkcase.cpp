/*

Write a program that takes a character as input and prints 1, 0, or -1 according to the following rules.


1, if the character is an uppercase alphabet (A - Z).
0, if the character is a lowercase alphabet (a - z).
-1, if the character is not an alphabet.


Example:
Input: The character is 'a'.

Output: 0

Explanation: The input character is lowercase, so our answer is 0.
Input format :
The only line contains a single character.


Output format :
The only line contains 1, 0, or -1 according to the above rules.
Sample Input 1 :
v


Sample Output 1 :
0


Explanation of Sample Input 1:
The input character is lowercase, so our answer is 0.


Sample Input 2 :
V


Sample Output 2 :
1


Explanation of Sample Input 2:
The input character is uppercase, so our answer is 1.


Sample Input 3 :
#


Sample Output 3 :
-1


Explanation of Sample Input 3:
The input character is not an alphabet, so our answer is -1.


Constraints :
The input can be any single character.



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
	char a;
	cin>>a;
	if(a>='a' && a<='z') cout<<0;
	else if(a>='A' && a<='Z') cout<<1<<endl;
	else cout<<-1;
    
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