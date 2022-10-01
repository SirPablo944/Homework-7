#include <iostream>
#include <string>
using namespace std;

bool isPrefix(string str, int len, int i, int k)
{
    // k length sub-string start at index i + k
    if (i + k > len)
        return false;
    for (int j = 0; j < k; j++)
    {

        // Mismatch of prefix and sub-string at index i
        if (str[i] != str[j])
            return false;
        i++;
    }
    return true;
}

// Method returns true if string is K-periodic
bool isKPeriodic(string str, int len, int k)
{
    // Check if all the sub-strings are equal
    // to the k length prefix of the string
    for (int i = k; i < len; i += k)
        if (!isPrefix(str, len, i, k))
            return false;
    return true;
}


int main()
{
    string str = "abcdabcdabcdabcd";
    int len = str.length();
    int k = 4;

    if (isKPeriodic(str, len, k))
        cout << ("Yes");
    else
        cout << ("No");
}