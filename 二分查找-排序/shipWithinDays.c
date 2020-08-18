//1011. 在 D 天内送达包裹的能力
//传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
//传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
//返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days
int shipWithinDays(int* weights, int weightsSize, int D){
    int i,max;
    int sum = 0;
    max = weights[0];
    for(i=0; i<weightsSize; i++){
        if(weights[i]>max)
            max = weights[i];
        sum += weights[i];
    }
    int mid, day, temp;
    while(max < sum){
        mid = (max+sum)/2;
        temp = 0;
        day = 1;
        for(i=0; i<weightsSize; i++){
            temp += weights[i];
            if(temp>mid){
                day++;
                temp = weights[i];
            }
        }
        if(day > D)
            max = mid+1;
        else
            sum = mid;
    }
    return max;
}
