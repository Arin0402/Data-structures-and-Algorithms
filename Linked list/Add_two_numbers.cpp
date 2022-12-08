// https://leetcode.com/problems/add-two-numbers/submissions/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;

        ListNode *head_1 = l1;
        ListNode *head_2 = l2;
        ListNode *head_3 = new ListNode();
        head_3->val = (head_1->val + head_2->val) % 10;
        ListNode *curr = head_3;
        carry = (head_1->val + head_2->val) / 10;

        while (head_1->next && head_2->next)
        {

            curr->next = new ListNode();
            curr = curr->next;
            head_1 = head_1->next;
            head_2 = head_2->next;
            int sum = head_1->val + head_2->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
        }
        while (head_1->next)
        {

            curr->next = new ListNode();
            curr = curr->next;
            head_1 = head_1->next;
            int sum = head_1->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
        }
        while (head_2->next)
        {

            curr->next = new ListNode();
            curr = curr->next;
            head_2 = head_2->next;
            int sum = head_2->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0)
        {
            curr->next = new ListNode();
            curr = curr->next;
            curr->val = carry;
        }

        return head_3;
    }
};
