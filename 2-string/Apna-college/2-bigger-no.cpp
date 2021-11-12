#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s="839112307";

	sort(s.begin(), s.end(), greater<int>());

	cout<<s<<endl;
	return 0;
}