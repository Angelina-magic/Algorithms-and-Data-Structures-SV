//1408. 数组中的字符串匹配
//给你一个字符串数组 words ，数组中的每个字符串都可以看作是一个单词。请你按 任意 顺序返回 words 中是其他单词的子字符串的所有单词。
//如果你可以删除 words[j] 最左侧和/或最右侧的若干字符得到 word[i] ，那么字符串 words[i] 就是 words[j] 的一个子字符串。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/string-matching-in-an-array
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** stringMatching(char ** words, int wordsSize, int* returnSize){
    if ((words == NULL) || (wordsSize <= 0)) {
        *returnSize = 0;
        return NULL;
    }

    char** res = (char**)malloc(sizeof(char*) * wordsSize);
    int index = 0;

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (i != j) {
            // C 库函数 char *strstr(const char *haystack, const char *needle) 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。
            // haystack -- 要被检索的 C 字符串。needle -- 在 haystack 字符串内要搜索的小字符串。该函数返回在 haystack 中第一次出现 needle 字符串的位置，如果未找到则返回 null。
                if (strstr(words[j], words[i])) {
                    res[index] = (char*)malloc(sizeof(char) * (strlen(words[i]) + 1));
                    memcpy(res[index], words[i], strlen(words[i]) + 1);
                    index++;
                    break;
                }
            }
        }
    }

    *returnSize = index;
    return res;

}
