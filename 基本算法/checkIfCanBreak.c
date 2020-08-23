//1433. 检查一个字符串是否可以打破另一个字符串
//给你两个字符串 s1 和 s2 ，它们长度相等，请你检查是否存在一个 s1  的排列可以打破 s2 的一个排列，或者是否存在一个 s2 的排列可以打破 s1 的一个排列。
//字符串 x 可以打破字符串 y （两者长度都为 n ）需满足对于所有 i（在 0 到 n - 1 之间）都有 x[i] >= y[i]（字典序意义下的顺序）。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/check-if-a-string-can-break-another-string
int cmp (const void *_a, const void *_b) 
{
    char *a = (char *)_a;
    char *b = (char *)_b;
    //return strcmp(*a, *b); // 单个字符比较使用strcmp较为耗时，会超出时间限制
    return *a - *b;

}

bool checkIfCanBreak(char * s1, char * s2)
{
    int i;
    int length  = strlen(s1);

    qsort(s1, length, sizeof(char), cmp);
    qsort(s2, length, sizeof(char), cmp);
    int flag = strcmp(s1, s2);

    if (flag > 0) {
        for(i = 0; i < length; i++) {
            if (s1[i] < s2[i]) {
                return false;
            } 
        }
    } else if (flag == 0) {
        return true;
    } else {
        for(i = 0; i < length; i++) {
            if (s2[i] < s1[i]) {
                return false;
            } 
        }
    }
    return true;
}
