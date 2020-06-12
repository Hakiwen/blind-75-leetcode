class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = 1;
        suffix[suffix.size() - 1] = 1;
        for(int i=1;i<nums.size();++i){
            prefix[i] = prefix[i -1]*nums[i - 1];
            suffix[nums.size() - i - 1] = suffix[nums.size() - i]*nums[nums.size() - i];
        }
        vector<int> ret(nums.size());
        for(int i=0;i<nums.size();++i){
            ret[i] = prefix[i]*suffix[i];
        }
        return ret;
    }
};
