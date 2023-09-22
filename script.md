# Beginning
1. 创建Competition模板
2. 在你所有的文件里无脑#include vex.h, 添加using namespace vex;
3. 创建robot-config.h robot-config.cpp 在robot-config.h中先声明你所有的电控元件, 在robot-config.cpp中定义你所有的电控元件
4. 在vex.h 中 include robot-config.h
5. 尝试在main.cpp->int main()中设置brain和controller的屏幕坐标, 并输出
6. 手柄的使用方法: 在`主页`中按`左` `右`切换至`程序`, 按`A`进入`程序`, 按`左` `右`切换至第n套程序, 按`A`进入, 从左到右分别是`运行` `计时运行` `比赛`, 进入`运行`, 调用usercontrol(), 进入`比赛`->`编程技能`, 调用autonomous()
7. 在main.cpp->usercontrol()中尝试用手柄操作摇杆控制电机旋转, 在main.cpp->autonomous()中尝试用编程控制电机旋转.
8. 你的电控元件, 函数参见PPT上的代码, 若想查看这个类的全部细节, 你可以选择一个类, 比如`brain`, `controller`, `motor`,然后按`F12` or 右键, `Go to Definition` 
9. Inertial的使用方法: 使用inertial.heading()获得当前的角度