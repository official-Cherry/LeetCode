/* [LeetCode] Contains Duplicate 
    : https://leetcode.com/problems/clone-graph/ */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Graph

class Solution {
public:

    // 방문한 노드 추적을 위한 hashmap
    unordered_map<Node*,Node*> visited;

    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
        {
            return nullptr;
        }

        // 만약 노드가 방문된적 있다면, 복제된 노드 반환
        if(visited.find(node) != visited.end())
        {
            return visited[node];
        }

        // 새 노드 생성 및 방문 기록 
        Node* cloneNode = new Node(node->val,{});
        visited[node] = cloneNode;

        // 이웃 노드들에 대해서도 재귀적으로 복제 
        for(Node* neighbor : node->neighbors)
        {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;

    }
};