#include "ExecutorImpl.hpp"
//#include "Command.hpp"
#include "./cmder/CmderFactory.hpp"
#include "Singleton.hpp"

#include <algorithm>
//#include <memory>
//#include <new>
//#include <unordered_map>

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
        //std::unordered_map<char, std::function<void(PoseHandler & posehandler)>> cmderMap{
        //    {'M', MoveCommand()},
        //    {'L', TurnLeftCommand()},
        //    {'R', TurnRightCommand()},
        //    {'F', FastCommand()},
        //    {'B',ReverseCommand()},
        //};
        //for(const auto cmd : commands)
        //{
        //    const auto it = cmderMap.find(cmd);
        //    if(it != cmderMap.end())
        //    {
        //        it->second(posehandler);
        //    }
        //}
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmder(commands);
        std::for_each(
            cmders.begin(),
            cmders.end(),
            [this](const Cmder & cmder) noexcept {
                cmder(posehandler).DoOperate(posehandler);
            }
        );
    }

}