//给定一个字符数组， 只包含数字字符， 和大小写字母，统计数字字符的个数，大写字母个数，小写字母个数
//Dato una stringa di solo numeri, lettere maiuscole e minuscole, contare per ognuno il numero

/*
这些函数用于检查传入的字符是否符合特定条件。如果符合，返回非零值（真）；否则返回 0（假）
函数名,         检查内容,           示例 (为真时)
iscntrl(),     是否为控制字符,      "\n, \b (退格)"

isspace(),     是否为空白字符,     "空格, \n, \t, \r"

isalpha(),     是否为字母,          "'a', 'Z'"

isdigit(),     是否为十进制数字,    '0' - '9'

isalnum(),     是否为字母或数字,    "'a', '5'"

islower(),     是否为小写字母,      'g'

isupper(),     是否为大写字母,       'A'

ispunct(),     是否为标点符号,      "'!', '.', ','"

isprint(),     是否为可打印字符,包含空格在内的所有可见字符

isgraph(),     是否为图形字符,不包含空格的可见字符

isxdigit(),    是否为十六进制数字,   "'0'-'9', 'a'-'f', 'A'-'F'"
*/

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