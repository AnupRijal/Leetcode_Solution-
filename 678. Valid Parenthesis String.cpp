class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        
        // First pass: Treat '*' as '('
        for (char c : s) {
            if (c == '(' || c == '*') {
                openCount++;
            } else {
                openCount--;
            }
            if (openCount < 0) {
                return false;
            }
        }
        
        int closeCount = 0;
        
        // Second pass: Treat '*' as ')'
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            if (closeCount < 0) {
                return false;
            }
        }
        
        return true;
    }
};
