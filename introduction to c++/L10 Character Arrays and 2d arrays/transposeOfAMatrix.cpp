/*

You are given a matrix ‘MAT’. Print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i].
For example:
Let matrix be : 
1 2
3 4

Then transpose of the matrix will be: 
1 3
2 4
Note:
You don't have to return anything just complete the function and print the final output.
Input Format :
The first line  contains two space-separated integers, ‘M’ and ‘N’, representing the size of the matrices.

The next ‘M’  lines of each test case contain ‘N’ space-separated integers, representing the elements of ‘MAT’.
Output Format :
M lines contains N spaces Integers denoting the transpose of the matrix given.
Constraints :
1 <= M, N <= 3*10^3
0 <= MAT[i][j] <= 10^7

Time Limit: 1 sec
Sample Input 1 :
2 2
1 2
3 4
Sample Output 1 :
1 3
2 4
Explanation For Sample Input 1 :
The transpose of the matrix will be: 
1 3
2 4
Sample Input 2 :
2 3
1 2 3 
3 4 5
Sample Output 2 :
1 3
2 4 
3 5
void transpose(int row,int col,int input[][1001]) {
    
    
}



*/

#include<iostream>
using namespace std;

void transpose(int row,int col,int input[][1001]) {

   int a[col][row];
    for(int i=0; i<row; i++){
        for(int j = 0; j<col; j++){
            a[j][i] = input[i][j];
        }
    }

    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    
}
int main(){
    int row,col;
    cin>>row>>col;
    int input[row][1001];

    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            
            cin>>input[i][j];
        }
    }
    transpose(row,col,input);
}