class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int num_int = intervals.size();
        
//         quick exits
        if(num_int == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(intervals[0][0] > newInterval[0] && intervals[num_int - 1][1] < newInterval[1]){
            vector<vector<int> > ret;
            ret.push_back(newInterval);
            return ret;
        } 
        
        
        auto it = intervals.begin();
        bool d = false;
        while(!d && it!=intervals.end()){
            auto this_int = (*it);
            bool a = (*it)[0] <= newInterval[0];
            bool b = (*it)[1] <= newInterval[1];
//             interval completely to the left of new
            bool c = (*it)[1] < newInterval[0];
//             interval not completely to the right of new
            d = (*it)[0] > newInterval[1];
            
            // cout << (*it)[0] << ", " << (*it)[1] << endl;
            // cout << a << b << c << d << endl;
            if(!c && !d){
                if(a){
                    newInterval[0] = (*it)[0];
                }
                if(!b){
                    newInterval[1] = (*it)[1]; 
                }
                intervals.erase(it);
            }
            else{
                ++it;
            }
            
        }
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
        }
        else if(d) {
            intervals.insert(--it, newInterval);
        }
        else{
            intervals.insert(it, newInterval);
        }
        
        // cout << newInterval[0] << "," << newInterval[1] << endl;
        return intervals;
    }
};
