/*

Classroom
Backtracking
profile picture
Problem statement
You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.



Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.



Elements in each combination must be in non-decreasing order.



For example:
Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 8
2 3 5
Sample Output 1:
Yes
Explanation Of Sample Input 1 :
All possible valid combinations are:
2 2 2 2
2 3 3
3 5
Sample Input 2 :
3 5
1 2 3 
Sample Output 2:
Yes
Constraints:
1 <= 'N' <= 15
1 <= 'B' <= 20
1 <= 'ARR[i]' <= 20

Time Limit: 1sec
// #include <vector>
// #include <algorithm>
// using namespace std;


void helper(vector<int>&arr, int b, int index, vector<vector<int>>&ans, vector<int>v, int sum){

    // base case
     if (sum >= b) {
        if (sum == b)



*/



#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

// #include <vector>
// #include <algorithm>
// using namespace std;


void helper(vector<int>&arr, int b, int index, vector<vector<int>>&ans, vector<int>v, int sum){

    // base case
     if (sum >= b) {
        if (sum == b)
            ans.push_back(v);
        return;
    }
    if (index == arr.size())
        return;


    // pick the same index
    v.push_back(arr[index]);                // Include the current element in the combination.
    helper(arr, b, index, ans, v, sum + arr[index]); // Recursively explore combinations including the current element.
    v.pop_back();                           // Backtrack by removing the current element from the combination.

    // pick the next index
    helper(arr, b, index + 1, ans, v, sum);  // Recursively explore combinations without including the current element.

}


void backtracking(int start, vector<int> &row, int sum, vector<vector<int>> &res, vector<int> &v, int target) {
    if (sum >= target) {
        if (sum == target) {
            res.push_back(row);
            // res.emplace_back(row);
        }
        return;
    }
    if (start == v.size())
        return;
    row.push_back(v[start]);
    sum += v[start];
    backtracking(start, row, sum, res, v, target);
    sum -= row[row.size() - 1];
    row.pop_back();
    backtracking(start + 1, row, sum, res, v, target);
}

vector<vector<int>> combSum(vector<int> &ARR, int B) {

    // METHOD 2 ---
    /*
    vector<vector<int>> res;
    vector<int> row, a;
    sort(ARR.begin(), ARR.end());

    a.push_back(ARR[0]);
    for (auto i = 1; i < ARR.size(); ++i)
        if (ARR[i - 1] != ARR[i])
            a.push_back(ARR[i]);

    backtracking(0, row, 0, res, a, B);
    return res;
    */

    // METHOD 1 ---  mine
    vector<vector<int>>ans;
    vector<int>v;
    // sorting is necessary ---
    sort(ARR.begin(), ARR.end());
    helper(ARR, B, 0, ans, v, 0);

    for(auto it:ans){
        for(auto x:it) cout<<x<<" ";
        cout<<"new row"<<endl;
        // cout<<endl;
    }
    // cout<<"answer one down"<<endl;

    return ans;
}


class Runner
{
    int t;

    vector<vector<int>> arr;
    vector<int> B;

public:
    void solve(vector<vector<int>> &res, int currIndex, int currSum, vector<int> &currList, int B, vector<int> &ARR)
    {
        if (currSum == B)
        {
            res.push_back(currList);
            return;
        }
        if (currIndex == ARR.size())
        {
            return;
        }

        solve(res, currIndex + 1, currSum, currList, B, ARR);

        int count = 0;
        while (currSum <= B)
        {
            count++;
            currSum += ARR[currIndex];
            currList.push_back(ARR[currIndex]);
            solve(res, currIndex + 1, currSum, currList, B, ARR);
        }

        while (count--)
        {
            currList.pop_back();
        }
    }

    vector<vector<int>> go(vector<int> &ARR, int B)
    {
        sort(ARR.begin(), ARR.end());
        vector<vector<int>> res;
        vector<int> currList;
        solve(res, 0, 0, currList, B, ARR);
        return res;
    }

    void takeInput()
    {

        t=1;
        B.resize(t);
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n >> B[c];
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
                cin >> temp[i];
            arr.push_back(temp);
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> copy = arr[i];
            vector<vector<int>> res = combSum(copy, B[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> res = combSum(arr[i], B[i]);
            vector<vector<int>> ans = go(arr[i], B[i]);
            sort(ans.begin(), ans.end());
            sort(res.begin(), res.end());
            if (ans == res)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}