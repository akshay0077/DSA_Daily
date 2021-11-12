/*
    Time Complexity: O(N^2)
    Space complexity: O(N)
*/

#include<string.h>

string removeVowels(string inputString)
{
    int len = inputString.length();

    char *inputStringArray = new char[inputString.length() + 1];
    strcpy(inputStringArray, inputString.c_str());

    for (int i = 0; i < len; i++)
    {
        char curr = inputStringArray[i];
        int j = i;

        if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u' || curr == 'A' || curr == 'E' || curr == 'I' || curr == 'O' || curr == 'U')
        {

            while (j < len - 1)
            {
                inputStringArray[j] = inputStringArray[j + 1];
                j++;
            }

            len--;
            i--;
        }
    }

    string result = "";

    for (int i = 0; i < len; i++)
    {
        result.push_back(inputStringArray[i]);
    }

    return result;
}

/*
    Time Complexity: O(N)
    Space complexity: O(N)

*/

string removeVowels(string inputString)
{
    string result;

    for (int i = 0; i < inputString.length(); i++)
    {
        char curr = inputString[i];

        if (curr != 'a' && curr != 'e' && curr != 'i' && curr != 'o' && curr != 'u' && curr != 'A' && curr != 'E' && curr != 'I' && curr != 'O' && curr != 'U')
        {
            result.push_back(curr);
        }
    }

    return result;
}
