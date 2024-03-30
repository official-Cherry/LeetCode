#include <vector>
using namespace std;

/* [LeetCode] Plus One
    : https://leetcode.com/problems/plus-one/ */

/*
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(); // 배열의 길이
        
        // 배열의 끝에서 시작하여 앞으로 이동
        for (int i = n - 1; i >= 0; i--) {
            // 현재 자릿수가 9가 아니면
            if (digits[i] != 9) {
                digits[i]++; // 현재 자릿수에 1을 더하고
                return digits; // 바로 결과를 반환
            }
            // 현재 자릿수가 9인 경우, 0으로 설정하고 다음 자릿수로 올림 처리
            digits[i] = 0;
        }
        
        // 모든 자릿수를 처리한 후 여기에 도달하면, 숫자가 999...와 같은 형태였음을 의미
        // 결과 배열의 크기를 1 증가시키고, 맨 앞을 1로 설정
        digits.insert(digits.begin(), 1);
        return digits;
    }
};