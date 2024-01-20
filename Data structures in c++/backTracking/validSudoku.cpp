/*


Problem statement
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).

You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.

A Sudoku solution must satisfy all the following conditions-

1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.
Note
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 5
N = 9
0 <= MATRIX[i][j] <= 9

Where 'N' denotes the size of the given square matrix.

Time Limit: 1sec
Sample Input 1:
1
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
yes
Explanation of the Sample Input1:
One of the possible solutions is:
9 4 1 3 2 6 7 5 8
6 3 7 1 5 8 2 4 9
8 2 5 4 9 7 6 1 3
2 6 8 7 1 4 3 9 5
1 7 4 5 3 9 8 6 2
3 5 9 6 8 2 4 7 1
4 1 3 2 6 5 9 8 7
5 9 6 8 7 3 1 2 4
7 8 2 9 4 1 5 3 6
Sample Input 2:
1
1 5 9 0 0 6 0 3 2
2 7 4 0 0 0 0 0 0
3 8 6 2 0 0 0 0 5
4 9 2 5 0 1 0 8 0
6 3 7 0 4 0 0 0 0
5 1 0 8 2 0 0 0 0
8 2 1 0 0 0 0 0 0
7 6 0 1 0 0 4 2 0
9 4 3 0 7 0 0 6 1
Sample Output 2:
no
Explanation of the Sample Input2:
In the third column from the left, there are two empty cells out of which one has to be filled with ‘8’, but we can’t put 8 in any of those two cells.


*/



#include <iostream>

using namespace std;

#include <unordered_map>

#define n 9


// Working of the map -----
/*

bool isValid(vector<vector<int>>&matrix) {
    int n = 9;
    unordered_map<int, int> row[n], column[n], subMatrix[3][3];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == 0) {
                continue;
            }

            row[r][matrix[r][c]] += 1;
            column[c][matrix[r][c]] += 1;
            subMatrix[r / 3][c / 3][matrix[r][c]] += 1;

            if (subMatrix[r / 3][c / 3][matrix[r][c]] > 1 || column[c][matrix[r][c]] > 1 ||
                row[r][matrix[r][c]] > 1) {
                return false;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Row " << i << ": ";
        for (auto it = row[i].begin(); it != row[i].end(); ++it) {
           cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << endl;
    }

     for (int i = 0; i < n; ++i) {
        cout << "column " << i << ": ";
        for (auto it = column[i].begin(); it != column[i].end(); ++it) {
           cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "SubMatrix[" << i << "][" << j << "]: ";
            // Iterate through the unordered_map
            for (auto it = subMatrix[i][j].begin(); it != subMatrix[i][j].end(); ++it) {
                cout << "(" << it->first << ", " << it->second << ") ";
            }
            cout << endl;
        }
    }


    return true;
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //this is fast I/O (inputput output) use header file <cstdio>
    
    vector<vector<int>>sukodu
    {
       {9, 0, 0, 0, 2, 0, 7, 5, 0 },
       { 6, 0, 0, 0, 5, 0, 0, 4, 0 },
        {0, 2, 0, 4, 0, 0, 0, 1, 0 },
        {2, 0, 8, 0, 0, 0, 0, 0, 0 },
        {0, 7, 0, 5, 0, 9, 0, 6, 0 },
        {0, 0, 0, 0, 0, 0, 4, 0, 1 },
        {0, 1, 0, 0, 0, 5, 0, 8, 0 },
        {0, 9, 0, 0, 7, 0, 0, 0, 4 },
        {0, 8, 2, 0, 4, 0, 0, 0, 6 }
    };

    if(isValid(sukodu)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;


    return 0;

   
    // ouput ---
    // Row 0: (5, 1) (7, 1) (2, 1) (9, 1) 
    // Row 1: (4, 1) (5, 1) (6, 1)
    // Row 2: (1, 1) (4, 1) (2, 1)
    // Row 3: (8, 1) (2, 1)
    // Row 4: (6, 1) (9, 1) (5, 1) (7, 1)
    // Row 5: (1, 1) (4, 1)
    // Row 6: (8, 1) (5, 1) (1, 1)
    // Row 7: (7, 1) (4, 1) (9, 1)
    // Row 8: (6, 1) (4, 1) (2, 1) (8, 1)

    // column 0: (2, 1) (6, 1) (9, 1)
    // column 1: (8, 1) (2, 1) (7, 1) (1, 1) (9, 1)
    // column 2: (2, 1) (8, 1)
    // column 3: (5, 1) (4, 1)
    // column 4: (4, 1) (5, 1) (7, 1) (2, 1)
    // column 5: (5, 1) (9, 1)
    // column 6: (4, 1) (7, 1)
    // column 7: (8, 1) (5, 1) (4, 1) (1, 1) (6, 1)
    // column 8: (4, 1) (6, 1) (1, 1)

    // SubMatrix[0][0]: (2, 1) (6, 1) (9, 1)
    // SubMatrix[0][1]: (4, 1) (5, 1) (2, 1)
    // SubMatrix[0][2]: (1, 1) (4, 1) (5, 1) (7, 1)
    // SubMatrix[1][0]: (8, 1) (7, 1) (2, 1)
    // SubMatrix[1][1]: (9, 1) (5, 1)
    // SubMatrix[1][2]: (4, 1) (1, 1) (6, 1)
    // SubMatrix[2][0]: (2, 1) (8, 1) (9, 1) (1, 1)
    // SubMatrix[2][1]: (4, 1) (7, 1) (5, 1)
    // SubMatrix[2][2]: (6, 1) (4, 1) (8, 1)



    for a 9x9 matrix there are 9 small boxes---
    [0][0]  [0][1]  [0][2]
    9 0 0 | 0 2 0 | 7 5 0 
    6 0 0 | 0 5 0 | 0 4 0 
    0 2 0 | 4 0 0 | 0 1 0 
    -------------------
    [1][0] [1][1]  [1][2]
    2 0 8 | 0 0 0 | 0 0 0 
    0 7 0 | 5 0 9 | 0 6 0 
    0 0 0 | 0 0 0 | 4 0 1
    --------------------
    [2][0]  [2][1]  [2][2]
    0 1 0 | 0 0 5 | 0 8 0 
    0 9 0 | 0 7 0 | 0 0 4 
    0 8 2 | 0 4 0 | 0 0 6
}


*/













bool isValid(int matrix[n][n]) {

    unordered_map<int, int> row[n], column[n], subMatrix[3][3];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == 0) {
                continue;
            }

            row[r][matrix[r][c]] += 1;
            column[c][matrix[r][c]] += 1;
            subMatrix[r / 3][c / 3][matrix[r][c]] += 1;

            if (subMatrix[r / 3][c / 3][matrix[r][c]] > 1 || column[c][matrix[r][c]] > 1 ||
                row[r][matrix[r][c]] > 1) {
                return false;
            }
        }
    }

    

    return true;
}

bool solve(int matrix[n][n], int i, int j) {

    // 2 base cases
    // base case if we reach end
    if (i == n - 1 && j == n) {
        return true;
    }

    // if just j reaches end
    if (j == n) {
        i++;
        j = 0;
    }

    // if not equal to 0 then skip
    if (matrix[i][j] != 0) {
        return solve(matrix, i, j + 1);
    }

    // n = 9 defined above
    for (int digit = 1; digit <= n; digit++) {
        // put from 1 to 9 and check if its valid, if valid then call solve else digit++ and check
        // if none match then put 0 again and come outside and return false
        matrix[i][j] = digit;

        if (isValid(matrix)) {
            if (solve(matrix, i, j + 1)) {
            	return true;
            }
        }

        matrix[i][j] = 0;
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {

    return solve(matrix, 0, 0);
}



int main() {
    int t;
    cin >> t;
    while(t--){
        int matrix[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cin >> matrix[i][j];
        }
        bool ans = isItSudoku(matrix);
        if (ans) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

}
