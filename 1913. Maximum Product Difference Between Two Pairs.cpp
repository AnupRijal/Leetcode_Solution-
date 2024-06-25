
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // Initialize variables to hold max and min values
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        // Find the largest and second largest values
        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
            
            // Find the smallest and second smallest values
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        
        // Calculate the product differences
        int productDiff1 = max1 * max2 - min1 * min2;
        int productDiff2 = max1 * min1 - max2 * min2;
        
        // Return the maximum product difference
        return max(productDiff1, productDiff2);
    }
};