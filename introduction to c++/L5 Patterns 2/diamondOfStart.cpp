/*
Print the following pattern for the given number of rows.
Note: N is always odd.


Pattern for N = 5



The dots represent spaces.



Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  *

*/

#include<iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int i =1;
    int half = (n/2) + 1;

    // PART 1 ascending part
    while(i<=half){
        int spaces = 1;
        while(spaces <= half-i){
            cout<<" ";
            spaces++;
        }
        int j = 1;
        while(j<=i){
            cout<<"*";
            j++;
        }

        j = i-1;
        while(j>=1){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }

    // PART 2 decending part
    half = n/2;
    i = 1;
    int total = n;
    while(i<=half){
        int spaces = 1;
        while(spaces<=i){
            cout<<" ";
            spaces++;
        }
        total = n-(2*i);
        while(total>0){
            cout<<"*";
            total--;
        }
        cout<<endl;

        i++;
    }















    // int i=1;
    // int half = (n/2) +1;
    // // 1st part---- 
    // while(i<=half){
    //     int spaces = 1;
    //     while(spaces<=half-i){
    //         cout<<" ";
    //         spaces++;
    //     }
    //     int j = 1;
    //     while(j<=i){
    //         cout<<"*";
    //         j++;
    //     }
    //     j = 1;
    //     while(j<=i-1){
    //         cout<<"*";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    // // 2nd part 
    // i = 1;
    // while(i<=n/2){
    //     int spaces = 1;
    //     while(spaces<=i){
    //         cout<<" ";
    //         spaces++;
    //     }
    //     int j = 1;
    //     while(j<=n/2 - i+1){
    //         cout<<"*";
    //         j++;
    //     }
    //     j = n/2 -1;
    //     for(int k=1; k<=j; k++) cout<<"*";
    //     cout<<endl;
    //     i++;
    // }
}