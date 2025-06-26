int xorRange(int N)
{
    if (N % 4 == 0)
        return N;
    else if (N % 4 == 1)
        return 1;
    else if (N % 4 == 2)
        return N + 1;
    else
        return 0; // N % 4 == 3
}

class Solution
{
public:
    int findRangeXOR(int l, int r)
    {
        return xorRange(r) ^ xorRange(l - 1);
    }
};
