class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> hash;
        map<int, bool>::iterator it;
        vector<int> ret;
        for (int index = 0; index < nums1.size(); ++index) {
            hash[nums1[index]] = false;
        }
        
        for (int index = 0; index < nums2.size(); ++index) {
            it = hash.find(nums2[index]);
            if (it != hash.end() && !it->second) {
                ret.push_back(it->first);
                it->second = true;
            }
        }
        return ret;
    }
    
};