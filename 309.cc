class Solution {
public:
    int maxProfit(vector<int>& p) {
        if (p.size() == 1 || p.size() == 0)
            return 0;
        int buy = 0, sell = -p[0], reset = INT_MIN;
        for (int i = 1; i < p.size(); ++i) {
            int p_buy = buy;
            buy = max(reset, buy);
            reset = sell + p[i];
            sell = max(p_buy - p[i], sell);
        }
        return max(buy, reset);
    }
};