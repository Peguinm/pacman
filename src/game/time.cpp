#include "time.h"

Time::Time()
{
    m_currentTime = m_oldTime = SDL_GetTicks();
    m_deltaTime = 1;
}

void
Time::calcDeltaTime()
{
    m_currentTime = SDL_GetTicks();
    m_deltaTime = m_currentTime - m_oldTime;
}

void
Time::updateOldTime()
{
    m_oldTime = m_currentTime;
}

SDL_Time
Time::getDeltaTime() const
{
    return m_deltaTime;
}
