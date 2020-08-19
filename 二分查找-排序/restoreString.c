//1528. 重新排列字符串
//给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
//请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
//返回重新排列后的字符串。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/shuffle-string
char * restoreString(char * s, int* indices, int indicesSize){
    char* temp = (char*)malloc(sizeof(char)*indicesSize);
    for(int i=0; i<indicesSize; i++)
        temp[i] = s[i];
    for(int i=0; i<indicesSize; i++)
        s[indices[i]] = temp[i];

    return s;

}
