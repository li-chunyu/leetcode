class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
        unorded_map<int, int> map;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (map.find(A[i] + B[j]) == map.end()) {
                    map[A[i]+B[j]] = 1;
                } else {
                    map[A[i]+B[j]] += 1;
                }
            }
        }

        int n = 0, sum = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                sum = C[i] + D[j];
                if (map.find(-sum) != map.end())
                    n += map[-sum];
            }
        }
        return n;
    }
};