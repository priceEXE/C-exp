#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas{  
 bool operator==(const Pose &Ihs, const Pose &rhs)
{
    return std::tie(Ihs.x, Ihs.y, Ihs.heading) == std::tie(rhs.x,rhs.y, rhs.heading);

}
//测试用例1
TEST (ExecutorTest, should_return_init_pose_when_without_command){
// given 给定测试条件
    std::unique_ptr<Executor> executor( Executor::NewExecutor({0, 0, 'E'}));//给了初始姿势
// when
// then
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
//测试用例2
TEST(ExecutorTest, shoul_return_default_pose_when_without_init_and_command)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor());//没有初始化

    //when

    //then

    const Pose target({0,0,'N'});
    ASSERT_EQ(target, executor->Query());
}
//测试用例3 测试Excecute方法，在朝向为E，起点为（0，0）时去执行M指令是否正确
TEST(ExecutorTest,should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    //given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0,0,'E'}));//给定初始方向
    //when 调用方法
    executor->Execute("M");
    //then
    const Pose target({1,0,'E'});
    ASSERT_EQ(target, executor->Query());
}
}
        