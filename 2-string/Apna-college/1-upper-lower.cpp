#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str="abcdefgh";

	//to Upper case
	for(int i=0; i<=str.size(); i++)
	{
		if(str[i]>='a' && str[i]<='z')
			str[i]-=32;
	}
	cout<<"Upper case : "<<str<<endl;

	//to Lowwer case
	for(int i=0; i<=str.size(); i++)
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i]+=32;
	}
	cout<<"Lower case : "<<str<<endl;

	return 0;
}

// C++ program to convert whole string to
// uppercase or lowercase using STL.
#include<bits/stdc++.h>
using namespace std;

int main()
{
	// su is the string which is converted to uppercase
	string su = "Akshay Kher";

	// using transform() function and ::toupper in STL
	transform(su.begin(), su.end(), su.begin(), ::toupper);
	cout << su << endl;

	// sl is the string which is converted to lowercase
	string sl = "Akshay Kher";

	// using transform() function and ::tolower in STL
	transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
	cout << sl << endl;

	return 0;
}
