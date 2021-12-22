3.Leetcode

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1


constraints:
0 <= s.length <= 5 * 10^4

------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // set to store characters in current slidding window
        unordered_set<char> count;
        // To store maximum size of substring
        int ans=0;
        // Starting index of current window
        int i=0;
        // Ending index of current window
        int j=0;
        
        while(j<s.length())
        {
            // if current element is present in window
            if(count.find(s[j])!=count.end())
            {
                // Shrinking the window until we delete occurence of current character
                while(s[i]!=s[j])
                {
                    count.erase(s[i]);
                    i++;   
                }
                count.erase(s[i]);
                i++;
            }
            // Updating the ans if length of current window is greater than ans
            if((j-i+1)>ans)
            {
                ans=j-i+1;
            }
            //inserting current character to window
            count.insert(s[j]);
            j++;
            

            }
        
        return ans;
        
        
    }
};