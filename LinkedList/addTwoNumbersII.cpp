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
        
        //create 2 stacks and store list nodes in it

        stack<int> st1;
        stack<int> st2;

        ListNode* temp = l1;

        while(temp)
        {
            st1.push(temp->val);
            temp = temp->next;
        }

        temp = l2;

        while(temp)
        {
            st2.push(temp->val);
            temp = temp->next;
        }


        // create a dummy node to store ans list
        ListNode* ans = new ListNode();

        ListNode* curr = ans;
        int sum = 0;
        int carry = 0;
        while(!st1.empty() || !st2.empty())
        {
           
            // if st1 contains value
            if(!st1.empty())
            {
                sum += st1.top();
                st1.pop();
            }
            // if st2 contains value
            if(!st2.empty())
            {
                sum+= st2.top();
                st2.pop();
            }
            ans->val = sum %10 ;

            carry = sum/10;
            
            ListNode* newNode = new ListNode(carry );
            newNode->next = ans;
            ans =newNode;
            sum = carry;
        }


        if(carry == 0)
        {
            return ans->next;
        }
        else
        {
            return ans;
        }


    }
};
