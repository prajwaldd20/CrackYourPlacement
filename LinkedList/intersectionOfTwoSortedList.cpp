/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
    int n1=0, n2=0;
    while(temp!=NULL)
    {
        n1++;
        temp=temp->next;
    }
    temp= headB;
    while(temp!=NULL)
    {
        n2++;
        temp =temp->next;
    }
    int diff;
    if(n1>n2)
    {
        diff = n1-n2;
    }
    else{
        diff= n2-n1;
    }
    ListNode* first=headA;
    ListNode* second =headB;
    if(n1>n2)
    {
        while(diff--)
        {
            first= first->next;
        }
    }
    else if(n2>n1)
    {
        while(diff--)
        {
            second = second->next;
        }
    }

    while(first!=second)
    {
        first = first->next;
        second = second->next;
    }
    if(first == second)
    {
        return first;
    }
    else{
        return nullptr;
    } 
    }
};
