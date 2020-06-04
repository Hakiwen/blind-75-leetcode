class Solution {
public:
    using mypair = std::pair<int, int>;
    static bool comparator( const mypair &l, const mypair &r){
        return l.first < r.first;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<mypair> vec;
        for(int i=0;i<nums.size();++i){
            vec.emplace_back(nums[i], i);
        }
        // cout << vec[0].first << vec[0].second << endl;
        sort(vec.begin(), vec.end(), Solution::comparator);
        // cout << (*vec.begin()).first << endl;
        auto i = vec.begin();
        auto j = vec.end() - 1;
        // cout << (*i).first << (*j).first << endl;
        int current_sum = i->first + j->first;
        // cout << current_sum << endl;
        while(current_sum != target){
            if(current_sum > target){
                j--;
            }
            else if(current_sum < target){
                i++;
            }
            current_sum = (*i).first + (*j).first;
        }
        int index_i = (*i).second;
        int index_j = (*j).second;
        std::vector<int> ret {index_i, index_j};
        return(ret);
    }
};
