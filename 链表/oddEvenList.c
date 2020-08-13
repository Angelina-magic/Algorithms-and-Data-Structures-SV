//328. 奇偶链表
//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
//请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/odd-even-linked-list

struct ListNode* oddEvenList(struct ListNode* head){
    if(head ==NULL || head->next==NULL) return head;
    struct ListNode* evenHead=head->next;  //记录偶数位置链表的表头，用于最后奇偶相连
    struct ListNode* odd=head;            //奇数位置指针
    struct ListNode* even=odd->next;      //偶数位置指针
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;         //指向后面第二个结点，即把奇数和偶数分开了
        even->next=even->next->next;
        odd=odd->next;
        even=odd->next;
    }
    odd->next=evenHead;
    return head;
}
