/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    set<int> Dele;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete) Dele.insert(i);
        helper(root, res, Dele, true);
        return res;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& res, set<int>& Dele, bool isRoot){
        if(node == NULL) return NULL;
        bool deleted = Dele.find(node->val) != Dele.end();
        if(isRoot && !deleted) res.push_back(node);
        node->left = helper(node->left, res, Dele, deleted);
        node->right = helper(node->right, res, Dele, deleted);
        return deleted ? NULL : node;
    }
};