#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <memory>
#include <new>

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
        for(const auto cmd : commands)
        {
            std::unique_ptr<ICommand> cmder ;
            if( cmd == 'F' )
            {
                cmder = std::make_unique<FastCommand>();
            }
            else if( cmd == 'M')
            {
                cmder = std::make_unique<MoveCommand>();
            }
            else if( cmd == 'L' )
            {
                cmder = std::make_unique<TurnLeftCommand>();
            }
            else if( cmd == 'R' )
            {
                cmder = std::make_unique<TurnRightCommand>();
            }
            cmder->DoOperate(posehandler);
        }
    }

}