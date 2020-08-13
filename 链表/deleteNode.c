//237. 删除链表中的节点
//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点。传入函数的唯一参数为 要被删除的节点 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    *node = *(node->next);
}
void deleteNode_1(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
