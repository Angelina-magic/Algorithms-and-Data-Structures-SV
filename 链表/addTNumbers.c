//面试题 02.05. 链表求和
//给定两个用链表表示的整数，每个节点包含一个数位。
//这些数位是反向存放的，也就是个位排在链表首部。
//编写函数对这两个整数求和，并用链表形式返回结果。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum=0, carry = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = head;

    while(l1 || l2 || carry) {
        sum = 0;
        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum >= 10 ? sum%10 : sum;
        newNode->next = NULL;            
        carry = sum >= 10 ? 1 : 0;
        
        p->next = newNode;
        p = p->next;
    }
    return head->next;

}
