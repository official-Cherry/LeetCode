#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* [LeetCode] Multiply Strings 
    : https://leetcode.com/problems/multiply-strings/ */

/*
input : two non-negative integers (string)
output : product of num1 and num2 (string)
*/

/* 
 
 문득 스택,큐로 해결할 수 있을 것 같다는 생각이 들었다.
 한자리 씩 곱셈하는 것을 구현 (big integer 를 사용하면 안되기 때문에)

     456
 *   123
   -------
    1368
    912
 + 456 
   -------
 = 56088

*/

class Solution {
public:
    string multiply(string num1, string num2) {
        
        // 두 수 중에 하나라도 0이면 결과는 0 (non-negative라고 했으므로)
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        int n1 = num1.size();
        int n2 = num2.size();

        // 곱셈 결과 가능한 최대길이는 두 숫자의 자릿수 합
        vector<int> result(n1+n2,0);

        // num1의 각 자릿수에 대해 역순으로 반복
        for (int i = n1 - 1; i >= 0; i--) {
            // num2의 각 자릿수에 대해 역순으로 반복
            for (int j = n2 - 1; j >= 0; j--) {
                // 현재 자릿수를 곱함
                int mul = (num1[i] - '0') * (num2[j] - '0');
                // 현재 자릿수 곱셈 결과와 이전 자릿수에서 올림된 값을 더함
                int sum = mul + result[i + j + 1];

                // 현재 위치에 나머지를 저장
                result[i + j + 1] = sum % 10;
                // 올림 값을 다음 위치에 더함
                result[i + j] += sum / 10;
            }
        }

        string resultStr;
        // 결과 벡터를 문자열로 변환. 선행 0은 제외
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) { // 결과 문자열이 비어있지 않거나 숫자가 0이 아닌 경우에만 문자를 추가
                resultStr.push_back(num + '0');
            }
        }

        // 모든 자릿수가 0인 경우를 위해 처리. 결과 문자열이 비어 있다면 "0" 반환
        return resultStr.empty() ? "0" : resultStr;
    
    }
};