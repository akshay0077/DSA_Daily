(1) Brute Force

/*
        Time Complexity : O(N ^ 3)
        Space Complexity : O(1),

        where N is the number of elements in the array.

*/

vector<int> findTriplets(vector<int> &arr, int n) 
{

    // It is used to store the required triplets
    vector<int> ans;

    for (int i = 0; i < n - 2; i++) 
    {
        for (int j = i + 1; j < n - 1; j++) 
        {
            for (int k = j + 1; k < n; k++) 
            {
                
                // If we find a valid triplet
                if ((arr[i] + arr[j] == arr[k]) or (arr[i] + arr[k] == arr[j]) or (arr[k] + arr[j] == arr[i])) 
                {
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[k]);
                    return ans;
                }
            }
        }
    }
    return ans;
}

(2) Sorting and Two pointers.

/*
        Time Complexity : O(N * log(N))
        Space Complexity : O(1),

        where N is the number of elements in the array.

 */

vector<int> findTriplets(vector<int> &arr, int n) {

    vector<int> ans;
    
    // Sorting the vector.
    sort(arr.begin(), arr.end());

    for (int i = n - 1; i >= 0; i--) 
    {

        int j = 0;
        int k = i - 1;

        // Use two pointer technique to find the required triplet.
        while (j < k) 
        {

            // If we find a valid triplet.
            if (arr[i] == arr[j] + arr[k]) 
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                ans.push_back(arr[k]);
                return ans;
            }

            // If the current element is greater than the sum of the other two, increment j.
            else if (arr[i] > arr[j] + arr[k]) 
            {
                j = j + 1;
            }

            // If the current element is smaller than the sum of the other two, decrement k.
            else 
            {
                k = k - 1;
            }
        }
    }

    return ans;
}