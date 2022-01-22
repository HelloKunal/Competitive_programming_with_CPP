// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here
	    if(n == 1 || m == 1) return m;
	    int start = 1, end = m;
	    double eps = 1e-6;
	    int res;
	    while(end > start + 1) {
	        int mid = (start + end) / 2;
	        
	        unsigned long long int nPow = 1;
	        for(int i = 0; i < n; i++) {
	            nPow *= mid;
	            if(nPow > m) {
	                nPow = m+2;
	                break;
	            }
	        }
	        
	        if(nPow == m) {
	            return mid;
	        } else if(nPow < m) {
	            start = mid;
	        } else {
	            end = mid;
	        }
	    }
	    
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends