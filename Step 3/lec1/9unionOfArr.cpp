#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        vector<int> ans;

        // Using two pointers i and j over the two arrays which helps
        // in storing the smaller element.
        while (i < n && j < m)
        {
            // Updating the pointer i until we have identical
            // elements at consecutive positions in a.
            while (i + 1 < n && a[i] == a[i + 1])
                i++;

            // Updating the pointer j until we have identical
            // elements at consecutive positions in b.
            while (j + 1 < m && b[j] == b[j + 1])
                j++;

            // Comparing elements of the arrays a and b at pointers
            // i and j and accordingly storing the smaller element
            // and updating the pointers.
            if (a[i] < b[j])
                ans.push_back(a[i++]);
            else if (b[j] < a[i])
                ans.push_back(b[j++]);
            else
            {
                // If a[i] is the same as b[j], we update both pointers.
                ans.push_back(b[j++]);
                i++;
            }
        }

        // Storing the remaining elements of the first array (if there are any).
        while (i < n)
        {
            // Updating the pointer i until we have identical
            // elements at consecutive positions in a.
            while (i + 1 < n && a[i] == a[i + 1])
            {
                i++;
            }

            // Storing the elements.
            ans.push_back(a[i++]);
        }

        // Storing the remaining elements of the second array (if there are any).
        while (j < m)
        {
            // Updating the pointer j until we have identical
            // elements at consecutive positions in b.
            while (j + 1 < m && b[j] == b[j + 1])
            {
                j++;
            }

            // Storing the elements.
            ans.push_back(b[j++]);
        }

        // Returning the list containing the union of the two arrays.
        return ans;
    }
};