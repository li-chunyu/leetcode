/* i&(i-1) 的二进制比 i 少一位1，
 * 比如, 14->1110 13=1101, 那么 14&13=1100 (这是因为
 * i-1 对 i 的二进制产生的影响是，i 的二进制的从右侧开始的
 * 第一个 1 变成 0，这个 1 之后的 0 全部变成 1，所以 i-1 与 i
 * 进行与操作时得到的结果是 i 最右侧的 1 变成 0，即比 i 的二进制表示少一个 1)
 *  又 i&(i-1) 比 i 小，所以求 i 的二进制 1 的个数时，i&(i-1)的 1 的个数为已知
 * ，故 i&(i-1) 的 1 的个数加 1 就是 i 的 1 的个数。
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i) {
            ret[i] = ret[i&(i-1)] + 1;
        }
        return ret;
    }
};