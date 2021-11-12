//Time: O(logN)
//Space: O(1)

#include <iostream>
using namespace std;

int BinarySearch(int arr[],int n,int k)
{
	int start=0;
	int end=n-1;

	while(start <=end){

		int mid=(start+end)/2;

		if(arr[mid]==k)
			return mid;
		if(arr[mid] > k)
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}
int main()
{
	int arr[]={10,40,60,70,90};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=70;

	cout<<BinarySearch(arr,n,k)<<endl;
}