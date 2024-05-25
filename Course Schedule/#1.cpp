/* [LeetCode] Course Schedule
    : https://leetcode.com/problems/course-schedule/ */

// problem description 
/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false. */

/* 
input: numCourses = 2, prerequisites = [[1,0]]
output: true

input: numCourses = 2, prerequisites = [[1,0],[0,1]]
output: false
*/

// Graph 
// 방향그래프에서 사이클이 있는지 여부를 확인
// 사이클이 없으면 모든 과목을 수강할 수 있음
// 사이클이 있으면 일부 과목을 수강하는 것이 불가능 
// DFS 사용 


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0); // 방문 x = 0 초기화 

        // 그래프를 인접리스트로 구성
        for(const auto& p : prerequisites) // 원본 객체 상수 참조 
        {
            graph[p[1]].push_back(p[0]); // (선수과목)을 인덱스로 하는 리스트  
        }

        // 모든 노드에 대해 DFS를 수행하여 사이클을 찾는다 
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i] == 0 && isCyclic(i,graph,visited))
            {
                return false;
            }
        }

        // 사이클이 없으면 모든 과목 수강 가능 
        return true;
    }

private:
    bool isCyclic(int curr, vector<vector<int>>& graph, vector<int>& visited) {
        
        if(visited[curr] == 1) return true; // 순환발견
        if(visited[curr] == 2) return false; // 이미 방문한 노드 


        visited[curr] = 1; // 현재 노드 방문 중으로 표시 
        for(int neighbor : graph[curr]) 
        {
            if(visited[neighbor]!=2 && isCyclic(neighbor,graph,visited))
            {
                return true;
            }
        }

        visited[curr] = 2; // 현재 노드의 방문을 완료로 표시 
        return false;

    }

};