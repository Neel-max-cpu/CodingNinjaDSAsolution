/*

For a given two-dimensional integer array of size (N x M), you need to find out which row or column has the largest sum(sum of all the elements in a row/column) amongst all the rows and columns. Return the maximum sum.
Note :
You don't have to print anything just the return largest row/column sum amongst all rows and amongst all columns.
Input Format :
First line contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output Format :
First line contains the largest Sum.
Constraints :
0 <= N <= 10^3
0 <= M <= 10^3
Elements in array range from 1 to 1000
Time Limit: 1sec
Sample Input 1:
6 4
28 26 24 22
21 23 25 27
20 18 16 14
13 15 17 19
12 10 8  6
5  7  11 13  
Sample Output 2:
101
Explanation:
Row Sum are following: 100 96 68 64 36 26
Column Sum are following: 99 99 101 101
So amongst all rows and column 101 is the maximum sum.
int findLargest(int input[][1001], int nRows, int mCols)
{
    
}





*/


#include <iostream>
using namespace std;
#include<climits>


#include <algorithm>


int findLargest(int input[][1001], int nRows, int mCols)
{
    int sum1= 0, max_sum1=0;
    int sum2 = 0, max_sum2 = 0;
    for(int i=0; i<nRows; i++){
        for(int j=0; j<mCols; j++) sum1+=input[i][j];
        max_sum1 = max(max_sum1, sum1);
        sum1 = 0;
    }

    for(int j=0; j<mCols; j++){
        for(int i=0; i<nRows; i++) sum2 += input[i][j];
        max_sum2 = max(max_sum2, sum2);
        sum2 = 0;
    }

    return max(max_sum2, max_sum1);
}

int main()
{
	
		int row, col;
		cin >> row >> col;
		int input[row][1001];
		for (int i = 0; i < row; i++)
		{
			
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		
		cout << findLargest(input, row, col)<<endl;
	
}