/* [LeetCode] Regular Expression Matching
    : https://leetcode.com/problems/regular-expression-matching/ */

// input : string s , pattern p
// rule : '.' - matches any single character 
// rule : '*' - matches zero or more of the preceding element (앞 문자의 0번이상 반복)
// output : true/false

// Example
// s = "aa" , p = "a" -> false ; "a" does not match the entire string "aa"
// s = "aa" , p = "a*" -> true ; 
// s = "ab" , p = ".*" -> true ; 

// 접근 1 : Dynamic Programming
// 문자열 s 와 패턴 p 간의 일치 여부를 부분적으로 확인하며 최종적으로 일치하는지 확인함 
// dp[i][j] <- 문자열 s의 첫 i 개와 패턴 p의 첫 j 개의 문자들이 일치하는지 bool 값으로 나타냄 

class Solution {
public:
    bool isMatch(string s, string p) {

        int len_s = s.length(); 
        int len_p = p.length();

        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1,false));
        dp[0][0] = true; 

        // s 제약 조건을 보면 1 <= s.length <= 20 -> s가 비어있는 경우는 없으므로 따로 처리 필요 없음 
        
        // 패턴 p 에 따라 dp 초기화 
        for(int j=1; j <= len_p; j++) {
            if(p[j-1] == '*' && dp[0][j-2])
            {
                dp[0][j] = true;
            }
        }

        // p가 . 인 경우  // p가 * 인 경우 -> 나눠서 생각 
        for(int i = 1; i <= len_s; i++) {
            for(int j = 1; j<=len_p; j++) {
                // 1: . 이거나 s == p 인 경우 
                if(p[j-1] == '.' || p[j-1] == s[i-1]) 
                {
                    dp[i][j] = dp[i-1][j-1]; // 직전 condition 이어 받음 (앞에서 false 였으면 지금 match 되어도 true 가 아님)
                }
                else if(p[j-1] == '*') 
                {
                    // 1번 이상 반복 
                    if(j>1 && (p[j-2] == '.' || p[j-2] == s[i-1]))
                    {
                        dp[i][j] = dp[i][j] || dp[i-1][j]; // 예시 ) s = aaa , p = a*
                    }
                    // 0번 반복
                    dp[i][j] = dp[i][j] || dp[i][j-2]; // 예시 ) s = ab , p = abc* 즉, 문자가 0번 반복된다고 했을 때 그 전의 상태를 이어받음
                }
            }
        }

        return dp[len_s][len_p];

    }
};