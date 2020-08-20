//557. 反转字符串中的单词 III
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
void swap(int left,int right,char *s){
    char temp;
    while(left<right){
        temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}

char * reverseWords(char * s){
    int i=0,num=0;
    int len =strlen(s);
    for(;i<len;i++){
        if(s[i]==' '){
            swap(num,i-1,s);
            num=i+1;
        }
        if(i==len-1)swap(num,i,s);

    }
    return s;
}
