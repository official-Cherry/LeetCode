/* [LeetCode] Maximal Rectangle 
    : https://leetcode.com/problems/maximal-rectangle/ */

// problem description 
/* given rows * cols binary matrix with 0 and 1 
   find the largest rectangle containing only 1 and return its area (면적) */

/* input : matrix = [["1","0","1","0","0"],
                    ["1","0","1","1","1"],
                    ["1","1","1","1","1"],
                    ["1","0","0","1","0"]] */
/* output : 6 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int max_area = 0;
        int matrix_row = matrix.size();
        int matrix_col = matrix[0].size();

        vector<int> histogram(matrix_col, 0); // 열마다 히스토그램을 구성하기 위한 벡터

        // 각 행에 대해 최대 직사각형을 찾는 코드 
        for(int row = 0; row < matrix_row; row++) {
            stack<int> indexStack;
            
            // 히스토그램 업데이트
            for(int col = 0; col < matrix_col; col++) {
                histogram[col] = (matrix[row][col] == '1') ? histogram[col] + 1 : 0;
            }

            for(int col = 0; col <= matrix_col; col++) {
                int currentHeight = (col == matrix_col) ? 0 : histogram[col];

                // 현재 열의 높이가 스택 맨 위에 있는 높이보다 낮으면 
                while(!indexStack.empty() && currentHeight < histogram[indexStack.top()]) {
                    int h = histogram[indexStack.top()];
                    indexStack.pop();
                    int w = indexStack.empty() ? col : col - indexStack.top() - 1; // 너비계산
                    max_area = max(max_area, h * w); // 최대 면적 갱신 
                }

                // 현재 열의 인덱스를 스택에 푸시 
                indexStack.push(col);
            }
        }

        return max_area;
    }
};
