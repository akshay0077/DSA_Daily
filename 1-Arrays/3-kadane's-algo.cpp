//(1) You can think O(n^2) with O(1) space solution

//(2) C++ program to print largest contiguous array sum

//Time : O(N)
//space :O(1)

#include <iostream>
using namespace std;

int maxSubArraySum(int arr[],int n){
	// int MaxSum=0;
	// for(int i=0; i<n; i++)
	// {
	// 	int CurrSum=0;
	// 	for(int j=i; j<n; j++)
	// 	{
	// 		CurrSum+=arr[j];
	// 		MaxSum=max(MaxSum,CurrSum);
	// 	}
	// }
	// return MaxSum;

	int MaxSum=0;
	int CurrSum=0;

	for(int i=0; i<n; i++){
		CurrSum+=arr[i];
		if(CurrSum > MaxSum)
			MaxSum=CurrSum;
		if(CurrSum < 0)
			CurrSum=0;
	}
	return MaxSum;
}

int main(){
	int arr[]={1,2,7,-4,3,2,-10,9,1};
	int n=sizeof(arr)/sizeof(arr[0]);

	int max=maxSubArraySum(arr,n);
	cout<<max<<endl;
	return 0;
}