Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

constraints:
1 <= nums.length <= 10^4


(1)Brute Force
/* Time: O(N^2) */

(2)Two pointers
/*
    Time:O(N)
    Space:O(1)

*/
class Solution{
    public:
    void moveZeroes(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        
        while(start< end)
        {
            if((nums[start]==0 && nums[end]==0)){
                end++;
                continue;
            }
            else if(nums[start]==0 && nums[end]!=0)
            {
                   swap(nums[start],nums[end]);
            }
            start++;
            end++;
        }
    }
};