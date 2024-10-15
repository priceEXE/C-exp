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

};
        