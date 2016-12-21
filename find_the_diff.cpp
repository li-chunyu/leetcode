class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> shash;
        map<char, int> thash;
        for(int char_asc=97; char_asc<=122; ++char_asc){
            shash[char(char_asc)] = 0;
            thash[char(char_asc)] = 0;
        }
        
        for(int index=0;index<s.size(); ++index){
            shash[s[index]] += 1;
        }
        
        for(int index=0; index<t.size(); ++index){
            thash[t[index]] += 1;
        }
        
        for(int char_asc=97; char_asc<=122; ++char_asc){
            if(shash[char(char_asc)] != thash[char(char_asc)])
                return char(char_asc);
        }
        return NULL;
    }
};
