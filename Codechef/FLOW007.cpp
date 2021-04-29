/*
we reverse the number provided
*/

#include <iostream>

using namespace std;

int main () 
{
	// testcases
	int testc;
	cin >> testc;
	while( testc > 0 )
	{
		testc--;
		
		// input
		long int N;
		cin >> N;
		
		// we store the number digits in an array
		int i=0,A[9],j=0;
		while(N > 0){
			A[i] = N % 10;
			N= N /10;
			i++;
		}
		N=0;
		
		// reform the number
		while(j<i){
			N += A[j];
			N = N * 10;
			j++;
		}
		N=N/10;
		
		// output
		cout<<N<<"\n";
		
	}
}
