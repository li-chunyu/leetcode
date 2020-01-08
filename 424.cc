class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, max_chfreq = 0, res = 0;
        vector<int> chfreq(26, 0);

        for (int end = 0; end < s.size(); ++end) {
            chfreq[s[end]-'A'] += 1;
            if (max_chfreq < chfreq[s[end]-'A'])
                max_chfreq = chfreq[s[end]-'A'];
            
            while ((end - start + 1) - max_chfreq > k) {
                chfreq[s[start]-'A'] -= 1;
                for (int i = 0; i < 26; ++i) {
                    if (chfreq[i] > max_chfreq)
                        max_chfreq = chfreq[i];
                }
                start++;
            }
            res = max(res, end-start+1);
        }
        return res;
    }
};