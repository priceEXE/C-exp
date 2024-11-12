#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"

namespace adas
{
    class CmderFactory final
    {
    public:
        CmderFactory(void) = default;
        ~CmderFactory(void) = default;

        CmderFactory(const CmderFactory &) =delete;
        CmderFactory& operator=(const CmderFactory&) = delete;
    public:
        std::list<std::function<void(PoseHandler& posehandler)>> GetCmder(const std::string& commands) const noexcept;
    private:
        const std::unordered_map<char, std::function<void(PoseHandler &posehandler)>> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()},
        };
    };
}