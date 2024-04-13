/* [LeetCode] Largest Rectangle in Histogram 
    : https://leetcode.com/problems/largest-rectangle-in-histogram/ */

// problem description 
/* Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
   return the area of the largest rectangle in the histogram. */

/* input : heights = [2,1,5,6,2,3] */
/* output : 10 */

/* input : heights = [2,4] */
/* output : 4 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int> indexStack; // 인덱스를 저장할 스택
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int height = (i == n) ? 0 : heights[i]; // 배열의 끝에 도달했을 경우 높이를 0으로 설정
            while (!indexStack.empty() && height < heights[indexStack.top()]) {
                int h = heights[indexStack.top()];
                indexStack.pop();
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;
                max_area = max(max_area, h * width);
            }
            indexStack.push(i);
        }

        return max_area;
    }
};