#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
    TEST(ExecutorTest, should_return_x_minus_2_given_status_is_fast_and_reverse_command_is_M_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FBM");
        // then
        const Pose target({-2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    TEST(ExecutorTest, should_return_S_and_x_minus_1_given_status_is_fast_and_reverse_command_is_L_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FBL");
        // then
        const Pose target({-1, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    TEST(ExecutorTest, should_return_N_and_x_minus_1_given_status_is_fast_and_reverse_command_is_R_and_facing_is_E)
    {
        // given给定一个executor
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始方向
        // when 调用方法
        executor->Execute("FBR");
        // then
        const Pose target({-1, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
}