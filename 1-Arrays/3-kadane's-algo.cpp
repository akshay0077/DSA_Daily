//(1) You can think O(n^2) with O(1) space solution

//(2) C++ program to print largest contiguous array sum

//Time : O(N)
//space :O(1)

#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int arr[], int n)
{
	int MaxSum = 0;
	int CurrSum = 0;

	for (int i = 0; i < n; i++)
	{
		CurrSum = CurrSum + arr[i];

		if (MaxSum < CurrSum)
			MaxSum = CurrSum;

		if (CurrSum < 0)
			CurrSum = 0;
	}
	return MaxSum;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-1, 2, -2, 5, 7, -3, 1};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum<<endl;
	return 0;
}
