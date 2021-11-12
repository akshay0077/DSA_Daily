
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

constraints:
1 <= s.length <= 2 * 10^5
-------------------------------------------------------------

(1)Brute Force

/*
    Time:O(N^2)
*/

class Solution{
public:
    bool isPalindrome(string s)
    {
        for(int i=0; i<s.size(); i++)
        {
            for(int j=0; j<s.size(); j++){
                if(i<j)
                {

                }
            }
        }
    }
}


(2)Two pointers Technicque

/*
    Time:O(N)
    Space:O(1)

*/
class Solution {
public:
    bool isPalindrome(string s) {
       int start = 0, end = s.size()-1;
        while(start < end){
            if(!isalnum(s[start])) 
                start++;
            else if(!isalnum(s[end])) 
                end--;
            else if(tolower(s[start]) != tolower(s[end])) 
                return false;
            else{
                start++; 
                end--;
            }
        }
        return true;
    }
};