#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <memory>
#include <new>
#include <unordered_map>

namespace adas{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept :posehandler(pose) {}
    Pose ExecutorImpl::Query(void) const noexcept
    {
        return posehandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new(std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        std::unordered_map<char, std::function<void(PoseHandler & posehandler)>> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B',ReverseCommand()},
        };
        for(const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if(it != cmderMap.end())
            {
                it->second(posehandler);
            }
        }
    }

}