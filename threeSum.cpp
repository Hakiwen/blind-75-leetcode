class Solution {
public:
    void printVector(const vector<int>& vec){
        int n = vec.size();
        for(int i = 0; i < n;++i){
            cout << vec[i] << ", ";
        }
        cout << endl;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int >> ret;
        printVector(nums);
        int n = nums.size();
        
        if(n < 3){
            return ret;
        }
        
        for(int t = 0; t<n - 2 && nums[t] <= 0;++t){
            int i = t + 1;
            int j = n - 1;
            
            bool processed = false;
            if(t > 0){
                processed = nums[t - 1] == nums[t];
            }
            
            while(i < j && !(t > 0 && processed)){
                int sum = nums[t] + nums[i] + nums[j];
                // cout << t << ", " << i << ", " << j << endl;
                // cout << nums[t] << ", " << nums[i] << ", " << nums[j] << endl;
                // cout << sum << endl;
                if(sum > 0){
                    --j;
                }
                else if(sum < 0){
                    ++i;
                }
                else{
                    vector<int> triplet = {nums[t], nums[i], nums[j]};
                    ret.push_back(triplet);
                    // cout << 'a' << endl;
                    while (i < n && nums[i] == triplet[1]) ++i;
                    // cout << 'b' << endl;
                    while (j >=0 && nums[j] == triplet[2]) --j;
                    
                }
            }
        }
        return ret;
    }
};
