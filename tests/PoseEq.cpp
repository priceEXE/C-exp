#include "PoseEq.hpp"
#include "Executor.hpp"
namespace adas
{
    bool operator==(const Pose &Ihs, const Pose &rhs)
    {
        return std::tie(Ihs.x, Ihs.y, Ihs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
}