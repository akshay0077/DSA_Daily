Input:
3
aabbc
abcd
abbdcaas

Output:
a2b2c1
a1b1c1d1
a1b2d1c1a2s1

/*
    Time Complexity: O(N)
    Space complexity: O(N)
*/

string encode(string &message)
{
    int c=1;
    string ans;

   for(int i=0;i<message.size();i++){  
       if(message[i]==message[i+1])
           c++;
       else{
           ans+=message[i]+to_string(c);
           c=1;
       }
   }
   return ans;
}