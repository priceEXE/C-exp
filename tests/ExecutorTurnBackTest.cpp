#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
    TEST(ExecutorTest, shuold_normal_tr_build_left_forward_left)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给了初始姿势
        // when
        executor->Execute("TR");
        // then
        const Pose target({0, 1, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    TEST(ExecutorTest, shuold_fast_tr_build_forward_left_forward_left)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给了初始姿势
        // when
        executor->Execute("FTR");
        // then
        const Pose target({1, 1, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    TEST(ExecutorTest, in_the_B_state_the_reverse_command_will_be_ignores)
    {
        // given 给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给了初始姿势
        // when
        executor->Execute("BTR");
        // then
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
}