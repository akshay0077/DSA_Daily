(1) Brute Force Approach

/*

	Time Complexity: O(N^2)
	Space Complexity: O(1)

	Where 'N' is the number of elements in the sequence.
	
*/

int maxArea(vector<int>& height) {
    // Number of elements.
		int n = height.size();

		// Variable to store max area initialised as a negative vlaue.
		int globalMax = -1;

		// Loop through all starting indices.
		for (int i = 0; i < n; i++) {

			// Fix a ending index for each starting index.
			for (int j = n - 1; j > i; j--) {

				// Calculate area.
				int area = (j - i) * min(height[i], height[j]);

				// Compare it with overall best area.
				globalMax = max(globalMax, area);
			}
		}
		return globalMax;
}

(2) Two Pointers Approach

/*
    Time Complexity: O(n)
    Space Complexity: O(1)

    Where 'n' is the number of elements in the sequence.
*/
int maxArea(vector<int>& height) {
    // Variable to store overall maximum area. Initially -1.
    int globalArea = -1;

    int startIndex = 0, endIndex = height.size() - 1;
    while (startIndex < endIndex) {
        // Minimum height calcuted to find the area.
        int minHeight = min(height[startIndex], height[endIndex]);

        globalArea = max(globalArea, (endIndex - startIndex) * minHeight);

        // If the start index has a smaller value than min height try to find a bigger value.
        if (height[startIndex] <= minHeight) {
            startIndex++;
        } else {
            // Otherwise, try to find a bigger value for end index.
            endIndex--;
        }
    }
    return globalArea;
}