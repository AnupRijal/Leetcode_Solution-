class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int n = s.length();
        int left = 0;
        int max_count = 0; // To store the max frequency of a single character in the current window
        int max_length = 0; // To store the maximum length of the substring found
        vector<int> count(26, 0); // Frequency count of each character in the current window

        for (int right = 0; right < n; ++right) {
            // Update the frequency of the current character
            count[s[right] - 'A']++;
            // Update the max_count with the highest frequency in the current window
            max_count = max(max_count, count[s[right] - 'A']);
            
            // Check if we need to shrink the window
            while (right - left + 1 - max_count > k) {
                // If more than k replacements are needed, move the left pointer
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update the maximum length
            max_length = max(max_length, right - left + 1);
        }
        
        return max_length;
    }
};
