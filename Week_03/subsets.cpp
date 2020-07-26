class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> &nums, vector<int> sub, int level) {
        if (level == nums.size()) {
            result.push_back(sub);
            return;
        }

        dfs(nums, sub, level + 1);
        sub.push_back(nums[level]);
        dfs(nums, sub, level + 1);

        sub.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> sub;
       dfs(nums, sub, 0);
       return result;
    }
};