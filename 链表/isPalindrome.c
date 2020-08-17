//234. 回文链表
//请判断一个链表是否为回文链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int q[55000];
bool isPalindrome(struct ListNode* head){
    struct ListNode* p = head;
    int len = 0;
    while(p){
        len++;
        q[len] = p->val;
        p = p->next;
    }
    for(int i = 1; i <= len/2; i++){
        if(q[i] != q[len-i+1]) return false;
    }
    return true;
}
