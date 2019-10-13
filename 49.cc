class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        for (auto str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str); 
        }
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            ret.push_back((*iter).second);
        }
        return ret;
    }
};