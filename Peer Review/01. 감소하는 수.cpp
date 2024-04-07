#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
문제 링크: https://www.acmicpc.net/problem/1038
문제 이름: [1038번] 감소하는 수
카테고리: BEAKJOON
*/

// 1. 벡터의 크기와 초기화 
// : 실제 필요한 최대 크기가 1022 임을 고려할 때, 불필요한 메모리 할당을 줄이면 좋겠다고 생각

// 2. 마지막 숫자 자리보다 작은 숫자를 덧붙여 감소하는 수를 찾는 방법 
// 2.1. 큐를 사용하여 해결
// : 동적 크기 조정, 인덱스 초과 방지 

// 3. 변수명

// 감소하는 수를 찾는 함수 
long long findNthDecreasingNumber(int n) {
    
    if (n > 1022) return -1;
    if (n == 0) return 0;
    if (n <= 9) return n;
    
    // 감소하는 수를 저장할 큐 선언 
    queue<long long> decreasingNumbers;

    // 1부터 9까지 각 숫자를 큐에 초기값으로 삽입 
    for (int digit = 1; digit <= 9; digit++) {
        decreasingNumbers.push(digit); 
    }

    int count = 0; // 찾은 감소하는 수의 개수 
    long long currentNumber = 0; // 현재 처리 중인 감소하는 수 

    // 큐가 비어있지 않은 동안 반복 
    while (!decreasingNumbers.empty()) {

        // 큐의 맨 앞에 있는 수를 꺼냄 
        currentNumber = decreasingNumbers.front();
        decreasingNumbers.pop();

        count++; // 감소하는 수의 개수를 하나 증가 
        if(count == n) return currentNumber; // n번째 감소하는 수를 찾음

        // 현재 감소하는 수의 마지막 숫자
        int lastDigit = currentNumber % 10;

        // 마지막 숫자보다 작은 모든 숫자에 대해 
        for(int nextDigit = 0; nextDigit < lastDigit; nextDigit++) {
            // 새로운 감소하는 수를 만들어 큐에 삽입 
            long long newNumber = currentNumber*10 + nextDigit;
            decreasingNumbers.push(newNumber);
        }
    }

    return  -1; // 이론적으로 여기에 도달할 일은 없음 
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; // 찾을 감소하는 수의 번호
    cin >> N;
    cout << findNthDecreasingNumber(N);
    return 0;
    
}