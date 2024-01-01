/*

Print the following pattern for the given number of rows.
Pattern for N = 4
   1
  212
 32123
4321234
Input format : N (Total no. of rows)

Output format : Pattern in N lines

Sample Input :
5
Sample Output :
        1
      212
    32123
  4321234
543212345
#include<iostream>
using namespace std;

int main(){

  // Write your code here  

  
}







*/

#include<iostream>
using namespace std;

int main(){

  // Write your code here  
  int n;cin>>n;
  int i = 1;
  while(i<=n){
    for(int j=1; j<=n-i; j++) cout<<" ";
    
    // decreasing
    for(int j=i; j>=1; j--) cout<<j;

    // increasing
    int d = 2;
    while(d<=i){
      cout<<d;
      d++;
    }
    cout<<endl;
    // for(int )



    i++;
  }
  
}

