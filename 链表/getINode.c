//剑指 Offer 52. 两个链表的第一个公共节点
//输入两个链表，找出它们的第一个公共节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *perA = headA;
    struct ListNode *perB = headB;

    if (!(headA && headB))
        return NULL;

    while (perA != perB) {
        perA = perA ? perA->next : headB;
        perB = perB ? perB->next : headA;
    }
    return perA;

}
