class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        // Sort ranges by starting point, and then by ending point if starting points are equal
        sort(ranges.begin(), ranges.end());

        int mod = 1e9 + 7;
        int n = ranges.size();

        // This will store the number of distinct groups of overlapping ranges
        int groupCount = 0;

        // Variables to keep track of the current group of overlapping ranges
        int currentEnd = -1;

        for (const auto& range : ranges) {
            // If the current range does not overlap with the previous one, we start a new group
            if (range[0] > currentEnd) {
                groupCount++;
                currentEnd = range[1];
            } else {
                // If it overlaps, extend the current end to the maximum end of the overlapping ranges
                currentEnd = max(currentEnd, range[1]);
            }
        }

        // The number of ways to split the groups into two groups is 2^groupCount
        // We need to compute this modulo 1e9 + 7
        long long result = 1;
        for (int i = 0; i < groupCount; ++i) {
            result = (result * 2) % mod;
        }

        return result;
    }
};