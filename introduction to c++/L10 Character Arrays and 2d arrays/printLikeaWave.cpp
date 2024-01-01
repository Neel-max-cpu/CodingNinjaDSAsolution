/*

For a given two-dimensional integer array of size (N x M), print the array in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.
ALTIMAGE

Input format :
First line  contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output format :
Print the elements of the two-dimensional array in the sine wave order in a single line, separated by a single space.
Constraints :
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1sec
Sample Input 1:
3 4 
1  2  3  4 
5  6  7  8 
9 10 11 12
Sample Output 1:
1 5 9 10 6 2 3 7 11 12 8 4
Sample Input 2:
5 3 
1 2 3 
4 5 6 
7 8 9 
10 11 12 
13 14 15
Sample Output 2:
1 4 7 10 13 14 11 8 5 2 3 6 9 12 15 
void wavePrint(int input[][1001], int nRows, int mCols)
{

}





*/


#include <iostream>
using namespace std;

void wavePrint(int input[][1001], int nRows, int mCols)
{
   int f = 0;
    for(int j=0; j<mCols; j++){
        if(f%2==0){
            for(int i=0; i<nRows; i++) cout<<input[i][j]<<" ";
            f++;
        }
        else{
            for(int i=nRows-1; i>=0; i--) cout<<input[i][j]<<" ";
            f++;
        }
    }
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
		wavePrint(input, row, col);
		cout << endl;
	
}