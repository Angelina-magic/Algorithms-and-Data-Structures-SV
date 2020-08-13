//面试题 02.07. 链表相交
//给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。
//换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   struct ListNode *a=headA;
   struct ListNode *b=headB;
   while(a!=b)
   {
       if(a==NULL)
            a=headB;
       else
            a=a->next;
       if(b==NULL)
            b=headA;
       else 
            b=b->next;
   }
   return b;
}
