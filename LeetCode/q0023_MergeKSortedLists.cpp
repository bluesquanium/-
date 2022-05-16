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
#define ll long long

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> nodes;
        vector<int> a;
        for(ll i = 0; i < lists.size(); i++) {
            ListNode* cur = lists[i];
            while(cur != NULL) {
                a.push_back(cur->val);
                nodes.push_back(cur);
                cur = cur->next;
            }
        }
        sort(a.rbegin(), a.rend());
        
        ListNode* ans = NULL;
        for(ll i = 0; i < a.size(); i++) {
            ListNode* t = nodes.back();
            nodes.pop_back();
            t->val = a[i];
            t->next = ans;
            ans = t;
        }
        
        return ans;
    }
};