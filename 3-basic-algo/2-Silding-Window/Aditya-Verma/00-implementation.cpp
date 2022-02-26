// https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/

//Time Complexity : O(n)
//Auxiliary Space : O(1)

class Solution{
public:
int maximumSumSubarray(int K, vector<int> &Arr , int N)
{
  int start=0;
  int end=0;
  int sum=0;
  int mx=INT_MIN;

  while (end<N)
  {
    sum=sum+Arr[end]; // do calculation to reduse tc
    if (end-start+1<K) 
    	j++; // increament j upto when the size of the size of window is not equal to required size
    
    else if ((end-start+1)==K) // when sindow size hit to the required window size 
    {
      mx=max(mx,sum); // selecting ans from the candidates
      sum=sum-Arr[start]; // start removing from the first
      start++;
      end++;
    }
  }
  return mx;
}
};