class Solution {
public:

    void maxprofitfinder(vector<int>& prices,int i,int& minpro,int& maxpro){
        //base case
        if(i==prices.size()){
            return;
        }

        if(prices[i]<minpro){
            minpro=prices[i];
        }
        int todayprofit=prices[i]-minpro;
        if(todayprofit>maxpro){
            maxpro=todayprofit;
        }
    
        maxprofitfinder(prices,i+1,minpro,maxpro);
        
    }

    int maxProfit(vector<int>& prices) {
        int minpro=INT_MAX;
        int maxpro=INT_MIN;
        int i=0;
        maxprofitfinder(prices,i,minpro,maxpro);
        return maxpro;        
    }
};