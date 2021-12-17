#include <iostream>
#include <map>

using namespace std;

int main(){
	map<string, int> mpp; 
	mpp["raj"] = 27; 
	mpp["hima"] = 31; 
	mpp["praveer"] = 31;
	mpp["sandeep"] = 67; 
	mpp["tank"] = 89; 
	mpp["raj"] = 29; 

	for(auto it:mpp){
		cout<<it.first<<it.second<<" ";
	}cout<<endl;
	return 0;
}