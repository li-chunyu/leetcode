class Solution {
public:
    int findComplement(int num) {
        int bit = 30;
        for (; bit >=0; --bit) {
            if ( (num & (1 << bit)) != 0) {
                break;
            }
        }
        for (; bit >=0; --bit) {
            num ^= (1 << bit);
        }
        return num;
    }
};
