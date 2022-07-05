//题解详见知乎博客
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int ans = min(height[l], height[r])*(r-l);
        while(l<r) {
            if(height[l]<height[r]) {
                l++;
                int size = (r-l)*min(height[l], height[r]);
                ans = max(ans, size);
            } else {
                r--;
                int size = (r-l)*min(height[l], height[r]);
                ans = max(ans, size);
            }
        }
        return ans;
    }
};