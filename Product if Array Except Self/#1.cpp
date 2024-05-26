/* [LeetCode] Product of Array Except Self
    : https://leetcode.com/problems/product-of-array-except-self/ */

// problem description 
/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
 */

/* 
input: nums = [1,2,3,4]
output: [24,12,8,6]

input: nums = [-1,1,0,-3,3]
output: [0,0,9,0,0]
*/

// Array 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> answer(n,1); // 모든 위치 1로 초기화 

        int leftProduct = 1;
        for(int i=0;i<n;i++)
        {
            answer[i] = leftProduct; // 현재 위치까지의 왼쪽 요소들 곱 
            leftProduct *= nums[i]; // 다음 위치를 위해 왼쪽 요소들의 곱을 업데이트
        }

        int rightProduct = 1;
        for(int i=n-1;i>=0;i--)
        {
            answer[i] *= rightProduct; // 왼쪽 요소들의 곱에 오른쪽 요소들의 곱을 곱함
            rightProduct *= nums[i]; // 다음 위치를 위해 오른쪽 요소들의 곱을 업데이트
        }

        return answer;
    }
};