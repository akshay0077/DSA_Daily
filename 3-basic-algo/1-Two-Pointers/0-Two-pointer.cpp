(1)Opposite - directional Two Pointers Technique

/*

Time complexity is O(n)
The space complexity is O(1) 

*/

Example: Array: 1 2 3 4 6
Target Sum: 6
Output: 1, 3

function twoSum(A, S):
	//   store the length of the array 
	n = A.length
	
	
        // maintain 2 pointers one for the left end and the other for the right end of the subarray.
    
    
	int start = 0, end = n - 1
	//   final answer pair
	ans  = {-1 , -1} 
	//   while the left pointer is less than the right pointer
	while(start <= end)
		//   calculate the current Sum of 2 pointers
		curSum = A[start] + A[end]
		if(curSum == S)
			//   we have found a valid pair so return the indices
			ans = {start, end}
			return ans
		else if (curSum > S)
			//   move the right pointer left as the sum is greater
			end -= 1         
		else 
			//   move the left pointer right as the sum is smaller
			start += 1    
	return ans

//-------------------------------------------------------------------

(2) Equi Directional Two Pointers Technique

Example: Array : -1 2 3 4 5 6 

P: 20
Output: 2

function minSubarray(A, P)

	//   store the length of the array 
	n = A.length
	
	/*
         maintain 2 pointers one for the left end and the other for the right end       
         of the subarray
        */
    
	int i = 0, j = 0
	
	//   We maintain the Product of the current window in the variable curP
	curP = 1
	
	//   final answer
	ans  = infinity
	
	//   move the left pointer rightwards
	while(i < n)
    	/*
          while we do not reach the required product keep expanding the 
          window 
        */
		while(j < n and curP <P)   
			curP *= A[j]
			j++
		//   we update the ans with the window length
		if(curP >= P)
		ans = min(ans, j  - i + 1)
		//   move the left pointer and update its contribution to the product
		curP /= A[i]
		i++
		
	return ans