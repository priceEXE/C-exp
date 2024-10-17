#include "ExecutorImpl.hpp"

#include <new>

namespace adas{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept :pose(pose) {}
    Pose ExecutorImpl::Query(void) const noexcept{
        return pose;
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new(std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept {
        for(const auto cmd : commands)
        {
            if( cmd == 'M' )
            {
                if(pose.heading == 'E') { ++pose.x; }
                else if(pose.heading == 'W') { --pose.x; }
                else if(pose.heading == 'N') { ++pose.y; }
                else if(pose.heading == 'S') { --pose.y; }
            }
            else if( cmd == 'L')
            {
                if(pose.heading == 'E') { pose.heading = 'N'; }
                else if(pose.heading == 'W') { pose.heading = 'S'; }
                else if(pose.heading == 'N') { pose.heading = 'W'; }
                else if(pose.heading == 'S') { pose.heading = 'E'; }
            }
            else if( cmd == 'R')
            {
                if(pose.heading == 'E') { pose.heading = 'S'; }
                else if(pose.heading == 'W') { pose.heading = 'N'; }
                else if(pose.heading == 'N') { pose.heading = 'E'; }
                else if(pose.heading == 'S') { pose.heading = 'W'; }
            }
        }
    }
}