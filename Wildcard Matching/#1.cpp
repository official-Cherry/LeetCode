/* [LeetCode] Wildcard Matching 
    : https://leetcode.com/problems/wildcard-matching/ */

// input : string s , pattern p 
// rule : '?' - matches any single character
// rule : '*' - matches any sequence of characters (including the empty sequence)
// output : true/false

// Example
// s = 'aa' , p = '*' -> matches any sequence
// s = 'cb' , p = '?a' -> ? 는 matches , but second letter doesn't match

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();

        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true;

        // 0 <= s.length, p.length <= 2000 -> s와 p 가 빈 문자열인 case 가 존재함 
        if(len_s == 0 && len_p == 0) return true;
        else if(len_s != 0 && len_p == 0) return false;

        // 패턴 p 에 따라 초기화 
        for(int j=1; j <= len_p && p[j-1] == '*'; j++)
        {
            dp[0][j] = true;
        }

        // p 가 ? 인 경우 // p 가 * 인 경우 
        for(int i=1;i <= len_s; i++) {
            for(int j=1; j <= len_p; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j]; // 1. *가 0개의 문자와 매치 // 2. *가 1개이상의 문자와 매치
                }
                else if(p[j-1] == '?' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[len_s][len_p];

    }
};