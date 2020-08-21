//917. 仅仅反转字母
//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
char *reverseOnlyLetters(char *s)
{
	if (s == NULL) {
		return NULL;
	}
	int len = strlen(s);
    
	char *a = (char*)malloc(sizeof(char) * (len + 1));
	memcpy(a, s, sizeof(char) * (len + 1));
	int i = 0, j = len - 1; // 首尾指针 

	while(i < j) { // 双指针往中间移动 

		while (i < j && !isalpha(a[i])) {
			i++;
		} 

		while (i < j && !isalpha(a[j])) {
			j--;
		} 

		if (i < j ) {
			char t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++, j--;
		}
	}
	return a;
}
