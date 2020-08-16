//25. K 个一组翻转链表
//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//k 是一个正整数，它的值小于或等于链表的长度。
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
//反转函数
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *prev = NULL, *cur = head, *next = head->next;
    while (next != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    return cur;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int i = 0;
    struct ListNode *ret = NULL, *tempHead = NULL, *cur = head;
    for (i = 0; i < k - 1 && cur != NULL; i++)
        cur = cur->next;
    if (cur == NULL)
        return head;
    tempHead = cur->next;
    cur->next = NULL;
    ret = reverse(head);
    head->next = reverseKGroup(tempHead, k);
    return ret;
}
