class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size(); // Get the length of the string

        // Initialize an array to store the last index of each character
        // -1 means the character hasn't been seen yet
        int hash[256]; // For all ASCII characters
        fill(hash, hash + 256, -1);

        int l = 0;      // Left pointer of sliding window
        int maxlen = 0; // To store the maximum length

        for (int r = 0; r < n; r++)
        {
            // If the character has appeared before and is within the current window
            if (hash[s[r]] >= l)
            {
                // Move the left pointer just after the last occurrence
                l = hash[s[r]] + 1;
            }

            // Update the last seen index of the character
            hash[s[r]] = r;

            // Update the maximum length
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
