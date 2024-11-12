#include "CmderFactory.hpp"

namespace adas
{
    std::list<Cmder> CmderFactory::GetCmder(const std::string &commands) const noexcept
    {
        std::list<Cmder> CmderList;
        for(const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if (it != cmderMap.end())
            {
                CmderList.push_back(it->second);
            }
        }
        return CmderList;
    }
}