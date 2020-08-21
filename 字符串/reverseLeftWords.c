//剑指 Offer 58 - II. 左旋转字符串
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
char* reverseLeftWords(char* s, int n){
    int len = strlen(s), k = 0;
    char *res = malloc((len+1)*sizeof(char));
    char *p = s + n;
    for(int i = 0; i < len - n; i++){
        res[k++] = p[i];
    }
    for(int i = 0; i < n; i++){
        res[k++] = s[i];
    }
    res[k] = '\0';
    return res;
}
