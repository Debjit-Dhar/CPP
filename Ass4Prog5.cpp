#include <iostream>

using namespace std;

class STRING
{
private:
    char *str;
    int size;
    int *ref_count;

public:
    STRING(int sz = 0)
    {
        size = sz;
        str = new char[sz + 1];
        for (int i = 0; i < sz; i++)
            str[i] = ' ';
        str[sz] = '\0';
        ref_count = new int(1);
    }

    STRING(const STRING &s)
    {
        size = s.size;
        str = new char[size + 1];
        for (int i = 0; i < size; i++)
            str[i] = s.str[i];
        str[size] = '\0';
        ref_count = s.ref_count;
        (*ref_count)++;
    }

    STRING(char s[], int sz)
    {
        size = sz;
        str = new char[size + 1];
        for (int i = 0; i < size; i++)
            str[i] = s[i];
        str[size] = '\0';
        ref_count = new int(1);
    }

    ~STRING()
    {
        (*ref_count)--;
        if (*ref_count == 0)
        {
            delete[] str;
            delete ref_count;
        }
    }

    STRING &operator=(const STRING &s)
    {
        if (this == &s)
            return *this;

        delete[] str;
        size = s.size;
        str = new char[size + 1];
        for (int i = 0; i < size; i++)
            str[i] = s.str[i];
        str[size] = '\0';
        ref_count = s.ref_count;
        (*ref_count)++;

        return *this;
    }

    STRING operator+(const STRING &s)
    {
        int newSize = size + s.size;
        char *newStr = new char[newSize + 1];

        for (int i = 0; i < size; i++)
            newStr[i] = str[i];
        for (int i = 0; i < s.size; i++)
            newStr[size + i] = s.str[i];

        newStr[newSize] = '\0';
        STRING temp(newStr, newSize);
        return temp;
    }

    int operator<(const STRING &s) const
    {
        int min = size < s.size ? size : s.size;
        for (int i = 0; i < min; i++)
        {
            if (str[i] < s.str[i])
                return 1;
        }

        if (size == s.size)
            return 0;

        return 1;
    }

    int operator>(const STRING &s) const
    {
        int min = size < s.size ? size : s.size;
        for (int i = 0; i < min; i++)
        {
            if (str[i] < s.str[i])
                return 0;
        }

        if (size == s.size)
            return 0;

        return 1;
    }

    int operator==(const STRING &s) const
    {
        if (size != s.size)
            return 0;

        for (int i = 0; i < size; i++)
        {
            if (str[i] != s.str[i])
                return 0;
        }

        return 1;
    }
};

int main()
{
    STRING str1(10);
    char s1[6] = {'D', 'e', 'b', 'j', 'i', 't'};
    char s2[4] = {'D', 'h', 'a', 'r'};

    STRING str2(s1, 6);
    STRING str3(s2, 4);

    cout << (str2 > str3) << '\n';
    cout << (str2 < str3) << '\n';
    cout << (str2 == str3) << '\n';

    str1 = str2;

    return 0;
}
