#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // vector<int> hash(*max_element(nums.begin(), nums.end()) + 1, 0);
    // max_element  returns an iterator pointing to the largest element
    // thus a * is used to deference the element and get its actual value

    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> hashh(n + 1, 0);

        for (int num : arr)
        {
            if (num >= 1 && num <= n)
            {
                hashh[num]++;
            }
        }

        vector<int> result;

        for (int i = 1; i <= n; i++)
        {
            result.push_back(hashh[i]);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--)
    {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.frequencyCount(a);

        // Print the result in the required format
        if (result.empty())
        {
            cout << "[]"; // Print empty brackets if no duplicates are found
        }
        else
        {
            for (int i = 0; i < result.size(); i++)
            {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl; // Ensure new line after each test case output
    }

    return 0;
}