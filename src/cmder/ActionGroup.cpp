#include"ActionGroup.hpp"
#include "CmderFactory.hpp"

#include <vector>
#include <algorithm>

namespace adas
{
    class ForwardAction final {
    public:
        void operator()(PoseHandler & posehandler) const noexcept{
            posehandler.Forward();
        }
    };

    class BackwardAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.Backward();
        }
    };

    class TurnLeftAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.TurnLeft();
        }
    };

    class TurnRightAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.TurnRight();
        }
    };

    class ReverseTurnLeftAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.TurnRight();
        }
    };

    class ReverseTurnRightAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.TurnLeft();
        }
    };

    class BeReverseAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.Reverse();
        }
    };

    class BeFastAction final
    {
    public:
        void operator()(PoseHandler &posehandler) const noexcept
        {
            posehandler.Fast();
        }
    };

    ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions) {}

    void ActionGroup::PushAction(const ActionType ActionType) noexcept {
        actions.push_back(ActionType);
    }

    void ActionGroup::DoOperate(PoseHandler& posehandler) const noexcept {
        static std::vector<std::function<void(PoseHandler & posehandler)>> actionVec = {
            ForwardAction(),
            BackwardAction(),
            TurnLeftAction(),
            TurnRightAction(),
            ReverseTurnLeftAction(),
            ReverseTurnRightAction(),
            BeFastAction(),
            BeReverseAction(),
        };
        std::for_each(actions.begin(), actions.end(), [&posehandler](const ActionType actionType) mutable noexcept{ 
            actionVec[static_cast<uint16_t>(actionType)](posehandler); 
        });
    }

    
}

/*could not convert : from '<brace-enclosed initializer list>' to 'std::vector<>'*/