#include <climits>

class Solution
{
public:
    int isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int rev = 0;
        int og = x;
        while (x != 0)
        {
            int digit = x % 10;
            x = x / 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return false;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
                return false;

            rev = rev * 10 + digit;
        }
        return rev == og;
    }
};