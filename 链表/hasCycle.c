//141. 环形链表
//给定一个链表，判断链表中是否有环。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/linked-list-cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while((fast!=NULL)&&(fast->next!=NULL)){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}
