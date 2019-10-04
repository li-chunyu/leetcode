/// ref https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation
/// STL implementation.

class Solution {
public:
    typedef vector<int>::iterator Iter;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        ret.push_back(nums);
        bool has_next;
        while ((has_next = nxt_permutation(nums.begin(), nums.end())) == true) {
            ret.push_back(nums);
        }
        return ret;
    }
    bool nxt_permutation(Iter first, Iter last) { // [first, last)
        if (first == last) return false; // empty.
        Iter i = first;
        ++i;
        if (i == last) return false; // only one element.
        i = last;
        --i;
        while (true) {
            Iter ii;
            ii = i;
            --i;
            if (*i < *ii) {
                Iter j = last;
                while (!(*i < *--j));
                iter_swap(i, j);
                reverse(ii, last);
                return true;
            }
            if (i == first) {
                reverse(first, last);
                return false;
            }
        }
    }
};