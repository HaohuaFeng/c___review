#include <stdio.h>

int main(){
    int current, current_minute, end, end_minute, value;
    printf("开始时间: ");
    scanf("%d %d", &current, &current_minute);
    printf("结束时间: ");
    scanf("%d %d", &end, &end_minute);
    printf("当前理智: ");
    scanf("%d", &value);
    if(current >= 12){
        current = current - 12;
    }
    int dh;
    if(end < current){
        dh = end + 12 - current;
    } else{
        dh = end - current;
    }
    int dm = end_minute - current_minute;
    if(dm < 0){
        dm = 60 + dm;
        dh -= 1;
    }
    int gain = (dh * 60 + dm) / 5,
    total = value + gain,
    use = total - 135;

    printf("=================================\n"
           "|\t剩余时间: %d: %d\t\t|\n"
           "|\t获得理智: %d\t\t|\n"
           "|\t总共理智: %d\t\t|\n"
           "|\t防止溢出: %d\t\t|\n"
           "=================================\n\n",
           dh, dm, gain, total ,use);
    return 0;
}