(1)Brute Force

/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(1)

    Where 'N' is the length of the given strings.
*/

int getMinimumAnagramDifference(string &str1, string &str2) {
    // Variable to store the minimum manipulations required to make string anagram.
    int minAnagramDiff = 0;

    int n = str1.size();

    // Iterate over the first string.
    for (int i = 0; i < n; i++) {
        int j;

        // Searching into the second string.
        for (j = 0; j < n; j++) {
            // If both the string has equal characters,
            // Then change the character of the second string.
            if (str1[i] == str2[j]) {
                str2[j] = '#';
                break;
            }
        }

        // If there is no matching character for the current character in the second string.
        if (j == n) {
            minAnagramDiff++;
        }
    }
    // Return minimum manipulations require to make string anagram.
    return minAnagramDiff;
}

(2)Using Frequency

/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where 'N' is the length of the given string.
*/

#include <vector>

int getMinimumAnagramDifference(string &str1, string &str2) {
    int n = str1.size();

    // Vector for storing the frequencies.
    vector<int> freq(26, 0);

    // Store the frequencies of characters of first string.
    for (int i = 0; i < n; i++) {
        freq[str1[i] - 'a']++;
    }

    // Subtract the frequencies of characters of second string.
    for (int i = 0; i < n; i++) {
        freq[str2[i] - 'a']--;
    }

    // Variable to store the total absolute frequencies difference.
    int freqDiff = 0;

    // Iterating for all alphabets to cacluclate the total absolute frequencies difference.
    for (int i = 0; i < 26; i++) {
        freqDiff += abs(freq[i]);
    }

    // Return minimum manipulations required to make string anagram.
    return freqDiff / 2;
}