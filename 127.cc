// 使用 BFS 的原因：
//  因为要返回最短的路径，如果使用 DFS 那么就要找到所有的路径，然后从
//  这些路径中找到最短的一条。
//  如果使用 BFS，则最先发现的路径就为最短路径。


class Solution {
public:
    struct Elem {
        int step;
        int index;
        Elem(int s, int w): step(s), index(w) {}
    };
    
    vector<vector<int>> make_graph(vector<string>& wordList) {
        vector<vector<int>> G(wordList.size(), vector<int>());
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < wordList.size(); ++j) {
                if (i == j) continue;
                if (transformable(wordList[i], wordList[j])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        return G;
    }
    
    bool transformable(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                cnt++;
        }
        return cnt <= 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<bool> used(n, false);
        queue<Elem> q;
        vector<vector<int>> G = make_graph(wordList);
        int end = 0;
        while (end < wordList.size() && wordList[end] != endWord && ++end);       
        if (end == wordList.size()) return 0;
        
        for (int i = 0; i < wordList.size(); ++i) {
            if (transformable(wordList[i], beginWord)) {
                q.push(Elem(2, i));
                used[i] = true;
            }
        }
        while (!q.empty()) {
            Elem e = q.front();
            q.pop();
            if (e.index == end)
                return e.step;
            for (int nei : G[e.index]) {
                if (!used[nei]) {
                    used[nei] = true;
                    q.push(Elem(e.step+1, nei));
                }
            }
            
        }
        return 0;
    }
};