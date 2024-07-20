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
    int getDecimalValue(ListNode* head) {
        if(head == NULL)
        return 0;
        vector<int> arr;
        while(head != NULL)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        int n=arr.size();
        int ans=0;
        int t=0;
       for(int i=n-1;i>=0;i--)
       {
        ans += arr[i] * pow(2, t);
        t++;
       }
        return ans;

    }
};
