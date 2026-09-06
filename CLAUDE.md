# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

- **Compile a single .c file:** `gcc -g <file.c> -o <file.exe> && ./<file.exe>`
- **Compile a single .cpp file:** `g++ -g <file.cpp> -o <file.exe> && ./<file.exe>`
- **Current compilers:** MinGW-w64 GCC/G++ at `E:\MYSY\mingw64\bin\` (gcc 15.2.0, g++ 15.2.0)
- **VS Code task:** Build active file via `Ctrl+Shift+B`（`.vscode/tasks.json`，仅配置了 gcc）
- **VS Code debug:** F5 启动 GDB 调试（`.vscode/launch.json`，使用 `E:\MYSY\mingw64\bin\gdb.exe`）
- **No build system**（Makefile/CMake）— 每个 .c/.cpp 文件独立编译为 .exe，产物放在源文件同目录

## Project Structure

课程 + 专题训练混合仓库，按区域划分：

- **Term1/** ~ **Term5/** — C 语言课程主线：变量/运算符/控制流 → 函数与数组 → 算法入门（冒泡、二分/插值查找）→ 指针/函数指针/字符串/结构体/文件 I/O → 高级文件 I/O、日期时间（`<time.h>`）。`Term1/HomeWork/` 是 for 循环作业；各 Term 目录内为扁平 `.c` + `.exe`，无 C++ 版
- **HomeWork/** — 3 套作业（1/2/3，指针/数组/函数指针），根下有 `debug.c`；另有 `HomeWork.zip`、`C_learning.zip`（整仓备份压缩包，勿改动）
- **string/** — **xv6 补弱专项**：做 MIT 6.1810 xv6 lab1（sleep/pingpong/primes/find/xargs）暴露的 C 薄弱点训练，t01–t06 是 TODO 填空代码题（精确预期输出，写完编译比对），t07/t08 是运行观察后在注释里作答型。无 C++ 版。读写约定见 `string/README.md`（t06 需管道/重定向喂输入）
- **data_structrue/** — 数据结构专题，按主题组织，各主题布局不统一（见下方"双语言约定"）
  - `linear-list/Sequential_List/` — **早期扁平历史结构**：`demo*`/`exercise*`/`ex2_*` 多个 .c 直接平铺，配套 `h/common.h` + `common.c`（共享的动态顺序表 Sqlist 定义与操作，全仓唯一头文件；练习题位序从 1 开始，约定见 `exercises.md`）；`review/` 复习题 r1–r5（按位删除/按值查找/二分/有序合并/去重，C 完成，C++ 分 `day1/`、`day2/` 两个子目录）
  - `linear-list/link_list/Term1/` — 扁平结构：ex1–ex4 md + Q1–Q4（头插建表/删值/反转/倒数第 k 个），单链表题常留 `v1`/`v2` 多版本重写；另含复习题 R1
  - `linear-list/Sequential_Stack/`、`Sequential_Queue/` — 规范化结构，C/C++ 双版本完备（ex1–ex3、ex1–ex2）
  - `Tree/` — 二叉树：ex1–ex4（建立与递归遍历/层序/深度与节点数/BST），C/C++ 双版本完备
  - `Graph/` — **2026-09 新增，进行中**：ex1–ex4 md（图的存储/DFS/BFS/连通分量），C 实现到 Q3，ex4 未写、C++ 未开始
  - `review/Term1/` — **2026-09 新增复习套题**：R1–R5（合并两个有序链表、用栈实现队列、平衡二叉树判断、递归判断回文、单调栈下一个更大元素），C 完成，C++ 未开始
- **Algorithm/** — **当前学习主线**，按 `Algorithm/学习规划.md` 系统推进（目标：考研 408 + 蓝桥杯 C/C++ 组 + 实习面试笔试；六阶段：排序 → 堆 → 图 → 查找与树进阶(AVL/B树/哈希/KMP) → 范式(分治/回溯/贪心/DP) → 技巧(双指针/滑动窗口/前缀和/单调栈/数论)）
  - `Recursion/`（原 `递归/`）— 递归专题 r1–r10（阶乘/斐波那契/反转链表/二叉树最大值/对称二叉树/爬楼梯/两两交换节点/翻转二叉树/相同的树/平衡二叉树判断），C 全完成，C++ 到 Q9
  - `Sorting/` — **2026-09 新增，进行中**：s0 复杂度/稳定性对比表 + s1–s7 题目说明（直接插入/希尔/简单选择/快排/归并/堆排序/计数），C 只写了前三题（Q3v2 为重写），**Q4 快排是 0 字节空文件**，C++ 未开始
- **LeetCode/** — 刷题记录（Q2 两数相加、Q3 无重复最长子串、Q20 有效括号）
- **review/** — Term4 阶段复习题（`Problem.md`）
- **test/** — 临时实验文件（有 `.cc` 需用 g++ 编译）

### 数据结构/算法目录的双语言约定（及例外）

约定：每道题的 md 文件含题目、结构体定义、测试用例和 C/C++ 两套示例代码；C++ 实现刻意贴近 C 语法（`struct` 而非 `class`，用 `cin/cout`、`new/delete`、`nullptr` 替换对应 C 写法），便于对照学习。

现实状态（截至 2026-09-06）并不统一，各目录差异很大：

| 区域 | C 版 | C++ 版 |
|------|------|--------|
| Tree、Sequential_Stack、Sequential_Queue | 完备 | 完备 |
| Algorithm/Recursion | r1–r10 完备（含 v2 重写） | Q1–Q9，**缺 Q10** |
| data_structrue/review/Term1 | Q1–Q5 完备 | 目录空 |
| Algorithm/Sorting | 插入/希尔/选择（快排空文件未写） | 目录空 |
| data_structrue/Graph | Q1–Q3（ex4 连通分量未写） | 目录空 |
| string/ | t01–t05 填空完成、t06 填空未完成（t07/t08 是运行观察 + 注释作答型，无代码填空） | 无此约定 |

历史主题（Sequential_List 扁平区、link_list/Term1、HomeWork、LeetCode、test）本就没有 C++ 版。新增题目默认出双版本，但注意：最近专题明显先做 C、C++ 滞后，动手前先确认用户当前意图。

## 已学 / 未学知识清单（截至 2026-09-06）

**已学（不含"进行中"专题）：**
- C 基础：变量、运算符、`if`/`switch`、`for`/`while` 循环；函数、数组（一维/二维/作参数）
- 指针：指针运算、`int **`、函数指针、指针函数数组；字符串 `<string.h>` 族（`strcmp`/`strcpy`/`strlen`/`strstr`）
- 结构体、`malloc`/`free`、文件 I/O（`fopen`/`fread`/`fwrite`/`fscanf`/`fprintf`）、`<time.h>`/`mktime`/`difftime`
- 数据结构：动态顺序表（扩容、按位序从 1 操作）、单链表（头插/尾插、带头结点）、顺序栈、循环队列、二叉树（递归遍历、层序、深度/节点数、BST 插入查找）
- 算法：递归专题 10 题（含爬楼梯、两两交换节点、翻转二叉树、相同的树、平衡二叉树判断——高度差 ≤ 1）；冒泡排序；顺序/二分/插值查找
- 复习题（2026-09）：合并两个有序链表、用栈实现队列、递归判断回文
- C++ 基础语法（`cin`/`cout`、`new`/`delete`、`nullptr`、构造函数，与 C 对照学习）
- 单调栈仅接触过"下一个更大元素"一题（R5）

**进行中（已完成部分、整体未验收，出题时按未学对待）：**
- 排序：直接插入、希尔、简单选择（C 版）；快排/归并/堆排序/计数排序未写
- 图：邻接矩阵/邻接表存储、DFS/BFS（含 visited 标记）、连通分量概念（C 版到 BFS，连通分量题未写）

**未学（出题和检查时不要涉及）：**
- 图论进阶：最小生成树（Prim/Kruskal）、最短路（Dijkstra/Floyd）、拓扑排序
- 堆（优先队列）、哈希表、AVL/红黑树、B 树系列、KMP
- 算法范式：分治/回溯/贪心/动态规划的系统化（注意：快排/归并和爬楼梯仅作为递归/枚举使用过，DP 的递推→记忆化→状态转移尚未系统学）；单调队列、双指针/滑动窗口/前缀和/位运算/数论
- C++ 高级特性：模板、STL 容器、异常处理、面向对象（继承/多态）
- 以上未学内容若有必要，需先提示"这个你还没学，要不要先了解一下？"

## Code Review Standards

- data_structrue/、Algorithm/、string/ 是用户**巩固 C/C++ 和数据结构知识**的核心区域，检查代码时必须**认真仔细**
- 检查要点：`scanf` 输入验证、内存分配与释放（`malloc`/`free` 和 `new`/`delete` 配对）、数组越界、指针正确性（含 `NULL` 检查）、所有分支路径覆盖；string/ 里还要重点盯字符串 `\0` 终止与缓冲越界
- 发现的问题要分类标注严重程度，并给出修复建议
- C 和 C++ 两种实现的检查要分别进行——不能因为 C 版本正确就默认 C++ 版本也正确
- 用户自评的习惯是每题写 v2/v3 重写版（删掉初版重新默写），检查时注意同一题可能并存多个版本文件

## Code Conventions

- 注释和用户界面字符串使用**中文**
- C 源文件用 `.c` 后缀，C++ 源文件用 `.cpp` 后缀，编译产物 `.exe` 放源文件同目录
- 几乎无头文件——每个文件自包含，含一个 `main()` 或少量函数。**唯一例外**：`data_structrue/linear-list/Sequential_List/h/common.h` + `common.c`（多个顺序表练习共享 Sqlist 动态表实现）
- C 版本输入用 `scanf`、输出用 `printf`；C++ 版本用 `cin`/`cout`
- 早期 Term 中错误处理较少；Term5 及 data_structrue/Algorithm/string 中增加了输入验证和标准库调用的错误检查
- 仓库根目录的 `tasks.json` 可能和 `.vscode/tasks.json` 重复——以 `.vscode` 版本为准
- 用户做题时允许/禁止使用的函数写在题目文件头注释里，出题和改题时遵守该约束
