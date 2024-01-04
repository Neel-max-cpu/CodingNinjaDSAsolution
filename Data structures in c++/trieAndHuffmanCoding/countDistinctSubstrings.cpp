/*


Problem statement
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.

Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= |S| <= 10^3

‘S’ contains only lowercase English letters.

Time Limit: 1 sec
Sample Input 1 :
2
sds
abc
Sample Output 1 :
6
7
Explanation of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.
Sample Input 2 :
2
aa
abab
Sample Output 2 :
3
8
Explanation of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }




*/


#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;



#include <string>
#include <algorithm>
#include <set>




class TrieNode{
    public:
        TrieNode *children[26];

        // constructor
        TrieNode(){
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }

        // destructor
        ~TrieNode(){
            for(int i=0; i<26; i++){
                if(children[i]!=NULL){
                    delete children[i];
                }
            }
        }    
};


void insert(string &s, int i, TrieNode *head){
    TrieNode *temp = head;
    int n = s.size();
    while(i<n){
        char ch = s[i];

        if(temp->children[ch-'a'] == NULL){
            // if childnode not present create a child node
            temp->children[ch-'a'] = new TrieNode();
        }
        // move to the child node
        temp = temp->children[ch-'a'];
        i++;
    }
}

int countNodes(TrieNode *root){
    if(root==NULL) return 0;

    int subTreeNodes = 1;
    for(int i=0; i<26; i++){
        subTreeNodes += countNodes(root->children[i]);
    }

    return subTreeNodes;
}


int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    // METHOD
    /*
    set<string>st;
    int n = s.size();
    for(int i=0; i<n; i++){
        string str= "";
        for(int j = i; j<n; j++){
            str = str+s[j];
            st.insert(str);
        }
    }

    return 1+st.size();
    */

    // METHOD 2 --
    // using trie 
    int n = s.size();

    TrieNode *head = new TrieNode();

    for(int i=0; i<n; i++){
        insert(s, i, head);
    }

    int totalNodes = countNodes(head);

    delete  head;

    return totalNodes;
}

class Runner
{
    int t;
    vector<string> arr;

public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            cin >> arr[tc];
        }
    }

    vector<string> getCopy()
    {
        vector<string> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<string> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            int ans = countDistinctSubstrings(arrCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = countDistinctSubstrings(arr[i]);

            cout << ans << endl;
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