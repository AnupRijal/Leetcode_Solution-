class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize pointers for nums1 and nums2, and a pointer for the result array
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // While both arrays have elements
        while (i >= 0 && j >= 0) {
            // Compare elements from both arrays and place the larger one at the end of nums1
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them into nums1
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
