/*


Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<=|S|<=50

// Change in the given string itself. So no need to return or print anything

void replacePi(char input[]) {
	// Write your code here

}









*/


#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print anything
#include <cstring>

void fun(char a[], int i){
	// base case
	if(a[i]=='\0' || a[i+1]=='\0') return;




	if(a[i]=='p' && a[i+1]=='i'){
		for(int j = strlen(a); j>=i+2; j--){
			a[j+2] = a[j];
		}
		a[i] = '3';
		a[i+1] = '.';
		a[i+2] = '1';
		a[i+3] = '4';		

		// here just increasing by 1 to make more efficient increase it to i+2, or something like that
		fun(a, i+1);
	}
	else 
		fun(a, i+1);
	
}


void replacePi(char input[]) {
	// Write your code here
	
	// METHOD 1
	// fun(input, 0);


	// METHOD 2
	// base case
	if(input[0]=='\0' || input[1]=='\0') return; 

	if(input[0]!='p' || input[1]!='i') replacePi(input+1);
	else{
		// we need to make space for 2 characters, since 3.14 has 4chars, and we got 2 , at 0 and 1th pos
		int lastIndex = 0;
		while(input[lastIndex]!='0') lastIndex++;

		while(lastIndex>=2){
			input[lastIndex+2] = input[lastIndex];
			lastIndex--;
		}
		input[0] = '3';
		input[1] = '.';
		input[2] = '1';
		input[3] = '4';

		replacePi(input+4);
	}
}




int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
