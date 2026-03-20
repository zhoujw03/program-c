//给定一个字符数组， 只包含数字字符， 和大小写字母，统计数字字符的个数，大写字母个数，小写字母个数
//Dato una stringa di solo numeri, lettere maiuscole e minuscole, contare per ognuno il numero

#include<stdio.h>
#include<ctype.h>

void count(char* p, int len){

    int count_number = 0;       //统计数字
    int count_upper_char = 0;   //统计大写字母
    int count_lowerr_char = 0;  //统计小写字母

    for (int i = 0; i < len; i++ ){
        char c = *(p + i);
        if (isdigit(c)) // 判断是不是十进制数字，如果是输出1，不是输出0
            count_number++;

        if(islower(c))
            count_lowerr_char++;

        if(isupper(c))
            count_upper_char++;
    }
    printf("数字 = %d\n", count_number);
    printf("小写字母 = %d\n", count_lowerr_char);
    printf("大写字母 = %d\n", count_upper_char);
}

int main(){

    char arr[] = {"abcd1234dLcIeLerRG3789ACBefg"};
    int len = sizeof(arr) / sizeof(arr[0]);
   // printf("%d", len);

    count(arr, len);

    return 0;
}