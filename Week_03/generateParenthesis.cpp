class Solution {
public:
    vector<string> res;
    void generateAll(int left, int right, int n, string s) {
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }
        
        if (left < n) generateAll(left + 1, right, n, s + "(");
        if (right < left) generateAll(left,  right + 1, n, s + ")");

        return;
    }

    vector<string> generateParenthesis(int n) {
       generateAll(0, 0, n, "");
       return res;
    }
};