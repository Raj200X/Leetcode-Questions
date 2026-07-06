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
    ListNode* nextNode = nullptr;
    ListNode* reverse(ListNode* curr,ListNode* prev,int k){
        if (k==0){
            nextNode = curr;
            return prev;
        }
        ListNode* forward = curr->next;
        curr->next = prev;
        return reverse(forward,curr,k-1);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while (temp!=nullptr){
            size++;
            temp = temp->next;
        }
        if (k>size){
            return head;
        }

    ListNode* newHead = reverse(head, nullptr, k);
        head->next = reverseKGroup(nextNode, k);
        return newHead;
    }
};