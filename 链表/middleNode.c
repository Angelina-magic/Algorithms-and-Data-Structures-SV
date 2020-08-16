//876. 链表的中间结点
//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *per = head;
    int n = 0;
    while(per) {
        ++n;
        per = per->next;
    }
    per = head;
    for(int k = 0;k < n/2; ++k){
        per = per->next;
    }
    return per;
}
