#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n > flowerbed.size()) return false;
        int left = 0, right = 0;
        int cnt = 0;
        while (left != flowerbed.size()) {
            while (left < flowerbed.size() && flowerbed[left] != 0) left++;
            right = left;
            while (right < flowerbed.size() && flowerbed[right] != 1) right++;
            // 为什么要减2？
            // 如果连续的0串两端被1包围，即”1 0 0 0 1“这种情形，那么靠近1的0是不能放置花的
            // 所以减去两端的0位置，则问题变成考虑长度为(length-2)孤立0串最多能放置多少花（更加简单的问题）
            // 如果左右left 和 right 为 vector 的第一个和最后一个元素，那么他们的外侧一定
            // 没有 1， 所以要加回来（length++）。
            int length = right - left - 2;
            if (right == flowerbed.size()) length++;
            if (left == 0) length++;
            cnt += ((n + 1) / 2);
            left = right;
        }
        return cnt >= n;
    }
};