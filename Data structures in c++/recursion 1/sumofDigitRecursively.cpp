/*


Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N
Output format :
Sum of digits of N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
12345
Sample Output 1 :
15
Sample Input 2 :
9
Sample Output 2 :
9
int sumOfDigits(int n) {
    // Write your code here

}








*/


#include <iostream>
using namespace std;

// int fun(int n, int sum){
//     if(n==0) return 0;
//     sum = sum+n%10;
//     n/=10;
//     return fun(n, sum);
// }

int sumOfDigits(int n) {
    // Write your code here
    if(n==0) return 0;
    int temp = n%10;
    return temp + sumOfDigits(n/10);
    // return fun(n, 0);

}




int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
