class Solution {
public:
    int climbStairs(int n) {
        if(!n){
            return 0;
        }
        else if (n == 1){
            return 1;
        }
        else{
            int current_paths;
            map <int, int> path_map;
            path_map.insert(pair<int,int>(0, 1));
            path_map.insert(pair<int,int>(1, 1));
            for(int i=2; i < n + 1;++i){
                
                current_paths = path_map.at(i - 2) + path_map.at(i - 1);
                path_map.insert(pair<int, int>(i, current_paths));
        }
            return path_map.at(n);
        }
        

    }
};
