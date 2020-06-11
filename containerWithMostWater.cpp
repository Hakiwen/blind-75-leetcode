class Solution {
public:
    int maxArea(vector<int>& height) {
       
        size_t numH = height.size();
        int minW = 1;
        int maxArea = 0;
        int level = 0;
        
        int i = 0;
        int j = numH - 1;
        while(i < numH - minW && j >= i + minW){
            int currentHeight = min(height[i],height[j]);
            if(currentHeight > level){
                level = currentHeight;
                maxArea = max(maxArea, currentHeight*(j - i));
            }
            if(height[i] < height[j]){
                ++i;
            }
            else{
                --j;
            }
            
        }
        return maxArea;
    }
};
