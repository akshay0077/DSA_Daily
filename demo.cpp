//Time:O(N)
//Space:O(N)

string convertString(string s){
	bool flag=true;

	for(int i=0; i<=s.size(); i++){
		if(flag==true && islower(s[i]))
			s[i]=isupper(s[i]);
		if(s[i]==' ')
			flag=true;
		else
			flag=false;
	}
	return s;
}