class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;
        int h;
        while (left < right) {
            max_area = max(min(height[left], height[right]) * (right - left), max_area);
            h = min(height[left], height[right]);
            while (height[left] <= h && left < right) ++left;
            while (height[right] <= h && left < right) --right;
        } 
        return max_area;
    }
};