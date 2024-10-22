#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas{  
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
// 测试用例4 测试Excecute方法，在朝向为W，起点为（0，0）时去执行M指令是否正确
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_W)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'})); // 给定初始方向
    // when 调用方法
    executor->Execute("M");
    // then
    const Pose target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
//测试用例5 测试Excecute方法，在朝向为N，起点为（0，0）时去执行M指令是否正确
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_N)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 给定初始方向
    // when 调用方法
    executor->Execute("M");
    // then
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例6 测试Excecute方法，在朝向为S，起点为（0，0）时去执行M指令是否正确
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_S)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'})); // 给定初始方向
    // when 调用方法
    executor->Execute("M");
    // then
    const Pose target({0, -1, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例7 测试Excecute方法，在朝向为N，起点为（0，0）时去执行L指令是否正确
TEST(ExecutorTest, should_return_W_given_command_is_L_and_facing_is_N)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 给定初始方向
    // when 调用方法
    executor->Execute("L");
    // then
    const Pose target({0, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例8 测试Excecute方法，在朝向为W，起点为（0，0）时去执行L指令是否正确
TEST(ExecutorTest, should_return_S_given_command_is_L_and_facing_is_W)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'})); // 给定初始方向
    // when 调用方法
    executor->Execute("L");
    // then
    const Pose target({0, 0, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例9 测试Excecute方法，在朝向为S，起点为（0，0）时去执行L指令是否正确
TEST(ExecutorTest, should_return_E_given_command_is_L_and_facing_is_S)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'})); // 给定初始方向
    // when 调用方法
    executor->Execute("L");
    // then
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例10 测试Excecute方法，在朝向为E，起点为（0，0）时去执行L指令是否正确
TEST(ExecutorTest, should_return_N_given_command_is_L_and_facing_is_E)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
    // when 调用方法
    executor->Execute("L");
    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例11 测试Excecute方法，在朝向为N，起点为（0，0）时去执行R指令是否正确
TEST(ExecutorTest, should_return_E_given_command_is_R_and_facing_is_N)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 给定初始方向
    // when 调用方法
    executor->Execute("R");
    // then
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例12 测试Excecute方法，在朝向为E，起点为（0，0）时去执行R指令是否正确
TEST(ExecutorTest, should_return_S_given_command_is_R_and_facing_is_E)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
    // when 调用方法
    executor->Execute("R");
    // then
    const Pose target({0, 0, 'S'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例13 测试Excecute方法，在朝向为N，起点为（0，0）时去执行R指令是否正确
TEST(ExecutorTest, should_return_W_given_command_is_R_and_facing_is_S)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'})); // 给定初始方向
    // when 调用方法
    executor->Execute("R");
    // then
    const Pose target({0, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}
// 测试用例14 测试Excecute方法，在朝向为N，起点为（0，0）时去执行R指令是否正确
TEST(ExecutorTest, should_return_N_given_command_is_R_and_facing_is_W)
{
    // given给定一个executor
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'})); // 给定初始方向
    // when 调用方法
    executor->Execute("R");
    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}
}
        