//1370. 上升下降字符串
//给你一个字符串 s ，请你根据下面的算法重新构造字符串：
//从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
//从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
//重复步骤 2 ，直到你没法从 s 中选择字符。
//从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
//从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
//重复步骤 5 ，直到你没法从 s 中选择字符。
//重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
//在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。
//请你返回将 s 中字符重新排序后的 结果字符串 。

//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/increasing-decreasing-string
char * sortString(char * s){
    
    int* cnt = (int*)malloc(sizeof(int)*26);
    memset(cnt,0,sizeof(int)*26);
    int len = strlen(s);
    int i = len,j=0;

    while(i--)  
        cnt[ s[i] - 'a']++;

    for(i = 0;i<len;) {

        for(j = 0 ; j<26&&i<len ; j++) {
            if(cnt[j]>0) {
                s[i++] = 'a' + j;
                cnt[j]--;
            }
        }

        for(j=25 ; j>=0 && i<len ; j--) {
            if(cnt[j]>0) {
                s[i++] = 'a' + j;
                cnt[j]--;
            }
        }
    }
    return s;
}
