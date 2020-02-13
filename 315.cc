// merge sort过程中加入计算逆序数的操作
// \ref https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76583/11ms-JAVA-solution-using-merge-sort-with-explanation

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> indexs(nums.size(), 0);
        vector<int> res(nums.size(), 0);
        vector<int> aux(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); ++i)
            indexs[i] = i;
        
        mergeSort(nums, indexs, res, aux, 0, nums.size()-1);
        return res;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& indexs, vector<int>& res,
                   vector<int>& aux, int lo, int hi) {
        if (lo >= hi) return;
        int mid = (lo + hi) / 2;
        mergeSort(nums, indexs, res, aux, lo, mid);
        mergeSort(nums, indexs, res, aux, mid+1, hi);
        merge(nums, indexs, res, aux, lo, mid, hi);
    }
    
    void merge(vector<int>& nums, vector<int>& indexs, vector<int>& res,
               vector<int>& aux, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; ++k)
            aux[k] = indexs[k];
        
        int k = lo;
        int rightcount = 0;
        while (i <= mid && j <= hi) {
            if (nums[aux[i]] <= nums[aux[j]]) {
                indexs[k] = aux[i];
                res[indexs[k]] += rightcount;
                i++;
            } else {
                indexs[k] = aux[j];
                j++;
                rightcount++;
            }
            k++;
        }
        
        while (i <= mid) {
            indexs[k] = aux[i];
            res[indexs[k]] += rightcount;
            k++;
            i++;
        }
        
        while (j <= hi) {
            indexs[k++] = aux[j++];
        }
    }
};