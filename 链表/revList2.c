//206. 反转链表
//反转一个单链表。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *per=NULL, *cur=head;
    while(cur){
        struct ListNode* Next=cur->next;
        cur->next = per;
        per = cur;
        cur = Next;
    }
    return per;
}
struct ListNode* reverseList2(struct ListNode* head){
    //当只有一个节点，它的反转就是本身
    if(!head || !head->next)  return head;
    //取出head节点，调用函数自身将head->next为头的链表反转，结果保存在res中
    struct ListNode *res = reverseList(head->next);
    //res的尾巴是head->next，所以需要将之前弹出的head接在此尾巴上
    head->next->next = head;
    head->next = NULL;
    return res;
}
