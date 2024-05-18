// apprach : hash set - uses a hash set data structure to store encountered elements
// if an element is already present in the hash set, return true
// Otherwise, add the element to the hash set.

// Time : O(n) Space : O(n)
// O(n) : nums 배열을 순회하며 중복된 원소가 있는지 확인 
// O(n) : unordered_set에 nums 배열의 모든 원소를 저장 (입력크기 n 에 비례)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0)
                return true;
            seen.insert(num);
        }
        return false;
    }
};