(1)Brute Force

/*
    Time Complexity : O(N ^ 3)
    Space Complexity : O(1)

    Where N is the size of the string.
*/

// Use it to check if the string 's' has at most 'k' distinct characters.
bool check(string s, int k) {
    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }

    int distinct = 0;

    for (int i = 0; i < 26; i++) {
        // Increase the count of distinct characters.
        if (freq[i]) {
            distinct++;
        }
    }

    return distinct <= k;
}

int getLengthofLongestSubstring(string s, int k) {
    int longestLength = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        string current;

        for (int j = i; j < n; j++) {
            current.push_back(s[j]);

            // Check if the substring from '[i, j]' has at most 'k' distinct characters.
            if (check(current, k)) {
                // Update 'longestLength' accordingly.
                longestLength = max(longestLength, j - i + 1);
            }
        }
    }

    return longestLength;
}

(2)Improved Version


/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(1)

    Where N is the size of the string.
*/

#include <vector>

// Returns the number of distinct characters in the array 'freq'.
int countDistinct(vector<int> &freq) {
    int distinct = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            distinct++;
        }
    }

    return distinct;
}

int getLengthofLongestSubstring(string s, int k) {
    int longestLength = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);

        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            // Check if 'freq' contains at most 'k' distinct characters.
            if (countDistinct(freq) <= k) {
                // Update 'longestLength' accordingly.
                longestLength = max(longestLength, j - i + 1);
            }
        }
    }

    return longestLength;
}

(3)Using Binary Search


/*
    Time Complexity : O(N * logN)
    Space Complexity : O(1)

    Where N is the size of the string.
*/

#include <vector>

// Returns the number of distinct characters in the array 'freq'.
int countDistinct(vector<int>& freq) {
    int distinct = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            distinct++;
        }
    }

    return distinct;
}

int getLengthofLongestSubstring(string s, int k) {
    int longestLength = 0;
    int n = s.size();

    int low = 1, high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        bool possible = false;
        vector<int> freq(26, 0);

        for (int i = 0; i < mid; i++) {
            freq[s[i] - 'a']++;
        }

        possible |= (countDistinct(freq) <= k);

        // Using sliding window, check if a valid substring of length 'mid' is possible.
        for (int i = mid; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[s[i - mid] - 'a']--;
            possible |= (countDistinct(freq) <= k);
        }

        /*
            If a valid substring of length 'mid' is possible then update 'longestLength'
            and check for substrings having length greater than 'mid'.
        */
        if (possible) {
            longestLength = max(longestLength, mid);
            low = mid + 1;
        }
        // If no such substring is possible check for substrings with length less than 'mid'.
        else {
            high = mid - 1;
        }
    }

    return longestLength;
}

(4)Optimal Approach


/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where N is the size of the string.
*/

#include <vector>

// Returns the number of distinct characters in the array 'freq'.
int countDistinct(vector<int>& freq) {
    int distinct = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            distinct++;
        }
    }

    return distinct;
}

int getLengthofLongestSubstring(string s, int k) {
    int longestLength = 0;
    int n = s.size();

    vector<int> freq(26, 0);

    // Starting index of the window.
    int start = 0;

    // Traverse for ending index of the window.
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;

        while (countDistinct(freq) > k) {
            freq[s[start] - 'a']--;
            start++;
        }

        longestLength = max(longestLength, i - start + 1);
    }

    return longestLength;
}