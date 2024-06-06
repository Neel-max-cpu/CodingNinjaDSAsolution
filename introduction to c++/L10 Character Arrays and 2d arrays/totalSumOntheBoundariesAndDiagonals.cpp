/*

For a given two-dimensional square matrix of size (N x N). Find the total sum of elements on both the diagonals and at all the four boundaries.
ALTIMAGE

Note
You don't have to print anything, just complete the function totalSum and return the answer.
Input format:
First line contains a single integer value, 'N' representing the 'rows' and 'columns' for the two-dimensional square matrix.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format:
First Line contains the single integer denoting the sum.
Constraints:
0 <= N <= 10^3
Time Limit: 1sec
Sample input 1:
3
1 2 3
4 5 6
7 8 9
Sample Output 1:
45
Explanation for Sample Output 1:
The boundary elements are 1, 2, 3, 6, 9, 8, 7 and 4. 

The first-diagonal elements are 1, 5 and 9. 

The second-diagonal elements are 3, 5 and 7.

We just need to add all these numbers making sure that no number is added twice. For example, '1' is both a boundary element and a first-diagonal element similarly, '5' contributes to both the diagonals but they won't be added twice.

Hence, we add up, [1 + 2 + 3 + 6 + 9 + 8 + 7 + 4 + 5] to give 45 as the output.
Sample input 2:
5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
Sample Output 2:
273
int totalSum(int input[][501], int n)
{
     //Write your code here
    // int i = 0, j = 0;
    int sum = 0;

    // BOUNDARIES;
    
    // top 
    for(int i=0; i<n; i++) sum+=input[0][i];
    // bottom
    for(int i=0; i<n; i++) sum+=input[n-1][i];
    // left
    for(int i=0; i<n; i++) sum+=input[i][0];
    // right
    for(int i=0; i<n; i++) sum+=input[i][n-1];


    // DIAGONALS
    int j = 0;

    // left to right(up to bottom)
    for(int i=0; i<n; i++){
        sum+=input[j][i];
        j++;
    }

    // right to left(bottom to up)
    j = n-1;
    for(int i=0; i<n; i++){
        sum+=input[j][i];
        j--;
    }


    sum = sum - 2*(input[0][0] + input[0][n-1] + input[n-1][0] + input[n-1][n-1]);
    if(n%2==1){
        sum -= input[n/2][n/2];
    }

    return  sum;


// others' answer-----
int sum=0;
for (int i = 0; i < n; i++) {
      sum += input[0][i];
      sum += input[n - 1][i];
      sum += input[i][0];
      sum += input[i][n - 1];
      sum += input[i][i];
      sum += input[i][n - 1 - i];
}

sum-=2*(input[0][0]+input[0][n-1]+input[n-1][n-1]+input[n-1][0]);
    
if(n%2!=0){
	sum-=input[n/2][n/2];
}
return sum;



*/

#include <iostream>
using namespace std;

int totalSum(int input[][501], int n)
{
    //Write your code here
    // int i = 0, j = 0;
    int sum = 0;

    // BOUNDARIES;
    
    // top 
    for(int i=0; i<n; i++) sum+=input[0][i];
    // bottom
    for(int i=0; i<n; i++) sum+=input[n-1][i];
    // left
    for(int i=0; i<n; i++) sum+=input[i][0];
    // right
    for(int i=0; i<n; i++) sum+=input[i][n-1];


    // DIAGONALS
    int j = 0;

    // left to right(up to bottom)
    for(int i=0; i<n; i++){
        sum+=input[j][i];
        j++;
    }

    // right to left(bottom to up)
    j = n-1;
    for(int i=0; i<n; i++){
        sum+=input[j][i];
        j--;
    }


    sum = sum - 2*(input[0][0] + input[0][n-1] + input[n-1][0] + input[n-1][n-1]);
    if(n%2==1){
        sum -= input[n/2][n/2];
    }

    return  sum;
    
    
}

int main()
{
	
		int n;
		cin >> n;
		int arr[501][501];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        
        cout << totalSum(arr, n) << endl; 
	
}
