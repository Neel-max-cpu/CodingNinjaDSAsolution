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
0 <= input[i][j] <10
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
#include <vector>


int totalSum(vector<vector<int>> a, int n)
{   

    if(n == 0){
        return 0;
    }








*/


#include <iostream>
#include<vector>
using namespace std;

#include <vector>


int totalSum(vector<vector<int>> a, int n)
{   

    if(n == 0){
        return 0;
    }

    int diagonals = 0;
    int boundaries = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // CONDITIONS FOR DIAGONALS
            if(i==j || (i+j)==n-1){
                // both for right_to_left(up/down) && left_to_right(up/down)
                diagonals += a[i][j];
            }

            // CONDITON FOR BOUNDARIES
            else if(i==0 || j==0 || i==n-1 || j==n-1){
                boundaries += a[i][j];
            }
        }

    }
    
    return diagonals+boundaries;




    // int boundary_up = 0;
    // int boundary_right = 0;
    // int boundary_down = 0;
    // int boundary_left = 0;

    // // UP
    // for(int i=0; i<n; i++){
    //     boundary_up += input[0][i];
    // }

    // // RIGHT
    //  for(int i=0; i<n; i++){
    //     boundary_right += input[i][n-1];
    // }

    // // DOWN
    //  for(int i=0; i<n; i++){
    //     boundary_up += input[n-1][i];
    // }

    // // LEFT 
    //  for(int i=0; i<n; i++){
    //     boundary_up += input[i][0];
    // }



    // int diagonal_right_up_to_down = 0;
    // int diagonal_left_up_to_down = 0;


    // // UP TO DOWN RIGHT TO LEFT
    // for(int i=0; i<n; i++){
    //     diagonal_right_up_to_down += input[i][i];
    // }

    // // UP TO DOWN LEFT TO RIGHT
    // int j = 0;
    // for(int i=n-1; i>=0; i--){
    //     diagonal_left_up_to_down += input[j][i];
    //     j++;
    // }


    // int total = boundary_up + boundary_down + boundary_left + boundary_right + diagonal_right_up_to_down + diagonal_left_up_to_down;
    // total = total - 2*(input[0][0] + input[0][n-1] + input[n-1][n-1] + input[n-1][0]);

    // return  total;
}

int main()
{
	
		int n;
		cin >> n;
		vector<vector<int>> arr(n,vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        
        cout << totalSum(arr, n) << endl; 
	
}