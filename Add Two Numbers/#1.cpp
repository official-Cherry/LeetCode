struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* [LeetCode] Add Two Numbers 
    : https://leetcode.com/problems/add-two-numbers/description/ */

/*
input : two linked list (non-empty)
output : one linked list (=sum of two linked list) ; do not contain any leading zero (except the number 0 itself)
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummyNode = new ListNode();
        ListNode* result = dummyNode;

        int sum = 0;
        int prev_leading = 0;
        int cur_leading = 0;
        int remainder = 0;
        
        // 둘 중 한 리스트가 끝날 때까지 (맨 마지막 노드는 더해지지 않은 상태로 끝남)
        while(true) 
        {
            // 더하기            
            sum = l1->val + l2->val;
            sum += prev_leading; // 전의 올림수를 반영 
            remainder = sum%10; // 올림수를 제외한 나머지 수 
            cur_leading = sum/10; // 현재 올림수 갱신 
                
            // 결과 저장 
            result->next = new ListNode(remainder);
            result = result->next;

            prev_leading = cur_leading; // 현재 올림수를 과거로 넘기기
            cur_leading = 0; // 현재 올림수는 초기화 

            // 둘 중 하나의 리스트가 끝이라면 멈추기 
            if(l1->next == nullptr || l2->next == nullptr){
                break;
            }

            // 포인터 옮기기 
            l1 = l1->next;
            l2 = l2->next;

        }

        if(l1->next == nullptr && l2->next == nullptr)
        {
            if(prev_leading !=0) {
                result->next = new ListNode(prev_leading);
                result = result->next;
            }
            return dummyNode->next;
        }

        // l1이 끝난 경우 
        else if(l1->next == nullptr)
        {
            l2 = l2->next;
            while(true)
            {
                sum = l2->val + prev_leading;
                remainder = sum%10;
                cur_leading = sum/10;
                result->next = new ListNode(remainder);
                result = result->next;

                prev_leading = cur_leading;
                cur_leading = 0;

                if(l2->next == nullptr) {
                    if (prev_leading !=0) {
                        result->next = new ListNode(prev_leading);
                        result = result->next;
                    }
                    break;
                }

                l2 = l2->next;
            }
        }

        // l2가 끝난 경우 
        else if(l2->next == nullptr)
        {
            l1 = l1->next;
            while(true)
            {
                sum = l1->val + prev_leading;
                remainder = sum%10;
                cur_leading = sum/10;
                result->next = new ListNode(remainder);
                result = result->next;

                prev_leading = cur_leading;
                cur_leading = 0;

                if(l1->next == nullptr) {
                    if (prev_leading !=0) {
                        result->next = new ListNode(prev_leading);
                        result = result->next;
                    }
                    break;
                }

                l1 = l1->next;
            }
        }

        return dummyNode->next;
    }
};