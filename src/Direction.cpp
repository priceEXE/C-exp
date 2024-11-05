#include "Direction.hpp"

namespace adas
{
    Direction::Direction(const unsigned index, const char heading) noexcept
    {
        this->index = index;
        this->heading = heading;
    }

    static const Direction directions[4] = {
        {0,'E'},
        {1,'S'},
        {2,'W'},
        {3,'N'},
    };

    static const Point points[4] = {
        {1,0},
        {0,-1},
        {-1,0},
        {0,1},
    };

    const Direction &Direction::GetDirection(const char heading) noexcept
    {
        for(const auto& direction : directions)
        {
            if(direction.heading == heading)
            {
                return direction;
            }
        }
        return directions[3];
    }

    const Point& Direction::Move(void) const noexcept
    {
        for(const auto& direction : directions)
        {
            if(direction.heading == heading)
            {
                return points[direction.index];
            }
        }
        return points[3];
    }

    const Direction& Direction::LeftOne(void) const noexcept
    {
        for(const auto& direction : directions)
        {
            if(direction.heading == heading)
            {
                int index = direction.index;
                index = (index + 3) % 4;
                return directions[index];
            }
        }
        return directions[3];
    }

    const Direction& Direction::RightOne(void) const noexcept
    {
        for(const auto& direction : directions)
        {
            if(direction.heading == heading)
            {
                int index = direction.index;
                index = (index + 1) % 4;
                return directions[index];
            }
        }
        return directions[3];
    }

    char Direction::GetHeading(void) const noexcept
    {
        return heading;
    }
}