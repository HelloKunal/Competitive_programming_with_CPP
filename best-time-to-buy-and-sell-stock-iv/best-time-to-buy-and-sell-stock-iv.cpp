class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size_p = prices.size();
        if(k >= size_p/2) {
            int T_ik0 = 0, T_ik1 = INT_MIN;
            
            int T_ik0_old;
            for(int price : prices) {
                T_ik0_old = T_ik0;
                T_ik0 = max(T_ik0, T_ik1 + price);
                T_ik1 = max(T_ik1, T_ik0_old - price);
            }
            
            return T_ik0;
        }
        
        vector<int> T_ik0(k+1, 0);
        vector<int> T_ik1(k+1, INT_MIN);
        for(int price : prices) {            
            for (int j = k; j > 0; j--) {
                T_ik0[j] = max(T_ik0[j], T_ik1[j] + price);
                T_ik1[j] = max(T_ik1[j], T_ik0[j - 1] - price);
            }
        }
        
        return T_ik0[k];
    }
};