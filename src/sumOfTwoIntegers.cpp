class Solution {
public:
//     Returns carry, sum
    pair<bool, bool> fullAdder(bool a, bool b, bool c){
        bool carry = (a & b) | (a & c) | (b & c);
        bool sum = (a ^ b) ^ c;
        return pair<bool,bool> (carry, sum);
    }
    
    int getSum(int a, int b) {
        vector<pair<bool,bool> > results(32);
        results[0] = fullAdder(a & 1, b & 1, false);
        int sum = 0;
        sum |= results[0].second;
        for(int i = 1;i<32;++i){
            results[i] = fullAdder((a >> i) & 1, (b >> i) & 1, results[i - 1].first);
            sum |= (results[i].second << i); 
        }
        return sum;
        
    }
};
