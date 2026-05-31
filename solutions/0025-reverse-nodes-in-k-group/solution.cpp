/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (k--) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevLeft = NULL;

        while (true) {
            right = left;

            // Check if k nodes exist
            for (int i = 0; i < k - 1; i++) {
                if (right == NULL)
                    break;
                right = right->next;
            }

            if (right) {
                ListNode* nextLeft = right->next;

                ListNode* newHead = reverse(left, k);

                if (prevLeft)
                    prevLeft->next = newHead;

                if (res == NULL)
                    res = newHead;

                prevLeft = left;   // old head becomes tail
                left = nextLeft;
            }
            else {
                if (prevLeft)
                    prevLeft->next = left;

                if (res == NULL)
                    res = left;

                break;
            }
        }

        return res;
    }
};
