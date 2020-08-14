//1290. 二进制链表转整数
//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
//请你返回该链表所表示数字的 十进制值 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* head){

    int n=0;
    struct ListNode *p=head;
    while(p)
    {
        n = n*2 + p->val;
        p = p->next;
    }
    return n;
}
