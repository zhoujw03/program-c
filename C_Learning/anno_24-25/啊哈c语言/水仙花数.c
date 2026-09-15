#include<stdio.h>

int main(){

    int a, b, c;
    int i;

    for (i = 100; i < 999; i++)
    {
        //分别找到数字的个位，十位和百位数
        a = i % 10;
        b = (i / 10) % 10;
        c = i / 100;
        if(a*a*a+b*b*b+c*c*c==i)
            printf("%d\n", i);
    }

        return 0;
}