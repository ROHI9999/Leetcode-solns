class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=i+1;
        for(int i=0;i<nums.size();i++){        
                int element = nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(element + nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {i,j};
    }
};