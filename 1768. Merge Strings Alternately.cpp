class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        //Counting the length of string
        int length_of_a = word1.length(); 
        int length_of_b = word2.length();
        //Adding the total length of character in string for loop 
        int total_length = length_of_a + length_of_b; 
        //Declaring a new string variable to store each element later
        string merged;
        
        //Running the loop for exact number of time  as present character 
        for (int k = 0; k < total_length; k++) {
            //If condition to check if the character in string has finished 
            if (length_of_a != 0) {
                //Storing element in new varaiable
                merged += word1[k]; 
                //Counter to monitor present character
                length_of_a--;
            }
            //If condition to check if the character in string ahs finished 
            if (length_of_b != 0) {
                //Storing element in new varaiable
                merged += word2[k]; 
                //Counter to monitor present character
                length_of_b--; 
            }
        }
        return merged;
    }
};