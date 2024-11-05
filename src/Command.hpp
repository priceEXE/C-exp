#pragma once
#include "PoseHandler.hpp"
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
        const std::function<void(PoseHandler& posehandler)> operate = [](PoseHandler& posehandler) noexcept {
            if(posehandler.IsFast())
            {
                posehandler.Move();
            }
            posehandler.Move();
        };
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
        const std::function<void(PoseHandler &posehandler)> operate = [](PoseHandler &posehandler) noexcept
        {
            if (posehandler.IsFast())
            {
                posehandler.Move();
            }
            posehandler.TurnLeft();
        };
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
        const std::function<void(PoseHandler &posehandler)> operate = [](PoseHandler &posehandler) noexcept
        {
            if (posehandler.IsFast())
            {
                posehandler.Move();
            }
            posehandler.TurnRight();
        };
    };
    class FastCommand final //: public ICommand
    {
    public:
        //void DoOperate(PoseHandler &poseHandler) const noexcept
        //{
        //    poseHandler.Fast();
        //}
        const std::function<void(PoseHandler &posehandler)> operate = [](PoseHandler &posehandler) noexcept
        {
            posehandler.Fast();
        };
    };
}