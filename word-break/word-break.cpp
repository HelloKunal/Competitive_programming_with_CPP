class Solution {
public:
    vector<int> memoArray;
    bool wordBreakUtil(unordered_set<string> &dict, string s, int pos) {
        if(pos == s.length()) return true;
        if(memoArray[pos] != -1) return memoArray[pos];
        
        for(int i = pos; i < s.length(); i++) {
            if(dict.find(s.substr(pos, i-pos+1)) != dict.end() && wordBreakUtil(dict, s, i+1)) {
                return memoArray[pos] = true;
            }
        }
        
        return memoArray[pos] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        memoArray.assign(s.length(), -1);
        
        for(string word : wordDict) {
            dict.insert(word);
        }
        
        return wordBreakUtil(dict, s, 0);
    }
};