//剑指 Offer 24. 反转链表
//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* per=NULL,* cur = head;
    struct ListNode* net;
    while(cur) {
        net = cur->next;
        cur->next = per;
        per = cur;
        cur = net;
    }
    return per;
}
