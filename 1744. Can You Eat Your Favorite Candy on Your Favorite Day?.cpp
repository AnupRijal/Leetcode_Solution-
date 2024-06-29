class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefixSum(n + 1, 0);
        
        // Compute the prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + candiesCount[i];
        }
        
        vector<bool> answer;
        
        for (const auto& query : queries) {
            int favoriteType = query[0];
            int favoriteDay = query[1];
            int dailyCap = query[2];
            
            long long minCandiesNeeded = favoriteDay + 1; // At least one candy per day
            long long maxCandiesPossible = static_cast<long long>(favoriteDay + 1) * dailyCap;
            
            long long candiesBefore = prefixSum[favoriteType];
            long long candiesAvailable = prefixSum[favoriteType + 1];
            
            bool canEat = (minCandiesNeeded <= candiesAvailable) && (maxCandiesPossible > candiesBefore);
            answer.push_back(canEat);
        }
        
        return answer;
    }
};
