#pragma once
#include "PoseHandler.hpp"

namespace adas
{
    class ICommand
    {
    public:
        virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
        virtual ~ICommand() = default;
    };

    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.Move();
        }
    };
    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.TurnLeft();
        }
    };
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.TurnRight();
        }
    };
    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };
}