/*


Problem statement
Given n number of words and an incomplete word w. You need to auto-complete that word w.

That means, find and print all the possible words which can be formed using the incomplete word w.

Note : Order of words does not matter.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 1 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"


*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <algorithm>
#include <string>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

      bool search(TrieNode* root, string word) {
        if (word.size() == 0)
            return true;

        if (root->children[word[0] - 'a'] == NULL)
            return false;

        return search(root->children[word[0] - 'a'], word.substr(1));
    }

    bool search(string word) {
        return search(root, word);
    }

    bool isLastNode(TrieNode *root){
        for(int i=0; i<26; i++){
            if(root->children[i]!=NULL) return 0;
        }
        return 1;
    }






    void print_fun(TrieNode *root, string s){
        if(root==NULL) return;
        if(root->isTerminal == true){
            cout<<s<<endl;
            return;
        }
        
        for(int i=0; i<26; i++){
            if(root->children[i]!=NULL){
                string t ="";
                t = s+root->children[i]->data;
                print_fun(root->children[i], t);
            }
        }
    }

   void AutoComplete(TrieNode* root, string s) {
        if (root->isTerminal == true)
            cout << s << endl;

        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                char c = i + 'a';
                AutoComplete(root->children[i], s + c);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here


        // METHOD 1 -BRUTE
        /*
        for(int i=0; i<input.size(); i++){
            string s = input[i];
            string t = s.substr(0,pattern.size());
            if(t==pattern)
                cout<<s<<endl;
        }
        */


        // METHOD 2 ---
        for (int i = 0; i < input.size(); i++) {
            insertWord(input[i]);
        }

        // Search in the trie
        if (!search(pattern)) {
            return;
        }

        string s = pattern;

        while (pattern.size() != 0) {
            root = root->children[pattern[0] - 'a'];
            pattern = pattern.substr(1);
        }

        AutoComplete(root, s);
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}