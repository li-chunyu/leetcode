class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for (char c : tasks) {
            if (count.find(c) == count.end())
                count[c] = 1;
            else
                count[c] += 1;
        }
        int n_most_freq = 0, most_freq = 0, idle = 0, n_slots = 0, ret = 0;
        for (auto p : count) {
            if (p.second == most_freq) {
                n_most_freq += 1;
            }
            if (p.second > most_freq) {
                n_most_freq = 1;
                most_freq = p.second;
            }
        }
        n_slots = (n - n_most_freq + 1) * (most_freq - 1);
        idle = max(0, n_slots - (int(tasks.size()) - n_most_freq*most_freq));
        return idle + tasks.size();
    }
};