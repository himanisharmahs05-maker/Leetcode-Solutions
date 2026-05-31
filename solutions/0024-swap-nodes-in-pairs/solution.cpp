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

        return prev;   // new head after reversal
    }

    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevLeft = NULL;
        int size = 2;

        while (true) {
            right = left;

            for (int i = 0; i < size - 1; i++) {
                if (right == NULL)
                    break;
                right = right->next;
            }

            if (right) {
                ListNode* nextLeft = right->next;

                // reverse current group
                ListNode* newHead = reverse(left, size);

                if (prevLeft)
                    prevLeft->next = newHead;

                if (res == NULL)
                    res = newHead;

                prevLeft = left;      // left becomes tail after reversal
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
