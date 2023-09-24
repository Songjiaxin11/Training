#ifndef ROBOT_CONFIG_H//头文件保护, 避免在编译过程中出现重复定义的问题
#define ROBOT_CONFIG_H
using namespace vex;//命名空间, 告诉编译器, 你可以直接用标准库中的成员, 不需要每个前面都加上vex::的前缀
using namespace std;//如果没有这句, 你将这样输出: std::cout<<"Hello World"<<std::endl;
#include "vex.h"//你可以再在每个文件里#include "vex.h"
extern brain Brain;//全局变量定义
extern controller Controller;//全局变量定义
extern motor Motor_BaseLF;
extern motor Motor_BaseLB;
extern motor Motor_BaseLM;
extern motor Motor_BaseRF;
extern motor Motor_BaseRB;
extern motor Motor_BaseRM;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
#endif
