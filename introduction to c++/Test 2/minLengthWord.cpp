/*


Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.
Input Format :
String S
Output Format :
Minimum length word
Constraints :
1 <= Length of String S <= 10^5
Sample Input 1 :
this is test string
Sample Output 1 :
is
Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a
/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
void minLengthWord(char input[], char output[]){
		
	// Write your code here	

}







*/

#include<iostream>
#include <algorithm>
#include <cstring>

/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
void minLengthWord(char input[], char output[]){
		
	// Write your code here	
    int n = strlen(input);

    int start = 0, end = 0;
    int min_len = n;
    int min_start_index  =0;
    while(end<=n){
        if(end<n && input[end]!=' '){
            end++;
        }
        else{
            int curr_len = end-start;
            if(curr_len<min_len){
                min_len = curr_len;
                min_start_index = start;
            }
            end++;
            start = end;
        }

    }

    for(int i=0; i<min_len; i++){
        output[i] = input[min_start_index++];
    }

	
	

}



using namespace std;


int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
