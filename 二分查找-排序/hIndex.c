//275. H指数 II
//给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列。编写一个方法，计算出研究者的 h 指数。
//h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。）"
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/h-index-ii
int hIndex(int* citations, int citationsSize){
int n=0,r=citationsSize;
    while(n<r)
    {
        int mid=(n+r+1)/2;
        if(citations[citationsSize-mid]>=mid)
            n=mid;
        else r=mid-1;
    }
    return n;

}
