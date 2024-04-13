/* [LeetCode] Maximum Score of a Good Subarray
    : https://leetcode.com/problems/maximum-score-of-a-good-subarray/ */

// problem description 
/* You are given an array of integers nums (0-indexed) and an integer k.
    The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). 
    A good subarray is a subarray where i <= k <= j.
    Return the maximum possible score of a good subarray. */

/* input : nums = [1,4,3,7,4,5], k = 3 */
/* output : 15 */
// explanation : The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 

/* input : nums = [5,5,4,5,4,1,1,1], k = 0 */
/* output : 20 */
// explanation : The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int max_score = nums[k]; // k 자체로 부분 배열을 형성할 수 있으므로 시작점
        int min_value = nums[k]; // 현재 부분 배열의 최솟값
        int left = k; // 왼쪽 포인터
        int right = k; // 오른쪽 포인터
        int n = nums.size();

        while (left > 0 || right < n - 1) {
            // 확장 가능 여부 판단
            if (left == 0) {
                right++;
            } else if (right == n - 1) {
                left--;
            } else if (nums[left - 1] < nums[right + 1]) {
                right++;
            } else {
                left--;
            }

            // 최솟값 업데이트
            min_value = min(min_value, min(nums[left], nums[right]));
            // 최대 점수 갱신
            max_score = max(max_score, min_value * (right - left + 1));
        }

        return max_score;
    }
};