https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;
        list<int> l;
        int start=0;
        int end=0;
        
        if (k>nums.size()) // edge case
        {
            ans.push_back(*max_element(l.begin(),l.end()));
            return ans;
        }
        
        while (j<nums.size())
        {
            while(l.size()>0 && l.back() <nums[end])
            {
                l.pop_back();
            }
            l.push_back(nums[end]);
            if ((end-start+1)<k)
                j++;
            else if (end-start+1==k)
            {
                ans.push_back(l.front());
                if (l.front()==nums[start])
                    l.pop_front();
                i++;
                j++;
            }
            
        }
        return ans;
    }
};