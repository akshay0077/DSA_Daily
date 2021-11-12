(1)/*
    Time Complexity : O(N)
    Space Complexity : O(N)
*/

string leftRotate(string &str, int d) {
        
    // Store the size of given string.
    int n = str.size();

    // If rotate multiple times.
    if(n < d) {
        return leftRotate(str, d % n);
    }

    // Take an empty string.
    string ans = "";

    // Append last 'n' - 'd' characters to 'ans'.
    ans = ans + str.substr(d);

    // Append the remaining first 'd' characters to the 'ans'.
    ans = ans + str.substr(0, d);

    // Reach this means your 'ans' is computed.
    return ans;
}

string rightRotate(string &str, int d) {
        
    // Store the size of given string.
    int n = str.size();

    // If rotate multiple times.
    if(n < d) {
        return rightRotate(str, d % n);
    }

    // Take an empty string.
    string ans = "";

    // Append last 'd' characters to 'ans'.
    ans = ans + str.substr(n - d);

    // Append the remaining first 'n' - 'd' characters to the 'ans'.
    ans = ans + str.substr(0, n - d);

    // Reach this means your 'ans' is computed.
    return ans;
}

(2)

string leftRotate(string &str, int d) {
    d=d%str.length();
   return str.substr(d,str.length()-d) + str.substr(0,d);
}
string rightRotate(string &str, int d) {
    d=d%str.length();
   return str.substr(str.length()-d,d) + str.substr(0,str.length()-d);
}
