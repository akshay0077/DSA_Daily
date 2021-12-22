(1) Brute Force (Time Limit Exceed)

/*  
    Time complexity: O(N * M)
    Space complexity: O(1)

    where 'N' is number of characters in string 'str1' 
    and 'M' is number of characters in string 'str2'.
*/

bool isSubSequence(string str1, string str2) {
    int prev = -1;
    int count = 0;
    int n = str1.size();
    int m = str2.size();

    // To use iterate all character of 'str2'.
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {
            if (str1[i] == str2[j] && j > prev) {
                prev = j;
                count += 1;
                break;
            }
        }
    }

    // If all characters of 'str1' are present in 'str2' in same order.
    if (count == n) {  
        return true;
    } else {
        return false;
    }
}

(2) Two pointer approach

/* 
    Time complexity: O(M)
    Space complexity: O(1)

    where 'M' is number of characters in string 'str2'.
*/

bool isSubSequence(string str1, string str2) {
    int idx = 0;
    int n = str1.size();
    int m = str2.size();

    // To use iterate all character of 'str2'.
    for (int i = 0; i < m; i++) {  
        if (str2[i] == str1[idx]) {
            idx += 1;
        }

        // When we have already iterate all the characters of 'str1'.
        if (idx == n) {  
            break;
        }
    }

    // If all characters of 'str1' are present in 'str2' in same order.
    if (idx == n) {  
        return true;
    } else {
        return false;
    }
}
