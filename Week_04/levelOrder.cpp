/*102. 二叉树的层序遍历*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> res;
       vector<int> r;
       if (!root) return res;
       queue<TreeNode *> q;
       q.push(root);
       while(!q.empty()){
           int count =  q.size();
           while(count > 0) {
               TreeNode *tmp = q.front();
               q.pop();
               r.push_back(tmp->val);
               if (tmp->left) q.push(tmp->left);
               if (tmp->right) q.push(tmp->right);

               count--;
           }
           res.push_back(r);
           r.clear();
       }
       return res;
    }
};