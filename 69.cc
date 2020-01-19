// 二分查找注意两个问题:
//  1. 区间选择的条件
//  2. 开闭区间选择
// 这里我使用了<左闭右开区间>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 0, r = INT_MAX;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid < (x / mid)) {
                l = mid + 1;
            } else if (mid > (x / mid)) {
                r = mid;
            } else {
                return mid;
            }
        }
        return r - 1;
    }
};