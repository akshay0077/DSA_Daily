Input :
3
I love programming
they are playing cricket
good to see you

Output:
3
I Love Programming
They Are Playing Cricket
Good To See You

//-----------------------------------------------

(1)inbuild function in convertString

/*
    Time Complexity: O(N)
    Space complexity: O(N)
*/

string convertString(string str)
{
    bool flag = true;
    for (int i = 0; i < str.size(); i++)
    {
            if (flag == true && islower(str[i])) {
                str[i] = toupper(str[i]);
            }
            if (str[i] ==' ')
                flag = true;
            else
                flag = false;
        }
        return str;
}


(2)Without using inbuilt functions

// Time Complexity: O(N)
// Space complexity: O(1)

string convertString(string s) 
{
      int n = s.length();

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' and s[i] <= 'z') {
            s[i] -= 32;
        }
        while (i < n && s[i] != ' ')
            i++;
    }
    return s;
}
