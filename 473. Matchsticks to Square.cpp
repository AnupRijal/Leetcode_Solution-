class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLength % 4 != 0) return false;
        
        int sideLength = totalLength / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        vector<int> sides(4, 0);
        
        return backtrack(matchsticks, sides, sideLength, 0);
    }
    
private:
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int target, int index) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] > target) continue;
            
            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, sides, target, index + 1)) return true;
            sides[i] -= matchsticks[index];
            
            if (sides[i] == 0) break;
        }
        
        return false;
    }
};