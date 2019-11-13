class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      int G[numCourses][numCourses] = {0};
      int D[numCourses] = {0};
      for (auto p : prerequisites) {
        G[p[0]][p[1]] = 1;
        D[p[1]] += 1;
      }
      int n = numCourses;
      while (n != 0) {
        int zero = -1;
        for (int i = 0; i < numCourses; ++i) {
          if (D[i] == 0) {
            zero = i;
            D[i] = INT_MAX;
            break;
          }
        }
        if (zero == -1)
          return false;
        else {
          for (int i = 0; i < numCourses; ++i) {
            if (G[zero][i] == 1) {
              D[i] -= 1;
            }
          }
        }
        n--;      
      }
      return true;
    }
};