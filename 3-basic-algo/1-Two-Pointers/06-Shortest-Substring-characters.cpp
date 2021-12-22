(1) Brute Force

/*
    Time Complexity : O(N ^ 2)
    Space Complexity : O(K)

    where 'N' denotes the length of the given string
    and 'K' denotes the number of distinct characters in the string.
*/

#include <unordered_set> 

string shortestSubstring(string s)
{
    int n = s.length();

    int startIndex = 0, minLength = n;

    // Set to count distinct characters.
    unordered_set<char> hashSet;

    for (int i = 0; i < n; i++)
    {
        hashSet.insert(s[i]);
    }

    // Variable to store all the distinct characters of string 's'.
    int distinctChar = hashSet.size();

    for (int i = 0; i < n; i++)
    {

        // Variable to store current distinct characters of string 's'.
        int count;

        // Unordered Set to count distinct characters in the window.
        unordered_set<char> visited;

        for (int j = i; j < n; j++)
        {
            
            // Insert the characters in the set 'visited'.
            visited.insert(s[j]);
            count = visited.size();

            /*
				If count of current distinct characters becomes equal to 
				count of all the distinct characters present in String 's' then 
				store the minimum length of the subString in 'minLength'.
			*/	
			if (count == distinctChar)
            {
                if (j - i + 1 < minLength)
                {
                    minLength = j - i + 1;
                    
                    // Updating starting index of substring.
                    startIndex = i;
                }
            }
        }
    }

    /*
		Return substring from 's' having starting index 
		as 'startIndex' and having length of 'minLength'.
	*/
	return s.substr(startIndex, minLength);
}

(2) Sliding Window

/*
    Time Complexity : O(N)
    Space Complexity : O(K)

    where 'N' denotes the length of the given string.
    and 'K' denotes the number of distinct characters in the string.
*/

#include <unordered_set>
#include <unordered_map>

string shortestSubstring(string s)
{
    int n = s.length();

    int startIndex = 0, minLength = n;

    // Unordered Set to count distinct characters.
    unordered_set<char> m;

    for (int i = 0; i < n; i++)
    {
        
        // Inserting every character of given string 's' in set.
        m.insert(s[i]);
    }

    // Variable to store all distinct elements in given string 's'.
    int distinctChar = m.size();

    // Variable to count the current distinct elements in 's'.
    int count = 0;
    
    /*
		Variable to store starting index of the substring
		with minimum length and having all distinct 
		characters of 's' at least once.
	*/
	int start = 0;

    //  Map to store frequency of charaters in a particular window.
    unordered_map<char, int> frequency;

    for (int end = 0;  end < n;  end++)
    {
        
        // New character inserted.
        frequency[s[end]]++;

		/*
			If current character having is 
			having frequency = 1 then increment 'count'.
		*/
        if (frequency[s[end]] == 1)
        {
            count++;
        }

        /*
			If count of current distinct characters 
			equals to count of all the distinct characters.
		*/
		while (count == distinctChar)
        {
            
            // Update the minimum length of substring in 'minLength'.
            if (end - start + 1 < minLength)
            {
                
                // Update the starting index of the substring.
                startIndex = start;
                minLength = end - start + 1;
            }

            // Decrement the frequency of the starting element. 
            frequency[s[start]]--;

            // Character is not present in the window after this.
            if (frequency[s[start]] == 0)
            {
                count--;
            }
            
            // Increment the 'start' pointer.
            start++;
        }
    }
    
    /*
		Return the substring starting with
		index 'startIndex' and having length of 'minLength'.
	*/
    return s.substr(startIndex, minLength);
}