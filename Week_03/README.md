### 第三周学习笔记
#### 本周主要学习内容
1. 泛型递归以及树的递归
2. 分治、回溯

回溯算法解题核心的框架：

```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```


可以看下具体应用：
题目是：[78子集](https://leetcode-cn.com/problems/subsets/)
```c++
class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> &nums, vector<int> sub, int level) {
        //终止条件
        if (level == nums.size()) {
            result.push_back(sub);
            return;
        }

        //做选择
        dfs(nums, sub, level + 1);  //不选当前的数
        sub.push_back(nums[level]);
        dfs(nums, sub, level + 1);  //选当前的数

        sub.pop_back();//撤销选择
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> sub;
       dfs(nums, sub, 0);
       return result;
    }
};
```
