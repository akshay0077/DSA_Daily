//Time: O(N)
//Space: O(1)

#include <iostream>
using namespace std;

int LinearSearch(int arr[],int n,int k)
{
	for(int i=0; i<n; i++){
		if(arr[i]==k)
			return i;
	}
	return -1;
}
int main()
{
	int arr[]={10,40,60,70,90};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=70;

	cout<<LinearSearch(arr,n,k)<<endl;
}