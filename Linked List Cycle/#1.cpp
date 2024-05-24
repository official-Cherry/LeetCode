/* [LeetCode] Linked List Cycle
    : https://leetcode.com/problems/distribute-coins-in-binary-tree/ */
    /* Linkied list cycle*/

// problem description 
/* Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.    */

/* input: head = [3,2,0,-4], pos = 1 */
/* output : true */

/* input: head = [1,2], pos = 0 */
/* output : true */

/* input: head = [1], pos = -1 */
/* output : false */

// constraints
/*
    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 시간 복잡도:
 * - 이 알고리즘은 각 노드를 최대 한 번씩만 방문하므로 O(n)의 시간 복잡도를 가짐
 * - 여기서 n은 리스트의 노드 수
 * 
 * 공간 복잡도:
 * - 이 알고리즘은 추가적인 공간을 거의 사용하지 않으므로 O(1)의 공간 복잡도를 가짐
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // 사이클이 없는 경우를 먼저 처리
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        // 두 개의 포인터 초기화
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        // 두 포인터가 만날 때까지 반복
        while (slow != fast) {
            // 만약 fast 또는 fast의 다음 노드가 null이라면 사이클이 없음
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            // slow는 한 번에 한 노드씩 이동
            slow = slow->next;
            // fast는 한 번에 두 노드씩 이동
            fast = fast->next->next;
        }
        
        // slow와 fast가 만났다면 사이클이 있음
        return true;
    }
};