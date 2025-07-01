class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ngeMap; // stores next greater for each element in nums2
        stack<int> st;

        // Step 1: Build NGE map for all elements in nums2
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int curr = nums2[i];

            while (!st.empty() && st.top() <= curr)
            {
                st.pop();
            }

            if (st.empty())
            {
                ngeMap[curr] = -1;
            }
            else
            {
                ngeMap[curr] = st.top();
            }

            st.push(curr);
        }

        // Step 2: Build result for nums1 using ngeMap
        vector<int> result;
        for (int num : nums1)
        {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};
