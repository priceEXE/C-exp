#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
    // 测试用例15 测试F指令，在命令组合为FM，车头朝向为E，执行组合指令是否正确
    TEST(ExecutorTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FM");
        // then
        const Pose target({2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例16 测试F指令，在命令组合为FL，车头朝向为E，执行组合指令是否正确
    TEST(ExecutorTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FL");
        // then
        const Pose target({1, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例17 测试F指令，在命令组合为FR，车头朝向为E，执行组合指令是否正确
    TEST(ExecutorTest, should_return_S_and_x_plus_1_given_status_is_fast_command_is_M_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FR");
        // then
        const Pose target({1, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例18 测试F指令，在命令组合为FFM，车头朝向为E，执行组合指令是否正确
    TEST(ExecutorTest, should_return_y_plus_1_given_status_is_fast_command_is_M_and_facing_is_N)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FFM");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
}