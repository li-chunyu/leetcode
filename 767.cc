// 贪心算法
// 完全没什么思路
// 
// 统计每个字符出现次数并建堆， 然后每次取出出现次数最多的2个元素，比如 a和 b
// 插入结果"ab"
class Solution {
public:
    string reorganizeString(string S) {
      vector<int> count(26, 0);
      for (auto c : S)
        count[c-'a'] += 1;
      
      priority_queue<pair<int, char>> pq;
      for (int i = 0; i < 26; ++i) {
        if (count[i] > (S.size()+1) / 2) return "";
        if (count[i] != 0) 
          pq.push(make_pair(count[i], 'a'+i));
      }
      
      pair<int, char> top1, top2;
      string res = "";
      while (!pq.empty()) {
        top1 = pq.top();
        pq.pop();
        res += top1.second;
        if (!pq.empty()){
          top2 = pq.top();
          pq.pop();
          res += top2.second;
          if (top2.first > 1) pq.push(make_pair(top2.first-1, top2.second));
        }
        if (top1.first > 1) pq.push(make_pair(top1.first-1, top1.second));
      }
      return res;
    }
};