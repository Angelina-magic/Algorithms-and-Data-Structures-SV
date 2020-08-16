//1171. 从链表中删去总和值为零的连续节点
//给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
//删除完毕后，请你返回最终结果链表的头节点。
//你可以返回任何满足题目要求的答案。（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeZeroSumSublists(struct ListNode* head){
  struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
	pre->next = head;
	pre->val = 0;
	struct ListNode* p = pre; 
	struct ListNode* q = NULL;
	int sum;

	while(p) {   
    sum = 0;
		q = p->next;

		while(q) {
			sum += q->val;
            
			if(sum == 0) {
				p->next = q->next;
			}
			q = q->next;
		}
		p = p->next;
	}
	return pre->next;
}
