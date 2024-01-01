/*

You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of  the longest consecutive sequence is 1, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Explanation:The longest consecutive sequence here is [8, 9, 10, 11, 12]. So the output is the start and end of this sequence: [8, 12].
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation:There are two sequences of equal length here: [1,2,3] and [7,8,9]. But since [7,8,9] appears first in the array (7 comes before 1), we return this sequence. So the output is [7,9].
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
Explanation:The longest consecutive sequence here is [15,16]. So the output is [15,16].

#include <unordered_map>
#include <vector>
#include <algorithm>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here

    // METHOD 1 ---
    /*
    if (n==1){






*/

#include <iostream>
#include <vector>
using namespace std;


#include <unordered_map>
#include <vector>
#include <algorithm>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here

    // METHOD 1 ---
    /*
    if (n==1){
        vector<int>v;
        v.push_back(arr[0]);
        return v;
    }
    else{
        unordered_map<int,bool>m;
        for(int i=0; i<n; i++){
            m[arr[i]] = true;
        }
        int start = arr[0], len = 1;
        // int end = arr[0];
        for(auto it:m){
            int a = it.first;
            if(it.second == true){
                int b = a+1;
                int temp_start = a, temp_end = a, temp_len = 1;
                
                while(m.find(b)!=m.end()){
                    // temp_end = b;
                    temp_len++;
                    m[b] = false;
                    b++;
                }
                
                b = a-1;
                while(m.find(b)!=m.end()){
                    temp_start = b;
                    temp_len++;
                    m[b] = false;
                    b--;
                }

                if(temp_len > len){
                    start = temp_start;
                    // end = temp_end;
                    len = temp_len;
                }
        
                else if(temp_len == len){
                    for(int j=0; j<n; j++){
                        if(arr[j] == start){
                            break;
                        }
                        else if(arr[j] == temp_start){
                            start = temp_start;
                            break;
                        }
                    }
                }
            }
        }

        vector<int>v;
        v.push_back(start);
        v.push_back(start+len-1);

        return v;
    }
    */

    // METHOD 2 
    unordered_map<int,bool>visited;
    unordered_map<int,int>eleToIndex;
    
    for(int i=0; i<n; i++){
        eleToIndex[arr[i]] = i;
        if(visited.count(arr[i]) ==0){
            // if gets repeated, so checking if not present then we add and make it true else skip
            visited[arr[i]] = true;
        }
    }

    int maxLen = 1, startIndex = 0;
    for(int i=0; i<n; i++){
        int a = arr[i];

        int currentMinStartIndex = i;
        int count =0;

        int b = a;
        // go forward
        while(visited.count(b) ==1 && visited[b] == true){
            // is b present in the map and its true 
            // visited.count(b) ==1 is present or not
            visited[b] =  false;
            count++;
            b++;
        }

        // go backward
        b = a -1;
        while(visited.count(b) == 1 && visited[b] == true){
            visited[b] = false;
            count++;
            currentMinStartIndex = eleToIndex[b];
            b--;
        }

        if(count>maxLen){
            maxLen = count;
            startIndex = currentMinStartIndex;
        }
        else if(count == maxLen){
            if(currentMinStartIndex < startIndex){
                startIndex = currentMinStartIndex;
            }
        }
    }

    int start_ele = arr[startIndex];

    vector<int>v;
    v.push_back(start_ele);

    if(maxLen>1){
        v.push_back(start_ele + maxLen -1);
    }
    
    return  v;
}



int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
