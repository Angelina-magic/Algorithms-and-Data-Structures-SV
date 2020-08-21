//面试题 01.09. 字符串轮转
//字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
bool isFlipedString(char* s1, char* s2) {

    int i=0,size1=strlen(s1),size2=strlen(s2);
    if(size1!=size2) {
        return false;
    }
    
    char mystr[2*size2+1];
    for(i=0;i<2*size2+1;i++) {
        mystr[i]='\0';
    }
    strcat(mystr,s2);
    strcat(mystr,s2);
    
    if(strstr(mystr,s1)) {
        return true;
    } else {
        return false;
    }
}
