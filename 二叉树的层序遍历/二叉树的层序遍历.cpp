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
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
 */
#include <iostream>
#include <vector>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> target;
        if (!root)
            return target;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            // 当前队列中的元素都是同一层的，n为该层元素数目
            int n = que.size();
            // 定义一个容器存储该层的节点的val值
            vector<int> tv;
            while (n--) {
                TreeNode* tn = que.front(); que.pop();
                tv.push_back(tn->val);
                if (tn->left)
                    que.push(tn->left);
                if (tn->right)
                    que.push(tn->right);
            }
            target.push_back(tv);
        }
        return target;
    }
};

