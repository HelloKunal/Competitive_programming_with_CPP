// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> res;
    void rec(int n, vector<string>& dict, string s, int i, string temp, string tempres) {
        // debug(s);
        if(i == s.length()) {
            // debug(temp);
            // debug(tempres);
            if(temp == "") {
                res.push_back(tempres.substr(1));
            }
            
            // res.push_back(tempres);
            return;
        }
        
        temp += s[i];
        // debug(temp);
        if(find(dict.begin(), dict.end(), temp) != dict.end()) {
            rec(n, dict, s, i+1, "", tempres+" "+temp);
        }
        
        rec(n, dict, s, i+1, temp, tempres);
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        res.clear();
        rec(n, dict, s, 0, "", "");
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends