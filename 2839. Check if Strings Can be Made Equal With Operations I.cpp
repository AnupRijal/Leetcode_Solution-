class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Extract characters at even indices (0 and 2)
        char s1_even[2] = { s1[0], s1[2] };
        char s2_even[2] = { s2[0], s2[2] };
        
        // Extract characters at odd indices (1 and 3)
        char s1_odd[2] = { s1[1], s1[3] };
        char s2_odd[2] = { s2[1], s2[3] };
        
        // Sort the characters
        sort(s1_even, s1_even + 2);
        sort(s2_even, s2_even + 2);
        sort(s1_odd, s1_odd + 2);
        sort(s2_odd, s2_odd + 2);
        
        // Compare sorted characters
        return (s1_even[0] == s2_even[0] && s1_even[1] == s2_even[1]) &&
               (s1_odd[0] == s2_odd[0] && s1_odd[1] == s2_odd[1]);
    }
};