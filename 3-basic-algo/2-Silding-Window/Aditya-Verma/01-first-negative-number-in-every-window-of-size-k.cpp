https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

(1)Brute Force

/*
	Time:O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

// function to find the first negative
// integer in every window of size k
void printFirstNegativeInteger(int arr[], int n, int k)
{
	// flag to check whether window contains
	// a negative integer or not
	bool flag;
	
	// Loop for each subarray(window) of size k
	for (int i = 0; i<(n-k+1); i++)		
	{
		flag = false;

		// traverse through the current window
		for (int j = 0; j<k; j++)
		{
			// if a negative integer is found, then
			// it is the first negative integer for
			// current window. Print it, set the flag
			// and break
			if (arr[i+j] < 0)
			{
				cout << arr[i+j] << " ";
				flag = true;
				break;
			}
		}
		
		// if the current window does not
		// contain a negative integer
		if (!flag)
			cout << "0" << " ";
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	printFirstNegativeInteger(arr, n, k);
	return 0;
}

//-----------------------------------------------------

(2)sliding Window

/*
	Time:O(N)
	Space:O(1)
*/

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
 long long start;
 long long end;

 vector<long long> ans;
 list<long long> l;

  while (end<N)
  {
    if (A[end]<0) 
      l.push_back(A[end]);

    if (end-start+1<K) 
    	end++;

    else if ((end-start+1)==K)
    {
      if (l.size()==0)
        ans.push_back(0);

      else
        ans.push_back(l.front());

      if(A[start]<0)
        l.pop_front();

      start++;
      end++;
    }
  }
  return ans;
}