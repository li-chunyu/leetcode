class Solution {
public:
    
    typedef pair<int, pair<int, int>> Elem;

    // Stl 比较器返回 true 表示要进行调整
    // 返回 false 表示关系符合要求不需要调整
    struct cmp {
        bool operator()(const Elem& a, const Elem& b) {
            return a.first > b.first;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Elem, vector<Elem>, cmp> pq;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        
        int count = 0, res = 0;
        while (!pq.empty()) {
            Elem e = pq.top();
            pq.pop();
            count++;
            res = e.first;
            if (count == k) break;
            
            if (e.second.second < n - 1) {
                e.second.second += 1;
                e.first = matrix[e.second.first][e.second.second];
                pq.push(e);
            }
        }
        return res;
    }
};