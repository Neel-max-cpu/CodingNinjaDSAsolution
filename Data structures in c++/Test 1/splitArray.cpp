/*

Given an integer array A of size N, check if the input array can be divided in two groups G1 and G2 with following properties-
- Sum of both group elements are equal
- Group 1: All elements in the input, which are divisible by 5 
- Group 2: All elements in the input, which are divisible by 3 (but not divisible by 5). 
- Elements which are neither divisible by 5 nor by 3, can be put in either group G1 or G2 to satisfy the equal sum property. 
Group 1 and Group 2 are allowed to be unordered and all the elements in the Array A must belong to only one of the groups.


Return true, if array can be split according to the above rules, else return false.
Note: You will get marks only if all the test cases are passed.
Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)
Output Format :
true or false
Constraints :
1 <= N <= 50
Sample Input 1 :
2
1 2
Sample Output 1 :
false
Sample Input 2 :
3
1 4 3
Sample Output 2 :
true







*/

#include <iostream>
using namespace std;
bool fun(int *a, int n, int start, int left_sum, int right_sum){
    // if left == right then true(return), else false(return)
    if(start == n) return left_sum == right_sum;

    if(a[start]%5==0) left_sum += a[start];

    // why not %5!=0 , since we are talking about 5 at the start , and if there is eg 15 it will go in 5 gr instead of 3
    else if(a[start]%3==0) right_sum += a[start];

    else{
        // if divisible by none
        // try adding in both and check recursively
        return (fun(a, n, start+1, left_sum+a[start], right_sum) || fun(a, n, start+1, left_sum, right_sum+a[start]));
    }

    return fun(a, n, start+1, left_sum, right_sum);
}


bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return fun(input, size, 0, 0, 0);
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
