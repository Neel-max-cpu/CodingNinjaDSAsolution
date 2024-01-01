/*

Print the following pattern for given number of rows.
Input format :

Line 1 : N (Total number of rows)

Sample Input :
   5
Sample Output :
1234554321
1234**4321
123****321
12******21
1********1
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
  for(int i=1; i<=n; i++) cout<<i;
  for(int i=n; i>=1; i--) cout<<i;
  cout<<endl;
  
  int i = 1;
  while(i<=n-1){
    int j = n-i;
    
    // ascending
    for(int k=1; k<=j; k++) cout<<k;

    // stars
    for(int k=1; k<=i*2; k++) cout<<"*";

    // decending
    for(int k=j; k>=1; k--) cout<<k;
    cout<<endl;
    
    i++;
  }
}


