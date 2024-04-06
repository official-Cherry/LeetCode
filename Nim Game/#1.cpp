/* [LeetCode] Nim Game
    : https://leetcode.com/problems/nim-game/ */

// input : integer n ; number of stones 
// output : true/false (I win or lose)

// Example (항상 내가 시작)
// input 4 -> output false
// 내가 remove 1 -> 친구가 3개 ; 짐
// 내가 remove 2 -> 친구가 2개 ; 짐
// 내가 remove 3 -> 친구가 1개 ; 짐 

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};