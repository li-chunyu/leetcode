class Solution {
public:
    char findTheDifference(string s, string t) {
	char ret;
	for(int index = 0; index<s.size(); ++index)  ret ^=s[index];
	for(int index = 0; index<t.size(); ++index)  ret ^=t[index];
	
	return ret;
    }
};
