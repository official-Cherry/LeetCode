/* [LeetCode] Contains Duplicate 
    : https://leetcode.com/problems/contains-duplicate/ */

// problem description 
/* Given an integer array nums, return true if any value appears at least twice in the array, 
    and return false if every element is distinct. */

/* input : nums = [1,2,3,1] */
/* output : true */

/* input : nums = [1,2,3,4] */
/* output : false */

/* input : nums = [1,1,1,3,3,4,3,2,4,2] */
/* output : true */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // 원소가 하나인 경우 (중복이 있을 수 없음)
        if(nums.size() == 1){
            return false;
        }
        
        // 같은 원소가 있는지 확인하기 위해 먼저 정렬
        sort(nums.begin(),nums.end());

        // 연속된 원소의 차가 0이면 같은 원소 (중복)
        for(int cur=0;cur<=nums.size()-2;cur++){
            if(nums[cur]-nums[cur+1]==0){
                return true;
            }
        }

        return false;

    }
};