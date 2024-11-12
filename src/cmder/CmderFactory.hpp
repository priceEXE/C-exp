#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"


namespace adas
{
    using Cmder = std::function<ActionGroup(PoseHandler &posehandler)>;
    using CmderList = std::list<Cmder>;

    class CmderFactory final
    {
    public:
        CmderFactory(void) = default;
        ~CmderFactory(void) = default;

        CmderFactory(const CmderFactory &) =delete;
        CmderFactory& operator=(const CmderFactory&) = delete;
    public:
        CmderList GetCmder(const std::string& commands) const noexcept;
    private:
        const std::unordered_map<char,Cmder> cmderMap{
            {'M', MoveCommand()},
            {'L', TurnLeftCommand()},
            {'R', TurnRightCommand()},
            {'F', FastCommand()},
            {'B', ReverseCommand()},
            {'Z', TurnRoundCommand()},
        };

    private:
        std::string ParseCommandString(std::string_view commands) const noexcept;
        void ReplaceAll(std::string &inout, std::string_view what, std::string_view with) const noexcept;
    };
    
}