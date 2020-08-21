//38. 外观数列
//给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
//注意：整数序列中的每一项将表示为一个字符串。
//「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//第一项是数字 1
//描述前一项，这个数是 1 即 “一个 1 ”，记作 11
//描述前一项，这个数是 11 即 “两个 1 ” ，记作 21
//描述前一项，这个数是 21 即 “一个 2 一个 1 ” ，记作 1211
//描述前一项，这个数是 1211 即 “一个 1 一个 2 两个 1 ” ，记作 111221
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/count-and-say
char * countAndSay(int n){
    char *mark=(char *)malloc(sizeof(char)*5000);
    char *temp=(char *)malloc(sizeof(char)*5000);
    mark[0]='1';
    mark[1]='\0';//结束标志
    int i,count,j;
    char key,*p;
    for(i=1;i<n;i++)//迭代次数
    {
        j=0;
        key=mark[0];
        count=0;
        p=mark;
        while(*p!='\0')
        {
            if(*p==key)//计数
                count++;
            else {
                temp[j++]=count+'0';//先存计数器
                count=1;
                temp[j++]=key;//再存关键字
                key=*p;
            }
            p++;

        }
        temp[j++]=count+'0';//先存计数器
        temp[j++]=key;//再存关键字
        temp[j]='\0';
        strcpy(mark,temp);
    }
    return mark;
}
