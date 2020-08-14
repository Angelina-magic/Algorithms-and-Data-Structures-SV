//面试题 02.02. 返回倒数第 k 个节点
//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
	struct ListNode *t = head;
	while (k--){
		t = t->next;
	}
	while (t){
		t = t->next;
		head = head->next;
	} 
    
	return head->val;

}
