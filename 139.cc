#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    struct Arc {
      string in;
      int weight;
      int next;
      Arc(string input, int next): in(input) { weight = in.size(); }
    };
  
    struct State {
      int idx;
      int state;
      State(int i, int s): idx(i), state(s){}
    };
  
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<vector<Arc> > adj(2, vector<Arc>());
      int null_start = 0;
      int null_end = 1;
      
      adj[null_end].push_back(Arc("", null_start));
      for (int i = 0; i < wordDict.size(); ++i) {
        adj[null_start].push_back(Arc(wordDict[i], null_end));
      }
      
      int idx = 0;
      stack<State> stack;
      stack.push(State(idx, 0));
      State cur_state(-1, -1);
      bool flag = false;
      while (!stack.empty()) {
        cur_state = stack.top();
        stack.pop();
        if (cur_state.state == 1) {
          if (cur_state.idx >= s.size()) {
            flag = true;
            break;
          } else {
            stack.push(State(cur_state.idx, 0));
            continue;
          }
        }
        
        for (auto arc : adj[0]) {
          if (s.substr(cur_state.idx, arc.in.size()) == arc.in) {
            stack.push(State(cur_state.idx+arc.in.size(), 1));
          }
        }
      }
      return flag;
      
    }
};

//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

int main() {
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  vector<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  Solution sol;
  cout << sol.wordBreak(s,dict) << endl;
  return 0;
}