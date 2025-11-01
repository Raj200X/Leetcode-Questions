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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int > mp;
        for (auto &p : nums){
            mp[p]++;
        }
         while (head != NULL && mp.count(head->val)) {
            head = head->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            if (mp.count(curr->val)) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
