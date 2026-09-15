# 多文件项目+头文件保护+静态库完整实战流程
## 1. 项目文件结构（示例）
先明确项目的文件分工，这是基础：
---
├── main.c          # 主程序（调用函数）
├── cals.c          # 函数实现文件1
├── io.c            # 函数实现文件2
├── calc.h          # calc.c 的函数声明头文件
├── io.h            # io.c 的函数声明头文件
└── common.h        # 汇总所有子头文件的总头文件
## 2. 头文件添加保护（防止重复包含）
每个 `.h` 文件必须加 `#ifndef`/`#define`/`#endif` 保护，示例如下：

### calc.h
```c
#ifndef CALC_H    // 格式：文件名大写+_H，避免重复
#define CALC_H

// 函数声明
int add(int a, int b);
int sub(int a, int b);

#endif  // 结束保护
```

### io.h
```c
#ifndef IO_H
#define IO_H

// 函数声明
void print_result(int res);
void input_num(int *a, int *b);

#endif
```

### common.h（汇总所有子头文件）
```c
#ifndef COMMON_H
#define COMMON_H

// 一次性包含所有子头文件，主程序只需包含这个文件
#include "calc.h"
#include "io.h"

#endif
```

## 3. 函数实现文件（.c）
### calc.c
```c
// 包含对应的头文件（匹配声明）
#include "calc.h"

// 函数实现
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}
```

### io.c
```c
#include "io.h"
#include <stdio.h>  // 依赖标准库头文件

void print_result(int res) {
    printf("结果：%d\n", res);
}

void input_num(int *a, int *b) {
    printf("输入两个数：");
    scanf("%d %d", a, b);
}
```

## 4. 主程序文件（main.c）
```c
// 只需包含汇总的头文件，无需逐个包含子头文件
#include "common.h"

int main() {
    int a, b, res;
    input_num(&a, &b);   // 调用io.c的函数
    res = add(a, b);     // 调用calc.c的函数
    print_result(res);   // 调用io.c的函数
    return 0;
}
```

## 5. 编译+制作静态库+链接运行（完整命令）
### 步骤1：编译所有 .c 文件生成 .o 目标文件
```bash
# 编译函数实现文件
gcc -c calc.c -o calc.o   # 生成calc.o
gcc -c io.c -o io.o       # 生成io.o
# 编译主程序（只编译，不链接）
gcc -c main.c -o main.o
```

### 步骤2：将函数 .o 文件打包成静态库（.a）
```bash
# 格式：ar -r 库名（必须以lib开头，.a结尾） 目标文件1 目标文件2
ar -r libcalc_io.a calc.o io.o
```
执行后会生成 `libcalc_io.a` 静态库文件。

### 步骤3：链接静态库生成可执行文件
```bash
# 方式1：直接指定库文件（推荐新手）
gcc main.o libcalc_io.a -o myprogram
# 方式2：标准库链接方式（-L. 指定当前目录找库，-lcalc_io 对应libcalc_io.a）
gcc main.o -L. -lcalc_io -o myprogram
```
### 步骤4：运行程序
```bash
./myprogram
```

## 6. 关键注意事项（避坑点）
1. **头文件保护的核心作用**：
   - 当多个文件同时包含同一个头文件时，`#ifndef` 能避免函数声明、宏定义重复，导致编译报错。
   - 也可以用简化写法 `#pragma once`（大部分编译器支持），效果和 `#ifndef` 一致，但 `#ifndef` 是跨平台标准写法。
2. **静态库命名规则**：
   - 必须以 `lib` 开头，`.a` 结尾（如 `libxxx.a`），否则链接时 `-lxxx` 无法识别。
3. **编译顺序**：
   - 先编译所有 `.c` 生成 `.o`，再打包库，最后链接主程序 + 库。
4. **头文件不编译**：
   - 始终记住：`.h` 文件只用于声明，不需要 `gcc -c xxx.h`，编译时编译器会自动读取 `#include` 的头文件。

---

### 总结
1. 每个函数头文件（.h）必须加 `#ifndef`/`#define`/`#endif` 防止重复包含，也可简化用 `#pragma once`；
2. 汇总头文件（如 common.h）可让主程序只需包含一个文件，简化代码；
3. 静态库制作流程：编译 .c 生成 .o → `ar -r libxxx.a 目标.o` → 链接库生成可执行文件，库名需遵循 `libxxx.a` 规则。