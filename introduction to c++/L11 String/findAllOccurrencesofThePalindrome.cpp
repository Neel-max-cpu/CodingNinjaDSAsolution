/*

Given a string ‘str’ and a pattern ‘pat’, you have to find all occurrences of the pattern in the string. You have to print the starting positions of all occurrences of the pattern in the string.
Input Format:
First line contains the string  'str' and followed by string 'pat'.
Output Format:
All occurrences of patterns starting position separated by space.
Constraints:
1<str.size()<500
1<=pat.size()<=str.size
Sample Input 1:
‘str’ = “heyhihey”
‘pat’ = “hey”
Sample Output 1:
0 5
Explanation:
The pattern has a length of 3. We check each substring of the original string, starting from index 'i', to see if the first three characters match the pattern. If they do, 'i' is considered a valid index.

In the string "heyhihey":

At index 0, the substring "hey" matches the pattern, so 0 is a valid index.

At index 1, the substring "eyh" does not match the pattern, so 1 is not a valid index.

At index 2, the substring "yhi" does not match the pattern, so 2 is not a valid index.

At index 5, the substring "hey" matches the pattern, so 5 is a valid index.

Thus, the valid indices are 0 and 5.
#include<iostream>
#include<string>
using namespace std;

int main(){
    // Write your code here
}





*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    // Write your code here
    string s; cin>>s;
    string p; cin>>p;
    // int n = s.size();
    // int m = p.size();


    // METHOD 1
    /*
   for(int i=0; i<s.size(); i++){
       if(s.substr(i,p.size())==p) {
           cout<<i<<" ";
       }
   }
   */


    // METHOD 2 
    /*
    int n = s.size();
    int m = p.size();
    for(int i=0; i<n; i++){
        if(s[i]==p[0]){
            bool a = true;
            for(int j=0; j<m; j++){
                if(p[j]!=s[i+j]){
                    a = false;
                    break;
                }
            }
            if(a==true) cout<<i<<" ";
        }
    }
    cout<<endl;
    */

    // METHOD 3 using inbuilt function
    
    int pos = s.find(p, 0);
 
    if (pos == string::npos)
        cout << "NONE";
 
    while (pos != string::npos) {
        cout << pos << " ";
        pos = s.find(p, pos + 1);
    }   

}