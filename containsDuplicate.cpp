class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> count;
    
        for(int i=0;i<nums.size();++i){
            auto itr = count.find(nums[i]);
            if(itr == count.end()){
                count.insert(std::pair<int, int>(nums[i],1));
            }
            else{
                return true;
            }
        }
        return false;
    }
};
