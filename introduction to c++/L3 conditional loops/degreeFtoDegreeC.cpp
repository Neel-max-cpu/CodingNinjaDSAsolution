/*

Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W), you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values and print the table.
Hint : Use type casting
Input Format :
3 integers - S, E and W respectively 
Output Format :
Fahrenheit to Celsius conversion table. One line for every Fahrenheit and corresponding Celsius value in integer form. The Fahrenheit value and its corresponding Celsius value should be separate by single space.
Constraints :
0 <= S <= 90
S <= E <=  900
0 <= W <= 80 
Sample Input 1:
0 
100 
20
Sample Output 1:
0   -17
20  -6
40  4
60  15
80  26
100 37
Sample Input 2:
20
119
13
Sample Output 2:
20  -6
33  0 
46  7
59  15
72  22
85  29
98  36
111 43
Explanation For Input 2:
Start calculating the Celsius values for each Fahrenheit Value which 
starts from 20. So starting from 20, we need to compute its corresponding
 Celsius value which computes to -6. We print this information as 
 <Fahrenheit Value> <a single space> <Celsius Value> on each line.
  Now add 13 to Fahrenheit Value at each step until you reach 119 
  in this case. You may or may not exactly land on the end value 
  depending on the steps you are taking.

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
	int s,e,w; cin>>s>>e>>w;
	while(s<=e){
		cout<<s<<" ";
		cout<<((s-32)*5)/9<<endl;
		s+=w;
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