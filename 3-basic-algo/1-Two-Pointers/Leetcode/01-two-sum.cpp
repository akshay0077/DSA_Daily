Input: numbers = [2,7,11,15], target = 9
Output: [1,2]

constraints:
2 <= numbers.length <= 3 * 10^4

(1)Brute Force
/*
    Time:O(N^2)
    Space:O(1)
*/

class Solution{
public:
    vector<int>twoSum(vector<int>& nums,int target)
    {
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                int sum=nums[i]+nums[j];
                
                if(sum==target)
                    return {i+1,j+1};
                else if(sum>target)
                    j--;
                else
                    i++;
            }
        }
        return {};
    }
};

(2)Two pointers Technicque
/*
    Time:O(N)
    Space:O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target) return {i+1,j+1};
            else if(sum>target) j--;
            else i++;
        }
        return {}; 
    }
};