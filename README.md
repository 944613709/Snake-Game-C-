# Snake Game (贪吃蛇游戏)

这是一个基于 C 语言开发的贪吃蛇游戏项目，作为哈尔滨工业大学 C 语言研讨课程的作业项目。

## 项目特点

- 使用 C 语言实现的经典贪吃蛇游戏
- 基于 Windows 控制台的图形界面
- 链表数据结构实现蛇身移动
- 具有完整的游戏流程和交互体验

## 功能介绍

1. **游戏界面**
   - 精美的 ASCII 艺术字欢迎界面
   - 清晰的游戏边界和得分显示
   - 实时显示玩家名称和分数

2. **游戏操作**
   - 使用 WASD 键控制蛇的移动方向
   - P 键暂停游戏
   - 简单直观的菜单操作系统

3. **游戏机制**
   - 随机生成食物
   - 吃到食物后蛇身自动增长
   - 碰撞检测（墙壁和蛇身）
   - 分数统计系统

## 技术实现

### 核心数据结构
```c
typedef struct Snakes {
    int x;
    int y;
    struct Snakes *next;
} snake;
```

### 主要功能模块

- `welcome()`: 游戏欢迎界面
- `menu()`: 游戏菜单系统
- `creatgraph()`: 游戏界面绘制
- `MovingBody()`: 蛇身移动逻辑
- `creatfood()`: 食物生成
- `Judge()`: 游戏状态判断
- `Eating()`: 进食处理

## 运行效果

### 欢迎界面
![欢迎界面](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152340496.png)

### 游戏界面
![游戏界面](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152340104.png)

### 结束界面
![结束界面](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152340900.png)

## 系统框架

![系统框架图](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152339857.png)

## 环境要求

- Windows 操作系统
- C 语言编译环境
- 控制台支持 ASCII 显示

## 如何运行

1. 克隆或下载项目代码
2. 使用 C 语言编译器编译 `main.c` 文件
3. 运行生成的可执行文件
4. 按照屏幕提示进行操作

## 项目结构

```
Snake-Game-C/
├── main.c          # 主程序源代码
├── main.exe        # 编译后的可执行文件
├── README.md       # 项目说明文档
└── images/         # 项目相关图片资源
```

## 贡献者

- 感谢哈尔滨工业大学 C 语言研讨课程的指导
