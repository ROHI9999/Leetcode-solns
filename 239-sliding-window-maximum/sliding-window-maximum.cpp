class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
        vector<int> ans;

        for(int i = 0;i<k;i++){
            
            //remove small element
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //insert index,so that we can checkout of the window
            dq.push_back(i);
        }
        
        //store the max element in ans vector
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();i++){

            //remove out of window elements
            while(!dq.empty() && (i - dq.front() >=k)){
                dq.pop_front();
            }

            //again pop small element
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //insert index,so that we can checkout of window size k 
            dq.push_back(i);
            
            //store max element fron deque in ans vector.
            ans.push_back(nums[dq.front()]);
        }
        //return the ans vector      
        return ans;

    }
};