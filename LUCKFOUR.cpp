#include <iostream>
using namespace std;

int main () {
	// testcases
	int testc;
	cin >> testc;
	
	while ( testc > 0 ) {
		testc--;
		
		// input
		int N, a, b = 0;
		cin >> N;
		
		// we check every digit
		while ( N > 0 ) {
			a = N % 10;
			b += ( a == 4 )? 1: 0;
			N= N / 10;
		}
		
		// output
		cout << b << "\n";
	}
}
