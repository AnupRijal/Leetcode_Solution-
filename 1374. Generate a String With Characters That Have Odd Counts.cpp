class Solution {
public:
    std::string generateTheString(int n) {
        // Create a string of 'a' repeated n times
        string result(n, 'a');
        
        // If n is even, change the last character to 'b' to make the count of 'a' odd
        if (n % 2 == 0) {
            result[n - 1] = 'b';
        }
        
        return result;
    }
};