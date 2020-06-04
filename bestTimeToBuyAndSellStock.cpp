class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int gain_max = 0;
        size_t len_prices = prices.size();
        
        if(len_prices < 2){
            return gain_max;
        }
        int min_price = prices[0];
        
        for(int i = 0; i<len_prices;++i){
            if(prices[i] - min_price > gain_max){
                gain_max = prices[i] - min_price;
            }
            if(prices[i] < min_price){
                min_price = prices[i];
            }
        }

        return gain_max;
    }
};
