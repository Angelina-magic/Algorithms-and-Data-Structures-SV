//434. 字符串中的单词数
//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//请注意，你可以假定字符串里不包括任何不可打印的字符。
int countSegments(char * s)
{
    int count = 0;
    char *p = s;
    int flag = 0;
    while (*p != '\0') {
        if (*p != ' ') {
            flag = 1;
        }
        if (*p == ' ' && flag == 1) {
            count += 1;
            flag = 0;
        }
        p++;
    }
    return count + (flag == 1);
}
