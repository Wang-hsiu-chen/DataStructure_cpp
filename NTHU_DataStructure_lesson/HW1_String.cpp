#include <iostream>

using namespace std;

class String
{
public:
    String(char *init, int m);
    ~String();
    // constructor using input string init of length m
    bool operator==(String t); // equality test
    bool operator!();          // empty test, true or false
    int Length();              // get the number of characters of *this
    String Concat(String t);
    // concatenation with another string t
    String Substr(int i, int j); // generate a substring i~i+j-1
    void FailureFunction();
    int Find(String pat);
    int FastFind(String pat);
    // Return an index i such that pat matches the substring
    // of the object begins at position i.  Return -1 if pat
    // is empty or not a substring of the object
    String Delete(int start, int length); // remove length characters beginning
    // at start
    String CharDelete(char c); // returns the string with all occurrence of c
    // removed.
    int Compare(String y); // compare two strings of letters of alphabet.
    // return -1 if <y, 0 if =y, and 1 if >y.
    // If two strings of letter of alphabet, x = (x0,…,xm-1) and y=(y0,…,yn-1)
    // where xi, yj are letters, then the Compare member function will decide
    // whether x<y, x=y, or x>y, where x < y means if xi=yi for 0≤i<j and xj<yj
    // or if xi=yi for 0≤i≤m and m<n. x=y means m=n and xi=yi for 0≤i<n. x>y
    // means if xi=yi for 0≤i<j and xj>yj or if xi=yi for 0≤i≤n and m>n.
    friend ostream &operator<<(ostream &os, String &p);
    friend istream &operator>>(istream &is, String &p);

private:
    char *str;
    char *f;
    int strLength;
};
String::String(char *init, int m)
{
    str = init;
    str = new char[m];
    strLength = m;
}
String::~String()
{
    // delete[] str;
}
bool String::operator==(String t)
{
    if (Length() == t.Length())
        return false;
    for (int i = 0; i < Length(); i++)
        if (str[i] != t.str[i])
            return false;
    return true;
}
bool String::operator!()
{
    if (Length() == 0)
        return true;
    else
        return false;
}
int String::Length()
{
    // int length = 0;
    // while (str[length] != )
    // {
    //     length++;
    // }
    return strLength;
}
String String::Concat(String t)
{
    int length = Length();
    int newLength = length + t.Length();
    char *temp = new char[newLength];
    for (int i = 0; i < length; i++)
        temp[i] = str[i];
    for (int i = length; i < newLength; i++)
        temp[i] = t.str[i - length];
    delete[] str;
    str = temp;
    strLength = newLength;
    return *this;
}
String String::Substr(int i, int newLength)
{
    if (i + newLength > Length())
        throw "error";
    char *temp = new char[newLength], *a;
    copy(str + i, str + i + newLength, temp);
    String subStr(a, newLength);
    subStr.str = temp;
    return subStr;
}
void String::FailureFunction()
{
    int lengthP = Length();
    f[0] = -1;
    for (int j = 1; j < lengthP; j++)
    {
        int i = f[j - 1];
        while ((str[j] != str[i + 1]) && (i >= 0))
            i = f[i];
        if (str[j] == str[i + 1])
            f[j] = i + 1;
        else
            f[j] = -1;
    }
}
int String::Find(String pat)
{
    for (int start = 0; start <= Length() - pat.Length(); start++)
    {
        int j;
        for (j = 0; j < pat.Length() && str[start + j] == pat.str[j]; j++)
            ;
        if (j == pat.Length())
            return start;
    }
    return -1;
}
int String::FastFind(String pat)
{
    int posP = 0, posS = 0;
    int lengthP = pat.Length(), lengthS = Length();
    while ((posP < lengthP) && (posS < lengthS))
    {
        if (pat.str[posP] == str[posS])
        {
            posP++;
            posS++;
        }
        else
        {
            if (posP == 0)
                posS++;
            else
                posP = pat.f[posP - 1] + 1;
        }
    }
    if (posP < lengthP)
        return -1;
    else // Textbook stops pattern matching once a match is found
        return posS - lengthP;
}
String String::Delete(int start, int length)
{
    int end = start + length - 1;
    int oldLength = Length();
    int newLength;
    if (start >= oldLength)
        throw "error";
    char *temp;
    if (end >= oldLength - 1 && start != 0)
    {
        temp = new char[start];
        copy(str, str + start, temp);
        newLength = start;
    }
    else if (end < oldLength - 1 && start != 0)
    {
        temp = new char[oldLength - length];
        copy(str, str + start, temp);
        copy(str + end + 1, str + oldLength, temp + start);
        newLength = oldLength - length;
    }
    delete[] str;
    str = temp;
    strLength = newLength;
    return *this;
}
String String::CharDelete(char c)
{
    int length = Length();
    for (int i = 0; i < length - 1; i++)
    {
        if (str[i] == c)
        {
            for (int j = i + 1; j < length; j++)
                str[j - 1] = str[j];
            length--;
            i--;
        }
    }
    if (str[length - 1] == c)
        length -= 1;
    char *temp = new char[length];
    copy(str, str + length, temp);
    delete[] str;
    strLength = length;
    str = temp;
    return *this;
}
int String::Compare(String y)
{
    int i = 0;
    int length = Length();
    int yLength = y.Length();
    int minLength = (length < yLength) ? length : yLength;
    while (str[i] == y.str[i] && i < minLength)
        i++;
    if (i == minLength)
    {
        if (yLength > length)
            return -1;
        else if (yLength == length)
            return 0;
        else if (yLength < length)
            return 1;
    }
    else if (i < minLength)
    {
        if (str[i] < y.str[i])
            return -1;
        else if (str[i] > y.str[i])
            return 1;
    }
    return 0;
}
ostream &operator<<(ostream &outs, String &arg)
{
    for (int i = 0; i < arg.Length(); i++)
        outs << arg.str[i];
    return outs;
}
istream &operator>>(istream &ins, String &arg)
{
    for (int i = 0; i < arg.Length(); i++)
    {
        cin.get(arg.str[i]);
        // ins >> arg.str[i];
    }
    return ins;
}

int main()
{
    char *a, *b, *c, enter;
    String strTest(a, 8), strTest1(b, 2), strTest2(c, 0), strOut(c, 0);
    cin >> strTest;
    cout << strTest << endl;
    cin >> strTest1;
    cout << strTest1 << endl;

    // strOut = strTest.Substr(2, 4);
    // cout << "Substr: " << strOut << endl;
    strTest.CharDelete('d');
    cout << strTest << endl;
    strTest2 = strTest.Delete(2, 4);
    cout << "Delete: " << strTest << endl;
    strTest.Concat(strTest1);
    cout << "Concat: " << strTest << endl;
    cout << "Compare: " << strTest.Compare(strTest2) << endl;
}