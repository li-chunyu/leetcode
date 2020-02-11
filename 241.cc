// 分治法， 动态规划，漂亮，思想和递归差不多

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        input.push_back('+');
        istringstream ss(input + "+");
        int n = 0;
        char op = ' ';
        while (ss >> n && ss >> op) {
            nums.push_back(n);
            ops.push_back(op);
        }
        int size = nums.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(size, vector<int>()));
        for (int i = 0; i < size; ++i) {
            for (int j = i; j >=0; --j) {
                if (i == j) {
                    dp[j][i].push_back(nums[j]);
                    continue;
                }
                
                for (int k = j; k < i; ++k) {
                    for (auto left : dp[j][k]) {
                        for (auto right : dp[k+1][i]) {
                            if (ops[k] == '+')
                                dp[j][i].push_back(left + right);
                            else if (ops[k] == '-')
                                dp[j][i].push_back(left - right);
                            else
                                dp[j][i].push_back(left * right);
                        }
                    }
                }
            }
        }
        
        return dp[0][size-1];
    }
};



// 分治法

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (ispunct(input[i])) {
                for (int a : diffWaysToCompute(input.substr(0, i))) {
                    for (int b : diffWaysToCompute(input.substr(i+1))) {
                        if (input[i] == '+')
                            res.push_back(a+b);
                        if (input[i] == '-')
                            res.push_back(a-b);
                        if (input[i] == '*')
                            res.push_back(a*b);
                    }
                }
            }
        }
        
        return res.size() != 0 ? res: vector<int>{stoi(input)};
    }
};

