class Solution {
public:
    int splitNum(int num) {
        // Convert the number to a string to easily access individual digits
        string numStr = to_string(num);
        
        // Sort the digits to facilitate the distribution
        sort(numStr.begin(), numStr.end());
        
        // Initialize two numbers as strings
        string num1, num2;
        
        // Distribute the sorted digits alternately between num1 and num2
        for (int i = 0; i < numStr.size(); ++i) {
            if (i % 2 == 0) {
                num1 += numStr[i];
            } else {
                num2 += numStr[i];
            }
        }
        
        // Convert the string representations to integers and sum them up
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        
        return n1 + n2;
    }
};
