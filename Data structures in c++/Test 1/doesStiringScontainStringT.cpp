/*


Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
true or false
Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true
Sample Input 2 :
abcde
aeb
Sample Output 2 :
false
bool checksequenece(char large[] , char*small) {

}






*/


#include<iostream>
using namespace std;

// METHOD 2

bool checksequenece(char large[], char *small) {
    if(small[0] =='\0') return true;
    if(large[0]=='\0') return false;

    if(large[0]==small[0]){
        return checksequenece(large+1, small+1);
    }
    else return checksequenece(large+1, small);

}

// METHOD 1
/*
bool checksequenece(char large[], char *small) {

    // if both's length are 0
    if(small[0]=='\0' && large[0]=='\0') return true;

    // if larger one's turns 0
    else if(small[0]!='\0' && large[0]=='\0') return false;

    // if smaller one's turn 0
    else if(small[0]=='\0' && large[0]!='\0') return true;

    int i = 0;
    for(; large[i]!='\0'; i++){
        if(large[i]==small[0]){
            break;
        }
    }

    if(large[i]=='\0') return false;
    // then call the function again from that i+1 th positon
    return checksequenece(large+i+1, small+1);


}

*/

// bool fun(char a[], int n, char b[], int m, int i){
//     if(n==0) return false;
//     if(i==m) return true;
//     if(a[0]==b[i]){
//         fun(a+1, n-1, b, m, i+1);
//         // if(i==m-1) return true;
//     }
//     else{
//         i=0;
//         fun(a+1, n-1, b, m, i);
//     }
// }



// bool checksequenece(char large[] , char*small) {
//     int n = 0;
//     int i = 0;
//     while(large[i]!='\0'){
//         n++;
//         i++;
//     }

//     i=0;
//     int m = 0;
//     while(small[i]!='\0'){
//         m++;
//         i++;
//     }

//     if(m>n) return false;
//     else if(m==n){
//         if(large==small) return true;
//         else return false;
//     }
//     else{
//         if(fun(large, n, small, m, 0)) return true;
//         else return false;
//     }
// }

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
