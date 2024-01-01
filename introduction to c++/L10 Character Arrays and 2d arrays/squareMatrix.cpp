/*

#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/

	int m,n; cin>>m>>n;
	int a[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++) cin>>a[i][j];
	}

	int sum = 0;
	for(int j=0; j<n; j++){
		for(int i=0; i<m; i++) sum+=a[i][j];
		cout<<sum<<" ";
		sum = 0;
	}
  
}




*/
#include<iostream>
using namespace std;



void squareMatrix(int n,int arr[][100],int output[]){
    //100 is just the upper limit, you just have to access till n
    int i=0, j=0;
    while(i<n){
        output[i] = arr[i][j];
        i++;
        j++;
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n][100];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int output[n];
    squareMatrix(n,arr,output);
    for(int i = 0;i<n;i++){
        cout<<output[i]<<" ";
    }

}
