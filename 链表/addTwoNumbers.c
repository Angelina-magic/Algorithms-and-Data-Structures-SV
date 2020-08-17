//445. 两数相加 II
//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/add-two-numbers-ii著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
struct ListNode* reverseList(struct ListNode* head, int *len){
    struct ListNode *p = NULL, *q = NULL;
    
    while (head) {
        q = head->next;  // q获取下个结点
        head->next = p;  // 将次结点后接上p连上
        p = head;  // p作为头结点
        head = q;  // head继续前进
        *len += 1;  // 计算链表长度(方便后面选最长为l1)
    }
    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (!l1 || !l2) return l1 ? l1 : (l2 ? l2 : NULL);  // 返回非空的链表即可
    int len1 = 0, len2 = 0;
    l1 = reverseList(l1, &len1);
    l2 = reverseList(l2, &len2);
    
    if (len1 < len2) {  // 交换得到最长链表l1
        struct ListNode *tmp = l2;
        l2 = l1;
        l1 = tmp;
    }
    
    struct ListNode *prev = NULL, *curr;
    int carry = 0;
    
    while (l1 || l2) {
        carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        l1->val = carry % 10;
        carry /= 10;
        curr = l1->next;  // curr先保存l1下节点
        l1->next = prev;  // 进行反转操作
        prev = l1;  // prev更新
        l1 = curr;
        l2 = l2 ? l2->next : NULL;
    }
    
    if (carry == 1) {  // 4.进位处理
        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = carry;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}
