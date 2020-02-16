class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) return vector<int>{lo+1, hi+1};
            else if (sum < target) lo += 1;
            else if (sum > target) hi -= 1;
        }
        return vector<int>();
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sec = 0;
        for (int i = 0; i < numbers.size(); ++i)  {
            sec = binarySearch(numbers, target-numbers[i], i+1, numbers.size());
            if (sec != -1) {
                return vector<int>{i+1, sec+1};
            }
        }
        return vector<int>();
    }
    
    int binarySearch(vector<int>& numbers, int target,
                     int start, int end) {
        int mid = 0;
        while (start < end) {
            mid = (start + end) / 2;
            if (numbers[mid] == target)
                return mid;
            else if (numbers[mid] < target)
                start = mid + 1;
            else
                end = mid;
            
        }
        return -1;
    }
};


