/*

Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.
Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.
Input Format:
The first line of input contains an integer N, denoting the total number of days.

The second line of input contains the stock prices of each day. A single space will separate them.
Output Format:
The only line of output will print the span for each day's stock price. A single space will separate them.
Note:
You are not required to print the expected output explicitly. It has already been taken care of. Just store the values of output in the spans array.
Constraints:
0 <= N <= 10^7
1 <= X <= 10^9
Where X denotes the stock's price for a day.

Time Limit: 1 second
Sample Input 1:
4
10 10 10 10
Sample Output 1:
1 1 1 1 
Sample Input 2:
8
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 
void calculateSpan(int prices[], int n, int spans[]) {
    //Write your code here
}






*/


#include <iostream>
#include <stack>
using namespace std;


#include<stack>
#include <algorithm>

void helper(int prices[], int n, int spans[], int m){
    if(m<0) return;

    int count = 1;
    for(int i=m-1; i>=0; i--){
        if(prices[m]>prices[i]) count++;
        else break;
    }
    spans[m] = count;
    // helper(prices, n, spans, m-1);

     for(int i = n-1; i>=0; i--){
        // since there is min of today so count will be min atleast 1
        int count = 1;
        for(int j=i-1; j>=0; j--){
            if(prices[i]>prices[j]) count++;
            else break;
        }
        spans[i] = count;
    }
}

void calculateSpan(int prices[], int n, int spans[]) {
    //Write your code here
    helper(prices, n, spans, n-1);
}

int main() {
    int n;
    cin >> n;

    int* prices = new int[n];
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int* spans = new int[n];
    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}
