# 终端命令
## 一、打开双窗口
- ⌘ + T ：新建终端标签页
- 左边：vi 写代码
- 右边：编译、运行、查指令

## 二、目录与文件基础
- `pwd` ：查看当前路径
- `ls` ：简单查看文件
- `ls -l` ：详细查看（权限、大小）
- `ls -la` ：详细+显示隐藏文件
- `cd 文件夹名` ：进入文件夹
- `cd ..` ：返回上一级
- `mkdir 名字` ：新建文件夹
- `touch main.c` ：新建空 .c 文件
- `cat main.c` ：查看文件内容
- `cp a.c b.c` ：复制文件
- `mv a.c b.c` ：重命名/移动
- `rm main.c` ：删除文件
- `clear` ：清屏
- `nm main` ：查看符号表（函数、变量）

## 三、vi 编辑器
- `vi main.c` ：打开或新建文件
- `i` ：进入编辑模式（插入模式）
- `Esc` ：退出编辑模式，回到命令模式

### 命令模式下操作：
- `yy` ：复制当前行
- `p` ：粘贴到光标下一行
- `dd` ：删除当前行
- `x` ：删除光标所在字符
- `:w` ：保存文件
- `:q` ：退出 vi
- `:wq` ：保存并退出
- `:q!` ：不保存强制退出

## 四、GCC 核心选项（中文说明）
- `-o outputfile` ：指定输出文件名，生成名为 outputfile 的可执行文件，而不是默认a.out。
- `-Wall` ：开启所有警告，启用编译器的所有警告信息，帮助发现代码中的潜在问题，是写代码时的推荐选项。
- `-g` ：生成调试信息，在可执行文件中加入调试符号表，用于配合 gdb(Mac 里用lldb) 等调试器进行代码调试。
- `-v` ：启用详细模式，显示编译、汇编、链接的完整过程和详细日志，便于排查编译问题。
- `-lm` ：链接数学库，当代码中使用了math.h头文件里的数学函数 (如sqrt()，sin() ) 时，必须加上此选项来链接数学库 libm。
- `-S` ：生成汇编代码，只进行编译，生成 .s 格式的汇编语言文件，不生成可执行文件，用于理解代码的底层实现。
- `-D name` ：编译时定义宏，在编译阶段定义一个名为 name 的宏, 其值默认为1,可用于在代码中通过 #ifdef 等条件编译指令控制代码执行。

## 五、调试器使用（Mac 环境 lldb）
1. 调试可执行文件：
`lldb programma`

2. 常用 `lldb` 命令：
- `run` ：运行程序
- `break main` ：在 main 函数处设置断点
- `next` ：单步执行（不进入函数）
- `step` ：单步执行（进入函数）
- `print 变量名` ：查看变量值
- `quit` ：退出调试器

## 六、编译 C 语言 · 核心指令
### 1. 直接编译+生成可执行文件
- `gcc main.c -o main`
- `gcc -Wall main.c -o main` （带警告）

### 2. 只编译，不链接（生成 .o）
- `gcc -c main.c` ：生成 main.o
- `gcc -c funzioni.c` ：生成 funzioni.o

### 3. 链接 .o 文件，生成可执行
- `gcc main.o funzioni.o -o programma`

### 4. 运行
- `./main`
- `./programma`

## 七、静态库制作（ar 命令）
- 将多个 .o文件打包成静态库 libnome.a：
`ar -r libnome.a file1.o file2.o`
- 链接静态库生成可执行文件：
`gcc main.o libnome.a -o programma`

## 八、头文件 .h 规则（超级重要）
- .h 头文件不需要编译！
- 不要写：`gcc xxx.h`
- 只需要在 .c 里 `#include "xxx.h"`
- 编译命令只编译 .c，链接 .o

## 九、多文件项目万能模板
假设有：main.c、funzioni.c、utils.c、xxx.h、yyy.h
1. 编译所有 .c
`gcc -c main.c`
`gcc -c funzioni.c`
`gcc -c utils.c`
2. 链接所有 .o
`gcc main.o funzioni.o utils.o -o programma`
3. 运行
`./programma`