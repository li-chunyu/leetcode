class Solution {
public:
     
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ret;
        for (auto iter = people.begin(); iter != people.end(); ++iter) {
                ret.insert(ret.begin()+(*iter)[1], *iter);
        }
        return ret;
    }
};
