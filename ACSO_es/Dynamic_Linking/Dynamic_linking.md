# 动态库(.so)生成与调用指南

## 一、生成.so动态库文件
### 1. 前提条件
假设有以下源文件（示例中用到）：
- `add.c`：实现加法函数`add(int a, int b)`
- `sub.c`：实现减法函数`sub(int a, int b)`
- 头文件`libarith.h`：声明函数和变量（供调用方使用）
  ```c
  // libarith.h
  int add(int a, int b);
  int sub(int a, int b);
  extern float pi;
  ```

### 2. 编译生成目标文件（.o）
```bash
# 编译add.c为位置无关的目标文件（-fPIC 是生成动态库的关键）
gcc -c -fPIC add.c -o add.o
# 编译sub.c
gcc -c -fPIC sub.c -o sub.o
```

### 3. 链接生成.so动态库
将编译好的目标文件链接为最终的动态库`libarith.so`：
```bash
# Linux/Mac通用（-shared 表示生成动态库，-o 指定输出文件名）
gcc -shared add.o sub.o -o libarith.so
```
**命名规范**：动态库建议以`lib`开头，后缀为`.so`，便于系统识别。

## 二、调用.so动态库（核心流程）
调用动态库的核心依赖`dlfcn.h`头文件，需使用`dlopen`/`dlsym`/`dlclose`等函数，步骤如下：

### 1. 包含必要头文件
```c
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>   // 动态库操作核心头文件
#include<math.h>    // 示例中用到sin函数，按需添加
```

### 2. 定义函数/变量指针类型
动态库中的函数/变量需通过指针调用，先定义匹配的指针类型：
```c
// 定义函数指针类型（与动态库中函数签名一致）
typedef int (*add_ptr_t)(int, int);  // 匹配add函数
typedef int (*sub_ptr_t)(int, int);  // 匹配sub函数
```

### 3. 打开动态库（dlopen）
```c
// 声明句柄：void*类型，用于保存动态库的打开句柄
void *handler;

// 打开动态库：RTLD_LAZY 延迟加载（用到时才加载），RTLD_NOW 立即加载全部
handler = dlopen("./libarith.so", RTLD_LAZY);

// 异常处理：如果句柄为空，打印错误并退出
if (handler == NULL)
{
  printf("dlopen失败: %s\n", dlerror());  // dlerror()获取最近的动态库操作错误
  exit(1);  // 非0退出表示程序异常
}
```

### 4. 获取动态库中的符号（dlsym）
`dlsym`用于从动态库中查找**函数/变量符号**，返回`void*`，需强制转换为对应类型。

#### 4.1 获取函数符号
```c
add_ptr_t add_ptr;  // 声明add函数指针
sub_ptr_t sub_ptr;  // 声明sub函数指针

// 查找add函数符号
add_ptr = (add_ptr_t)dlsym(handler, "add");
if (add_ptr == NULL){
  printf("dlsym(add)失败: %s\n", dlerror());
  exit(1);
}

// 查找sub函数符号
sub_ptr = (sub_ptr_t)dlsym(handler, "sub");
if (sub_ptr == NULL){
  printf("dlsym(sub)失败: %s\n", dlerror());
  exit(1);
}
```

#### 4.2 获取变量符号
变量符号的查找与函数类似，但需转换为对应类型的指针：
```c
float *pi_ptr;  // 声明pi变量的指针（因为dlsym返回指针）

// 查找pi变量符号
pi_ptr = (float *)dlsym(handler, "pi");
if (pi_ptr == NULL){
  printf("dlsym(pi)失败: %s\n", dlerror());
  exit(1);
}
```

### 5. 使用动态库中的函数/变量
通过指针调用函数、访问变量：
```c
int a = 10, b = 20;

// 调用add函数（两种方式均可）
int z = (*add_ptr)(a, b);  // 方式1：解引用函数指针
// int z = add_ptr(a, b);  // 方式2：直接调用（C语言支持）
printf("加法结果: %d\n", z);

// 调用sub函数
int w = (*sub_ptr)(a, b);
printf("减法结果: %d\n", w);

// 访问pi变量（解引用指针）
float s = sin(2 * (*pi_ptr) / 3);
printf("sin(2π/3)结果: %f\n", s);
```

## 三、空指针/异常处理（关键）
动态库操作中最常见的异常是`dlopen`/`dlsym`返回NULL，需严格处理：

### 1. dlopen返回NULL
原因：动态库文件不存在、权限不足、路径错误（如漏写`./`表示当前目录）、动态库本身编译错误。
处理：打印`dlerror()`错误信息，退出程序（或降级处理）。

### 2. dlsym返回NULL
原因：符号名拼写错误（如大小写、函数名写错）、符号未导出（编译时未加`-fPIC`）、变量/函数未定义。
处理：
```c
// 每次dlsym后必须检查NULL
pi_ptr = (float *)dlsym(handler, "pi");
if (pi_ptr == NULL){
  printf("未找到pi符号: %s\n", dlerror());
  // 可选：退出/使用默认值/降级逻辑
  exit(1);  // 示例中直接退出，也可设置默认值：pi_ptr = &default_pi;
}
```

### 3. 避免直接解引用dlsym返回值
错误写法（风险高）：
```c
// 错误：如果dlsym返回NULL，解引用会导致段错误
float pi = *((float *)dlsym(handler, "pi"));
```
正确写法：先赋值给指针，检查NULL后再解引用（如示例中`*pi_ptr`）。

## 四、关闭动态库（释放资源）
使用完动态库后，必须调用`dlclose`释放句柄，避免内存泄漏：
```c
// 关闭动态库句柄
dlclose(handler);
```
**注意**：
- `dlclose`仅减少动态库的引用计数，当引用计数为0时，系统才会真正释放库的资源。
- 即使程序退出，系统也会自动释放，但显式调用是良好的编程习惯。

## 五、完整编译与运行命令
### 1. 编译调用程序（main.c）
需链接`dl`库（`-ldl`），否则会提示`dlopen/dlsym`未定义：
```bash
# Linux/Mac通用
gcc main.c -o main -ldl -lm  # -lm 链接数学库（示例中用到sin函数）
```

### 2. 运行程序
```bash
./main
```
预期输出：
```
加法结果: 30
减法结果: -10
sin(2π/3)结果: 0.866025
```

## 六、总结
| 步骤 | 核心函数 | 关键操作 |
|------|----------|----------|
| 生成.so | `gcc -c -fPIC`/`gcc -shared` | 编译位置无关目标文件，链接为动态库 |
| 打开库 | `dlopen` | 指定库路径，检查返回句柄是否为NULL |
| 获取符号 | `dlsym` | 区分函数/变量符号，检查返回值是否为NULL |
| 使用符号 | 指针调用/解引用 | 函数指针直接调用，变量指针解引用访问 |
| 关闭库 | `dlclose` | 释放句柄，避免资源泄漏 |

**核心注意事项**：
1. 动态库编译必须加`-fPIC`（Linux），否则链接时会报错。
2. 调用程序编译必须加`-ldl`，链接动态库操作的核心库。
3. 所有`dlopen/dlsym`的返回值必须检查NULL，避免运行时崩溃。
4. 变量符号通过指针访问，不要直接解引用`dlsym`的返回值。