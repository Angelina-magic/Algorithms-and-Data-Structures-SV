//面试题 02.01. 移除重复节点
//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeDuplicateNodes(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    int* occurred = (int*)calloc(20001, sizeof(int));
    occurred[head->val] = 1;，
    struct ListNode* pos = head;
    // 枚举前驱节点
    while (pos->next != NULL) {
        // 当前待删除节点
        struct ListNode* cur = pos->next;
        if (!occurred[cur->val]) {
            occurred[cur->val] = 1;
            pos = pos->next;
        } else {
            pos->next = pos->next->next;
        }
    }
    pos->next = NULL;
    return head;
}
