class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort intervals by their end point, and if they have the same end point, by their start point in descending order
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        int n = intervals.size();
        vector<int> nums; // Contains the integers of the containing set

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // Number of integers already added that fall within the interval
            int count = 0;

            // Check the last two elements of nums to see if they are within the current interval
            if (!nums.empty() && nums.back() >= start) {
                count++;
            }
            if (nums.size() > 1 && nums[nums.size() - 2] >= start) {
                count++;
            }

            // Add necessary integers to ensure at least two integers in the current interval
            if (count == 0) {
                nums.push_back(end - 1);
                nums.push_back(end);
            } else if (count == 1) {
                nums.push_back(end);
            }
        }

        return nums.size();
    }
};
