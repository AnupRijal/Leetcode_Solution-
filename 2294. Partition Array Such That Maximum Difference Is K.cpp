class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Initialize the count of subsequences
        int count = 0;
        int i = 0;
        int n = nums.size();
        
        // Iterate through the sorted array
        while (i < n) {
            // Start a new subsequence
            count++;
            int j = i;
            
            // Find the maximum j such that nums[j] - nums[i] <= k
            while (j < n && nums[j] - nums[i] <= k) {
                j++;
            }
            
            // Move to the next element after the current subsequence
            i = j;
        }
        
        return count;
    }
};