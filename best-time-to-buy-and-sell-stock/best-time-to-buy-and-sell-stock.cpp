class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size_p = prices.size();
        vector<int> maxArray(size_p);
        maxArray[size_p-1] = prices[size_p-1];
        for(int i = size_p-2; i >= 0; i--) {
            maxArray[i] = max(prices[i], maxArray[i+1]);
        }
        int sum = 0;
        for(int i = 0; i < size_p; i++) {
            sum = max(maxArray[i]-prices[i], sum);
        }
        return sum;
    }
};