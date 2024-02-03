/*


Problem statement
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51

#include<vector>
#include<algorithm>
using namespace std;

int helper(int *weights, int *values, int n, int maxWeight, int i){
	// base case
	if(i==n || maxWeight==0){
		return 0;
	}


*/


#include <iostream>
using namespace std;


#include<vector>
#include<algorithm>
using namespace std;

int helper(int *weights, int *values, int n, int maxWeight, int i){
	// base case
	if(i==n || maxWeight==0){
		return 0;
	}

	// pick the weight
	int a = 0, b = 0;
	if(maxWeight-weights[i]>=0){
		a = values[i] + helper(weights, values, n, maxWeight-weights[i], i+1);
	}

	// don't pick the weigh
	b = helper(weights, values, n, maxWeight, i+1);

	return max(a,b);
}

int helper_rec(int *weights, int *values, int index, int maxWeight){
	// base case
	if(index == 0 || maxWeight == 0) return 0;

	// pick 
	int take = 0, notTake  = 0;
	if(maxWeight - weights[index] >=0){
		take = values[index] + helper_rec(weights, values, index-1, maxWeight-weights[index]);
	}

	// not pick
	notTake =  helper_rec(weights, values, index-1, maxWeight);

	return max(take, notTake);
}


int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	
	// recursion ---
	/*
	int ans = helper(weights, values, n, maxWeight, 0);
	return ans;
	*/


	// recursion --- method 2
	int ans = helper_rec(weights, values, n-1, maxWeight);
	return ans;

}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}