#include <iostream>
using namespace std;

int main(){
	int arr[5]={0,1,2,3,4};

	for(int i=0; i<5; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=4; i>=0; i--){
		cout<<arr[i]<<" ";
	}
	return 0;
}