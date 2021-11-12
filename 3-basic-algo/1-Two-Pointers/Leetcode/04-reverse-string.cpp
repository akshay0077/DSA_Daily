Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

constraints:
1 <= s.length <= 105

(1)Brute Force:
/*
	Time:O(N^2)
*/

(2)Two pointers:
/*
	Time:O(N)
	space:O(1)
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
     int start=0;
     int end =s.size()-1;
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};

=>using C++ STL

class Solution {
public:
    void reverseString(vector<char>& s) {
      reverse(s.begin(),s.end());
    }
}; 