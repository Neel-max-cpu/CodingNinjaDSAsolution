/*

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
int stringToNumber(char input[]) {
    // Write your code here

}









*/


#include <iostream>
using namespace std;
#include<cstring>
#include <algorithm>
#include <string>




// METHOD 1 -- using recursion
int fun(char a[], int n){
    if(a[0]=='\0'){
        // return n/10;
        return n;
    }

    // if(a[0]=='-') {
    //     fun(a+1, n);
    // }

    n = n*10 + (a[0]-'0');

    // n += a[0]-'0';
    // n*=10;
    
    fun(a+1, n);
}

int stringToNumber(char input[]) {
    // Write your code here
    int i =0;   
    
    return  fun(input,0);
    
}






// METHOD 2

// int stringToNumber(char input[]) {
//     int result = 0;
//     int i = 0;

//     while (input[i] != '\0') {
//         // Check if the character is a valid digit
//         if (input[i] >= '0' && input[i] <= '9') {
//             // Update the result by shifting digits left and adding the new digit
//             result = result * 10 + (input[i] - '0');
//             i++;
//         } else {
//             // Handle invalid input (non-digit character)
//             return 0; // You can choose to return an error code or handle this differently
//         }
//     }

//     // return result
//     return result;
// }






int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
