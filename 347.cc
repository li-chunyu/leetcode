    class Solution {
    public:
        struct cmp {
            bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
                return p1.second > p2.second;
            };
        };

        vector<int> topKFrequent(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
            vector<int>::iterator left = nums.begin(), right = nums.begin();
            vector<int> ret;
            while (right != nums.end()) {
                if ((*right) != (*left)) {
                    if (pq.size() >= k) {
                        if (pq.top().second < int(right-left)) {
                            pq.pop();
                            pq.push(make_pair((*left), int(right-left)));
                        }
                    } else {
                        pq.push(make_pair(*left, int(right-left)));
                    }
                    left = right;
                } else {
                    right++;
                }
            }
            if (pq.size() >= k) {
                        if (pq.top().second < int(right-left)) {
                            pq.pop();
                            pq.push(make_pair((*left), int(right-left)));
                        }
                    } else {
                pq.push(make_pair((*left), int(right-left)));
            }
            while (pq.size() != 0) {
                ret.push_back(pq.top().first);
                pq.pop();
            }
            sort(ret.begin(), ret.end());
            return ret;
        }

    };