#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        l = std::max(l, 0);
        r = std::max(r, 0);
        ans = std::max(ans, l + r + root->val);
        return std::max(l, r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    std::cout << "Max path sum: " << solution.maxPathSum(root) << std::endl;

    // Clean up the memory (not shown in the original code)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
