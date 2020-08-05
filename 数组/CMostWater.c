#include<stdio.h>
#include<math.h>
// 求面积
int Area(int x1, int x2, int y1, int y2) {
    return abs(x1-x2)*(y1<=y2?y1:y2);
}
int maxArea(int* height, int heightSize){
    int *left, *right;
    left = height, right = height + heightSize -1;
    int L = 0, R = heightSize - 1, area = Area(L, R, *left, *right);

    // 将双指针的范围收缩
    while(!(left==right)) {
        if(*left<=*right) {
            left++, L++, area = area<Area(L, R, *left, *right) ? Area(L, R, *left, *right):area;

        } else {
            right--, R--, area = area<Area(L, R, *left, *right) ? Area(L, R, *left, *right):area;
        }
    }
    return area;    

}

int main(void) {
    int height[9] = {1,8,6,2,5,4,8,3,7};
    int heightSize = 9;
    printf("the max area is %d", maxArea(height, heightSize));
    return 0;
}
