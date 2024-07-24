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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //the main part is that digits are stored in reverse order
        ListNode* t1= l1;
        ListNode* t2 =l2;
        int carry=0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr =dummy;
        while(t1!= NULL && t2!= NULL)
        {
            int sum = t1->val +t2->val+carry;
            carry =sum/10;
            curr->next = new ListNode(sum%10);
            curr= curr->next;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1!= NULL)
        {
            int sum = t1->val +carry;
            carry =sum/10;
            curr->next =  new ListNode(sum%10);
             curr= curr->next;
            t1=t1->next;
        }
        while(t2!= NULL)
        {
            int sum = t2->val +carry;
            carry =sum/10;
            curr->next =  new ListNode(sum%10);
             curr= curr->next;
            t2=t2->next;
        }
        if(carry != 0)
        {
            curr->next =  new ListNode(carry);
        }
        return dummy->next;
    }
};
