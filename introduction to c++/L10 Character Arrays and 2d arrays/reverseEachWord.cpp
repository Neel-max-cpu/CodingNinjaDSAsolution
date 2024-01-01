/*

Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed. A word is a combination of characters without any spaces.
Example:
Input Sentence: "Hello I am Aadil"
The expected output will print, "olleH I ma lidaA".
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

All the words in string are separated by a single space.

String does not contain any leading or trailing spaces.

Time Limit: 1 second
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
Sample Input 2:
Always indent your code
Sample Output 2:
syawlA tnedni ruoy edoc
void reverseEachWord(char input[]) {
    // Write your code here
}





*/

#include <iostream>
#include <cstring>
using namespace std;


#include <cstring>

void reverseEachWord(char input[]) {
    // Write your code here
    int n = strlen(input);
    int i = 0;
    int beforespace = 0;
    while(i<n){
        if(input[i]==' '){
            int k =i-1;
            while(k>beforespace){
                char c = input[k];
                input[k] = input[beforespace];
                input[beforespace] = c;
                k--;
                beforespace++;
            }
            beforespace=i+1;
        }
        i++;
    }

    int k=n-1;
    while(k>beforespace){
            char c = input[k];
            input[k] = input[beforespace];
            input[beforespace] = c;
            k--;
            beforespace++;
        }
    
    

}
int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}