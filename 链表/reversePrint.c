//剑指 Offer 06. 从尾到头打印链表
//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head==0){
        *returnSize=0;
        return 0;
    }
    
    // 逆向链表
    struct ListNode*tmp,*header=head;
    int length=1,i;
    while(head->next!=0){
        length++;
        tmp=head->next;
        head->next=tmp->next;
        tmp->next=header;
        header=tmp;
    }
    *returnSize=length;
    int *res=malloc(length*sizeof(int));
    for(i=0;i<length;i++){
        res[i]=header->val;
        header=header->next;
    }
    return res;
}
