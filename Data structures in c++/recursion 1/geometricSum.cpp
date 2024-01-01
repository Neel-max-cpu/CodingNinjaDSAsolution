/*


Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
Note :
using recursion.
Input format :
Integer k
Output format :
Geometric sum (upto 5 decimal places)
Constraints :
0 <= k <= 1000
Sample Input 1 :
3
Sample Output 1 :
1.87500
Sample Input 2 :
4
Sample Output 2 :
1.93750
Explanation for Sample Input 1:
1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500
double geometricSum(int k) {
    // Write your code here

}








*/


#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>

double geometricSum(int k) {
    // Write your code here
    if(k==0) return 1;
    double a = pow(2,k);
    double t = 1/a;
    return t+geometricSum(k-1);
}



using namespace std;

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
