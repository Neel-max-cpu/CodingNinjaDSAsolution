/*


Problem statement
You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 3000
1 <= |ARR[i]| <=1000

Each string consists of only lowercase letters.

Time limit: 1 sec
Sample Input 1:
2
4
coding codezen codingninja coder
3
night ninja nil 
Sample Output 1:
cod
ni
Explanation of sample input 1:
For the first test case, 
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.

For the second test case,
The longest common prefix among all the given strings is “ni” as it is present as a prefix in all strings. Hence, the answer is “ni”.
Sample Input 2:
2
3
applejuice applepie apple
4
car cus cart carat
Sample Output 2:
apple
c


*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

    

#include<string>
#include <algorithm>

class TrieNode {
   public:
    char data;
    TrieNode **child;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        childCount = 0;
        child = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:

    Trie() {
        root = new TrieNode('\0');
    }

    // HELPER FUNCTION
    void insertHelper(TrieNode* root, string &word)
    {
    TrieNode* cur = root;

    for(int idx = 0; idx < word.size(); ++idx)
    {   
        int diff = word[idx] - 'a';
        
        // If the child[diff] of cur is an empty node
        if (cur->child[diff] == NULL)
        {
            cur->child[diff] = new TrieNode(word[idx]);
            cur->childCount += 1;
        }

        cur = cur->child[diff];
    }

    // Marking the endOfWord of last character as true.
    cur->isTerminal = true;    
    }

    void insert(string s){
        insertHelper(root, s);
    }

    int countChild(TrieNode *root, int *index){
        int count = 0;
        for(int i=0; i<26; i++){
            if(root->child[i] != NULL){
                count++;
                *index = i;
            }
        }
        return count;
    }

    string walkTree(TrieNode *root){
        TrieNode *temp = root;
        int index;
        string s;

        while(countChild(temp, &index) == 1 and temp->isTerminal == false){
            temp = temp->child[index];
            s.push_back('a'+index);
        }
        return s;
    }

    string longestCommonPrefix(vector<string> &arr, int n)
    {
        // Write your code here


        // will work even if we don't create a tree cause we are inside the class itself
        
        // Trie t;
        for(int i=0;i<n; i++){
            // t.insert(arr[i]);
            insert(arr[i]);
            // cout<<arr[i]<<" ";
        }

        // return walkTree(t.root);
        return walkTree(root);


    }
};


    


int main() {
    int t;
    cin>>t;
    while(t--){
    Trie t1;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    cout<<t1.longestCommonPrefix(vect, n)<<endl;
    }
}