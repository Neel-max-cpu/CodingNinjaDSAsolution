// question --------
/*
Palindrome Pairs
You are given a list of ‘N’ words ‘WORDS’. Your task is to return all pairs of the distinct indices (i, j) in ‘WORDS’, such that the concatenation of WORDS[i] and WORDS[j] is a palindrome.
For Example:
You are given ‘WORDS’ = [“cat”, “mat”, “tac”]. Then the answer will be [(0, 2), (2, 0)}, because “cat” + “tac” = “cattac” which is a palindrome and “tac” + “cat” = “taccat” which is also a palindrome.
Input Format :
The first line of the input contains a single integer 'T', representing the number of test cases.

The first line of each test case contains an integer ‘N’, representing the number of words in ‘WORDS’.

The next ‘N’ lines contain a String, representing a word of ‘WORDS’’.
Output Format:
For each test case, print all pairs of the distinct indices (i, j) in ‘WORDS’, such that the concatenation of WORDS[i] and WORDS[j] is a palindrome.

Print the output of each test case in a separate line.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
2 <= N <= 1000
0 <= WORDS[i].LENGTH <= 100
WORDS[i] consists of lowercase English letters

Time Limit: 1 sec
Sample Input 1:
2
3
cat
mat
tac
3
ab  
ba
bb
Sample Output 1:
0 2 
2 0
0 1
1 0
Explanation of Sample Input 1:
For the first test case, the answer will be [(0, 2), (2, 0)], because “cat” + “tac” = “cattac” which is a palindrome, and “tac” + “cat” = “taccat” which is also a palindrome.

For the second test case, the answer will be [(0, 1), (1, 0)], because “ab” + “ba” = “abba” which is a palindrome, and “ba” + “ab” = “baab” which is also a palindrome.
Sample Input 2:
2
2
abc 
cba
3
wow
bow 
wob 
Sample Output 2:
0 1
1 0
1 2
2 1
*/



#include <iostream>
#include <vector>
#include <climits>
#include<set>
#include<map>
using namespace std;



// class Node{
//     char data;
//     public:
//     int id = -1;
//     vector<int> PalindromeList;
//     Node* child[26];
//     Node(char data){
//         this->data = data;
//         for(int i=0;i<26;i++){
//             this -> child[i] = NULL;
//         }
//     }
// };

class Node {
public:
    int id;
    vector<int> palindromeList;
    Node* child[26];
    
    Node() : id(-1) {
        fill(begin(child), end(child), nullptr);
    }
};



// bool isPalindrome(string word, int startIndex, int endIndex){
//     int i = startIndex, j = endIndex;
//     while(i < j){
//         if(word[i] != word[j]) return false;
//         i++;
//         j--;
//     }
//     return true;
// }

bool isPalindrome(const string& word, int left, int right) {
    while (left < right) {
        if (word[left] != word[right]) return false;
        ++left;
        --right;
    }
    return true;
}


// void insert(Node* root, string word, int word_idx){
//     Node* p = root;
//     p->id = word_idx; 
//     for(int i=word.size()-1;i>=0;i--){
        
//         if(isPalindrome(word, 0, i)) p->PalindromeList.push_back(word_idx);
//         int idx = word[i] - 'a';
//         if( p->child[idx] == NULL){
//             Node* new_node = new Node(word[i]);
//             p-> child[idx] = new_node;
//         }
//         p=p->child[idx];
//     }
// }


void insert(Node* root, const string& word, int index) {
    Node* node = root;
    for (int i = word.size() - 1; i >= 0; --i) {
        if (isPalindrome(word, 0, i)) {
            node->palindromeList.push_back(index);
        }
        int idx = word[i] - 'a';
        if (node->child[idx] == nullptr) {
            node->child[idx] = new Node();
        }
        node = node->child[idx];
    }
    node->id = index;
    node->palindromeList.push_back(index); // Add the word itself if it's a palindrome.
}

// vector<vector<int>> countPalindromicPairs(vector<string> &words)
// {
//     vector<vector<int>> ans;
//     Node* root = new Node('$');
//     for(int i=0;i<words.size();i++){
//         insert(root, words[i], i);
//     }
//     for(int i=0;i<words.size();i++){
//         string word = words[i];
//         Node* p = root;
//         for(int j=0;j<word.size();j++){
//             if(p->id>=0 && isPalindrome(word, i, word.size()-1)){
//                 vector minians = {i, p->id};
//                 ans.push_back(minians);
//             }
//             int index = word[j] - 'a';
//             p = p-> child[index];
//             if(p==NULL) break;
//         }
//         if(p==NULL) continue;
//         for( int j: p->PalindromeList){
//             if(i != p->PalindromeList[j]){
//                 vector minians = {i, p->PalindromeList[j]};
//                 ans.push_back(minians);
//             }
//         }
//     }
//     return ans;
// }

vector<vector<int>> countPalindromicPairs(vector<string>& words) {
    vector<vector<int>> result;
    Node* root = new Node();
    
    // Insert all words into the trie
    for (int i = 0; i < words.size(); ++i) {
        insert(root, words[i], i);
    }
    
    // Search for pairs
    for (int i = 0; i < words.size(); ++i) {
        Node* node = root;
        for (int j = 0; j < words[i].size(); ++j) {
            // If there's a match and the remainder of the word forms a palindrome
            if (node->id >= 0 && node->id != i && isPalindrome(words[i], j, words[i].size() - 1)) {
                result.push_back({i, node->id});
            }
            int idx = words[i][j] - 'a';
            node = node->child[idx];
            if (node == nullptr) break;
        }
        if (node == nullptr) continue;
        for (int palIndex : node->palindromeList) {
            if (i != palIndex) {
                result.push_back({i, palIndex});
            }
        }
    }
    
    return result;
}





class Runner
{
    int t;
    vector<int> tn;
    vector<vector<string>> twords;  


public:
    void takeInput()
    {
        cin >> t;       
        for (int c = 0; c < t; c++)
        {
           int n;
           cin>>n;
            vector<string> tmp(n);
            for(int i=0;i<n;i++){
                cin>>tmp[i];
            }        

            
            tn.push_back(n);
            twords.push_back(tmp);
            
        }
    }

    void execute()
    {
        

        for (int i = 0; i < t; i++)
        {   
            vector<vector<string>> copytwords = twords;
            vector<vector<int>> ans = countPalindromicPairs(copytwords[i]);           

        }

        
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {   
            vector<vector<int>> ans = countPalindromicPairs(twords[i] );           
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
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
