class Solution {
    public:
    int maxsubhelper(vector<int> &nums,int start,int end){
        //base case
        if(start==end){
            return nums[start];
        }
        int mid=start +(end-start)/2;
        int maxsumleftborder=INT_MIN,maxsumrightborder=INT_MIN;
        
        int maxsumleft= maxsubhelper(nums,start,mid);
        int maxsumright = maxsubhelper(nums,mid+1,end);

        //MAX CROSS BORDER..
        int leftcrossborder=0,rightcrossborder=0;

        for(int i=mid;i>=start;i--){
            leftcrossborder += nums[i];

            if(maxsumleftborder < leftcrossborder) maxsumleftborder = leftcrossborder;
        }
        
        for(int i=mid+1;i<=end;i++){
            rightcrossborder += nums[i];

            if(rightcrossborder > maxsumrightborder) maxsumrightborder = rightcrossborder;
            
        }
        int crossborder = maxsumleftborder + maxsumrightborder;
        return max(crossborder,max(maxsumleft,maxsumright));
    } 
    int maxSubArray(vector<int>& nums) {
        return maxsubhelper(nums,0,nums.size()-1);   
    }
};