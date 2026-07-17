class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        int left = 0;
        int right = n-1;
        while(left < right){
            int h = min(heights[left], heights[right]);
            int w = right - left;
            max_area = max(max_area, h*w);
            
            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return max_area;
    }
};
