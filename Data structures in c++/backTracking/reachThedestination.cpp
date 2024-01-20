/*


Problem statement
Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:

(a, b) -> (a + b, b)
(a, b) -> (a, a + b)
Your task is to find if it is possible to reach the destination point using only the desired moves or not.

For example:
For the coordinates, source point = (1, 1) and destination point = (3, 5)
The output will be true as the destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= x, y <= 3000

Where ‘T’ is the number of test cases and ‘x’, ‘y’ are the coordinates of the given points.

Time Limit: 1sec
Sample Input 1:
2
1 1 3 5
1 1 1 4
Sample Output 1:
True
True
Explanation For Sample Input 1:
For the first test case
The output will be true as destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)

For the second test case
The output will be true as destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (1, 3) -> (1, 4)
Sample Input 2:
2
1 1 2 2
1 1 1 1
Sample Output 2:
False
True



*/



#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include<algorithm>
#include <vector>
using namespace std;

// bool f = false;


bool isValid(int start, int end, int x, int y){
    // if(start>x && end>y) return false;
    // else return true; 
    return (start<=x && end<=y);
}

bool helper(int start, int end, int x, int y){
// void helper(int start, int end, int x, int y){
    // base case
    if(start==x && end==y){
        return true;
        // f = true;
        // return;
    }
    
    bool f = false;

    if(isValid(start+end, end, x, y)){
        f = f || helper(start+end, end, x, y);
        // helper(start+end, end, x, y);
    }
    
    if(isValid(start, end+start, x, y)){
        f = f || helper(start, end+start, x, y);
        // helper(start, end+start, x, y);
    }
    
    return f;

}


bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    // METHOD 1 --- 9/11 TC PASSED -- since more possibility
    // return  helper(sx, sy, dx, dy);
    

    // METHOD 2 --- less possibility
    if (sx==dx and sy==dy){
        return true;
    }
    if (sx>dx or sy>dy){
        return false;
    }
    if(dx>dy){    
        return reachDestination(sx,sy,dx-dy,dy);
    }
    else{
        return reachDestination(sx,sy,dx,dy-dx);
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a>> b>> c>> d;

        
        if(reachDestination(a,b,c,d)){
            cout<< "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
}