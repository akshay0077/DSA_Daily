(1) Brute Force

/*
    Time Complexity: O(N*3^N)
    Space Complexity: O(N)

    Where 'N' is the length of the string.
*/

// Function to check if a string is balanced.
bool isValid(string &s);

// Function to try all possible strings.
bool checkValidStringHelper(string &s, int i, string &temp);

bool checkValidString(string s){
    string temp;
    return checkValidStringHelper(s, 0, temp);
}

bool checkValidStringHelper(string &s, int i, string &temp){

    // If we reach the end of string.
    if (i == s.length()){
        return isValid(temp);
    }

    // If current char is not '*', move forward.
    if (s[i] != '*'){
        temp.push_back(s[i]);

        if (checkValidStringHelper(s, i + 1, temp)){
            return true;
        }
        temp.pop_back();
    }

    // Else, try each possiblity.
    else{

        // '*' as Empty String.
        if (checkValidStringHelper(s, i + 1, temp)){
            return true;
        }

        // '*' as an open bracket.
        temp.push_back('(');

        if (checkValidStringHelper(s, i + 1, temp)){
            return true;
        }

        temp.pop_back();

        // '*' as a close bracket.
        temp.push_back(')');

        if (checkValidStringHelper(s, i + 1, temp)){
            return true;
        }
        temp.pop_back();
    }

    // If it's impossible to get any answer.
    return false;
}

bool isValid(string &s){
    int c = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            c++;
        }

        else if (c > 0){
            c--;
        }

        else{
            return 0;
        }
    }

    return c == 0;
}

(2) Two pointers

/*
    Time Complexity: O(N)
    Space Complexity:  O(1)

    Where 'N' is the length of the string.
*/

bool checkValidString(string s) {
    int lower = 0, upper = 0;
    for (char c : s){

        if (c=='(') {
            lower++;
            upper++;
        } 

        else if (c==')') {
            lower--;               
            upper--;
        }

        // '*' encountered.
        else{ 
            lower--;
            upper++;
        }

        lower = max(lower, 0);

        // Unmatched ')' found in the middle of string.
        if (upper<0) 
        {
            return false;
        }
    }
    return lower == 0;
}