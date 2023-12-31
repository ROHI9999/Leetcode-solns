class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high) {
			int mid = low + (high - low)/2;  //divide by 2 using  >> (right shift)
			
            if(nums[mid] == target)
                return mid;
            
            if(nums[low] <= nums[mid]) {
                // left half is sorted
                if(target >= nums[low] && target <= nums[mid])  // If target is within the range.....
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                if(target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};