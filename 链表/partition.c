//86. 分隔链表
//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
//你应当保留两个分区中每个节点的初始相对位置。
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode*p1Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode*p2Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode*p1=p1Head;
    struct ListNode*p2=p2Head;
    struct ListNode*p=head;

    while(p){
        if(p->val<x){
            p1->next=p;
            p1=p;
        }
        else{
            p2->next=p;
            p2=p;
        }
        p=p->next;
    }
    p2->next=NULL;
    p1->next=p2Head->next;
    return p1Head->next;

}
