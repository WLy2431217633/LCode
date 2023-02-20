#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int a=0, b=0, c=0, sum=0;
        ListNode *head = NULL, **temp = &head;
        
        while(l1||l2)
        {
            a = getValueAndMoveNext(l1);
            b = getValueAndMoveNext(l2);
            sum = a + b + c;  // c进位

            ListNode *LNode = new ListNode(sum%10); // 每一位相加取模
            *temp = LNode;
            temp = &LNode->next;

            c = sum/10;  // 进位多少
        }
        // 存在进位
        if(c > 0)
        {
            ListNode *LNode = new ListNode(c%10);
            *temp = LNode;
        }
        return head;
    }


    int getValueAndMoveNext(ListNode * &l)
    {
        int temp = 0;
        if(l)
        {
            temp = l->val;
            l = l->next;
        }
        return temp;
    }
};

int main()
{
    ListNode *l1;
    

}