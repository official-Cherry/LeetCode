/* [LeetCode]
    : https://leetcode.com/problems/binary-tree-level-order-traversal/ */

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(!root) return result; // root 가 null 인 경우 

        queue<TreeNode*> q; // BFS 를 위한 큐 
        q.push(root);

        while(!q.empty()) 
        {
            int size = q.size(); // 현재 레벨의 노드 수 
            vector<int> currentLevel;

            for(int i=0;i<size;i++) // 현재 레벨 모든 노드 순회 
            {
                TreeNode* node = q.front();
                q.pop(); // 방문한 노드 제거 
                currentLevel.push_back(node->val); 

                // 자식 노드가 있으면 큐에 추가
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result.push_back(currentLevel); // 현재 레벨의 결과 
        }

        return result;
    }
};