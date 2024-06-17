class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n); // Initialize ans with size 2 * n

        // Fill the ans array using a single loop
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];       // First half of ans
            ans[i + n] = nums[i];   // Second half of ans
        }

        return ans;
    }
};