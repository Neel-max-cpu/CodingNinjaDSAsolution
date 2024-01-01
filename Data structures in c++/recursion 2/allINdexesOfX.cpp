/*

Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Hint:
Try making a helper function with the required arguments and call the helper function from the allIndexes function.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
Return all the indexes in the output array (in increasing order).
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */

}







*/


#include<iostream>
using namespace std;


int fun(int a[], int n, int x, int b[], int i, int index){
  if(n==0) return i ;

  if(a[0]==x){
    b[i] = index;
    fun(a+1, n-1, x, b, i+1, index+1);
  }
  else{
    fun(a+1, n-1, x, b, i, index+1);
  }
}



int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
   int n = fun(input, size, x, output, 0, 0);
    return n;

}



int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


