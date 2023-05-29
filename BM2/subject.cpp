#include <iostream>
#include <stack>


struct  ListNode
{
    ListNode *next;
    int val;
};


cclass Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if(nullptr == head || head->next == nullptr || m == n){
            return head;
        }

        ListNode *mhead = head;
        size_t i = 1;
        for (; i < m; i++)
        {
            mhead = mhead->next;
        };

        std::stack<int> stk;

        ListNode *nhead = mhead;
        for (; i <= n; i++)
        {
            stk.push(nhead->val);
            nhead = nhead->next;
        }
        

        while (mhead != nhead)
        {
            mhead->val = stk.top();
            stk.pop();
            mhead = mhead->next;
        }

        return head;

    }
};