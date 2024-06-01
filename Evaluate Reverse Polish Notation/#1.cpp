/* [LeetCode]
    : https://leetcode.com/problems/binary-tree-level-order-traversal*/

// Reverse Polish Notation => 연산자가 피연산자 뒤에 오는 방식 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for(const string& token:tokens)
        {
            if(isOperator(token))
            {
                // 두개의 피연산자 가져오기 
                int secondOperand = stack.top();
                stack.pop();
                int firstOperand = stack.top();
                stack.pop();

                // 계산 결과를 스택에 다시 넣기
                stack.push(calculate(firstOperand, secondOperand, token));
            }
            else
            {
                // 피연산자는 스택에 넣기 
                stack.push(stoi(token));
            }
        }

        return stack.top();
    }

private:
    bool isOperator(const string& token){
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int calculate(int op1, int op2, const string& op)
    {
        if(op=="+") return op1+op2;
        if(op=="-") return op1-op2;
        if(op=="*") return op1*op2;
        if(op=="/") return op1/op2;
        return 0;
    }
    

};