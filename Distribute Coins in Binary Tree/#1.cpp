/* [LeetCode] Ditribute Coin in Binary Tree
    : https://leetcode.com/problems/distribute-coins-in-binary-tree/ */

// problem description 
/* You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. 
    There are n coins in total throughout the whole tree.
    In one move, we may choose two adjacent nodes and move one coin from one node to another. 
    A move may be from parent to child, or from child to parent.
    Return the minimum number of moves required to make every node have exactly one coin. */

/* input: root = [3,0,0] */
/* output : 2 */

/* input: root = [0,3,0] */
/* output : 3 */

// constraints
/*
    The number of nodes in the tree is n.
    1 <= n <= 100
    0 <= Node.val <= n
    The sum of all Node.val is n.
*/

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

/*
 * 시간 복잡도:
 * - 이 알고리즘은 트리의 각 노드를 정확히 한 번씩 방문하므로 O(n)의 시간 복잡도를 가짐
 * - 여기서 n은 트리의 노드 수
 * 
 * 공간 복잡도:
 * - 이 알고리즘은 재귀 호출을 사용하므로 재귀 호출 스택의 깊이가 최대 트리의 높이만큼 필요
 * - 이진 트리의 높이는 최악의 경우 O(n) (즉, 트리가 한쪽으로 치우쳐 있는 경우) 이고, 평균적으로 O(log n)임
 * - 따라서 공간 복잡도는 O(h)이고, 여기서 h는 트리의 높이
*/

class Solution {
public:
    int moves; // 총 이동 횟수를 저장하는 변수

    // 각 서브트리의 코인 불균형을 계산하는 헬퍼 함수
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        // 왼쪽과 오른쪽 서브트리의 불균형을 계산
        int left = dfs(node->left);
        int right = dfs(node->right);

        // 현재 노드에서 필요한 이동 횟수를 추가
        moves += abs(left) + abs(right);

        // 현재 노드의 불균형을 반환 (현재 노드의 코인 수 - 1 + 왼쪽 불균형 + 오른쪽 불균형)
        return node->val - 1 + left + right;
    }

    int distributeCoins(TreeNode* root) {
        moves = 0; // 이동 횟수를 0으로 초기화
        dfs(root); // DFS 탐색 시작
        return moves; // 총 이동 횟수를 반환
    }

};