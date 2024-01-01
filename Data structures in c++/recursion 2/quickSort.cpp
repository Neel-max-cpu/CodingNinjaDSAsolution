/*


Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements between 'start' and 'end' using quick sort.


Note :
Make changes in the input array itself.
Input format :
Line 1 : Integer N i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7 
Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9






*/


#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;



/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/


void swapping(int a[], int i, int j, int count, int x, int partition_index){
	while(i< partition_index && j>partition_index){
		if(a[i]<=x){
			i++;
		}
		else if(a[j]>x){
			j--;
		}
		else{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	
}

int partitionArray(int a[], int start, int end) {
	// Write your code here

	
	int count = 0;
	// why start+1, since we need to find out the elements smaller than or equal to x[which is a[start] = x]
	for(int i=start+1; i<=end; i++){
		if(a[i]<=a[start]) count++;
	}

	// swap the pos of a[start] to its correct position
	int temp = a[start];
	a[start] = a[count+start];
	a[count+start] = temp;


	int partition_index = count+start;
	// putting the elements correctly on to both side of the partition, i.e ele smaller than x left side, and greater than x right side
	swapping(a,start,end,count,a[partition_index],partition_index);
	
	return partition_index;

}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/

	// base case
	if(start>=end) return;

	int partitionIndex = partitionArray(input, start, end);
	quickSort(input, start, partitionIndex-1);
	quickSort(input, partitionIndex+1, end);
}

class Runner {
    vector<int> v;

public:
    void takeInput() {
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
    }

    void execute() {
        int n = (int)v.size();

        int* input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        free(input);
    }

    void executeAndPrintOutput() {
        int n = (int)v.size();

        int* input = new int[n];
        for (int i = 0; i < n; i++)
            input[i] = v[i];

        quickSort(input, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << input[i] << ' ';
        cout << '\n';

        free(input);
    }
};

int main() {
    // freopen("./Testcases/large/in/input.txt", "r", stdin);
    // freopen("./Testcases/large/out/output.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}