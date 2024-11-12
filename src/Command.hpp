#pragma once
#include "PoseHandler.hpp"
#include "ActionGroup.hpp"
#include <functional>
namespace adas
{
    //class ICommand
    //{
    //public:
    //    virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    //    virtual ~ICommand() = default;
    //};

    class MoveCommand final //: public ICommand
    {
    public:
        //void DoOperate(PoseHandler &poseHandler) const noexcept override
        //{
        //    if (poseHandler.IsFast())
        //        poseHandler.Move();
        //    poseHandler.Move();
        //}
        //const std::function<void(PoseHandler& posehandler)> operate = [](PoseHandler& posehandler) noexcept {
        //    if(posehandler.IsFast())
        //    {
        //        posehandler.Move();
        //    }
        //    posehandler.Move();
        //};
        ActionGroup operator()(PoseHandler & posehandler) const noexcept
        {
            ActionGroup actiongroup;
            const auto action = posehandler.IsReverse() ? 
                ActionType::BACKWORD_1_STEP_ACTION :
                ActionType::FORWARD_1_STEP_ACTION;

                if(posehandler.IsFast())
                {
                    actiongroup.PushAction(action);
                }
                actiongroup.PushAction(action);
            return actiongroup;
        }
    };
    class TurnLeftCommand final //: public ICommand
    {
    public:
        //void DoOperate(PoseHandler &poseHandler) const noexcept override
        //{
        //    if (poseHandler.IsFast())
        //        poseHandler.Move();
        //    poseHandler.TurnLeft();
        //}
        //const std::function<void(PoseHandler &posehandler)> operate = [](PoseHandler &posehandler) noexcept
        //{
        //    if (posehandler.IsFast())
        //    {
        //        posehandler.Move();
        //    }
        //    posehandler.TurnLeft();
        //};
        ActionGroup operator()(PoseHandler& posehandler) const noexcept
        {
            ActionGroup actiongroup;
            const auto action = posehandler.IsReverse() ? 
            ActionType::BACKWORD_1_STEP_ACTION : 
            ActionType::FORWARD_1_STEP_ACTION;
            if (posehandler.IsFast())
            {
                actiongroup.PushAction(action);
            }
            if(action == ActionType::BACKWORD_1_STEP_ACTION)
                actiongroup.PushAction(ActionType::REVERSE_TURNLEFT_ACTION);
            else if(action == ActionType::FORWARD_1_STEP_ACTION)
                actiongroup.PushAction(ActionType::TURNLEFT_ACTION);
            return actiongroup;
        }
    };
    class TurnRightCommand final //: public ICommand
    {
    public:
        //void DoOperate(PoseHandler &poseHandler) const noexcept override
        //{
        //    if (poseHandler.IsFast())
        //        poseHandler.Move();
        //    poseHandler.TurnRight();
        //}
        //const std::function<void(PoseHandler &posehandler)> operate = [](PoseHandler &posehandler) noexcept
        //{
        //    if (posehandler.IsFast())
        //    {
        //        posehandler.Move();
        //    }
         //   posehandler.TurnRight();
        //};
        ActionGroup operator()(PoseHandler &posehandler) const noexcept
        {
            ActionGroup actiongroup;
            const auto action = posehandler.IsReverse() ? ActionType::BACKWORD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            if (posehandler.IsFast())
            {
                actiongroup.PushAction(action);
            }
            if (action == ActionType::BACKWORD_1_STEP_ACTION)
                actiongroup.PushAction(ActionType::REVERSE_TURNRIGHT_ACTION);
            else if (action == ActionType::FORWARD_1_STEP_ACTION)
                actiongroup.PushAction(ActionType::TURNRIGHT_ACTION);    
            return actiongroup;
        }
    };
    class FastCommand final //: public ICommand
    {
    public:
        //void DoOperate(PoseHandler &poseHandler) const noexcept
        //{
        //    poseHandler.Fast();
        //}
        //const std::function<void(PoseHandler &posehandler)> operate = [](PoseHandler &posehandler) noexcept
        //{
         //   posehandler.Fast();
        //};

        ActionGroup operator()(PoseHandler &posehandler) const noexcept
        {
            ActionGroup actiongroup;
            actiongroup.PushAction(ActionType::BF_FAST_ACTION);
            return actiongroup;
        }
    };

    class ReverseCommand final
    {
    public:
        ActionGroup operator()(PoseHandler &posehandler) const noexcept
        {
            ActionGroup actiongroup;
            actiongroup.PushAction(ActionType::BE_REVERSE_ACTION);
            return actiongroup;
        }
    };

    class TurnRoundCommand final
    {
        public:
            ActionGroup operator()(PoseHandler &posehandler) const noexcept
            {
                if (posehandler.IsReverse())
                {
                    return ActionGroup();
                }
                else
                {
                    if (posehandler.IsFast())
                    {
                        return ActionGroup({
                            ActionType::FORWARD_1_STEP_ACTION,
                            ActionType::TURNLEFT_ACTION,
                            ActionType::FORWARD_1_STEP_ACTION,
                            ActionType::TURNLEFT_ACTION,
                        });
                    }
                    else
                    {
                        return ActionGroup({
                            ActionType::TURNLEFT_ACTION,
                            ActionType::FORWARD_1_STEP_ACTION,
                            ActionType::TURNLEFT_ACTION,
                        });
                    }
                }
            }
    };
}