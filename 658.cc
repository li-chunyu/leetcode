
// \ref https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
// 可以理解为二分搜索序列的开头
// 考虑 arr[mid .. mid+k-1] 和 arr[mid+1 .. mid +k] 两个长度为 k 的窗口,
// 如果 x - arr[mid] 比 arr[mid+k] - x 要大，则说明arr[mid+1 .. mid +k]是更符合要求的窗口
// (因为两个窗口中只有 a[mid] 和 a[mid+k]不同，其余元素均相同。)。
// 若 mid+1 为开头的窗口更好，那么则说明所求最佳窗口开头落在[mid+1, right]之间（因为序列是单调的），所以 left = mid+1。
// 若 mid 为开头的窗口更好，那么则说明所求最佳窗口落在[left, mid]之间，所以 right = mid。
// 
// insight:
//  与其说是在 arr[mid .. mid+k-1] 和 arr[mid+1 .. mid +k] 中选择一个更好的， 不如说是选择一个移动窗口的方向。
//  区别于普通二分查找（查找数字），只需要 key 和 arr[mid] 比较就可以确定方向，而在此题中要通过
//  arr[mid .. mid+k-1] 和 arr[mid+1 .. mid +k] 之间的比较来确定区间移动的方向。
//  由此可见应用二分查找解决问题的关键就是，找到选择区间方向（区间向左还是向右）的策略。
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int left = 0, right = arr.size() - k;
      while (left < right) {
        int mid = (left + right) / 2;
        if (x - arr[mid] > arr[mid+k] - x) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};