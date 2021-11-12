class Solution{
public:
	int maxSubArraySum(int arr[],int k,int n)
	{
		int start=0;
		int end=0;
		int sum=0;
		int mx=INT_MIN;

		while(end < n)
		{
			sum=sum+arr[end];
			if(end-start+1<k)
			{
				j++;
			}
			else if((end-start+1)==k)
			{
				mx=max(mx,sum);
				sum=sum-arr[start];
				start++;
				end++;
			}
		}
		return mx;
	}
}