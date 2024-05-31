/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid; // Found the pick
            } else if (result == 1) {
                left = mid + 1; // Pick is higher
            } else {
                right = mid - 1; // Pick is lower
            }
        }
        return -1; // This line should never be reached if the input is valid
    }
};