#ifndef _TIME_H
#define _TIME_H

#include "SDL3/SDL.h"

class Time
{
  public:
    ~Time(){};
    Time();

    SDL_Time getDeltaTime() const;
    void calcDeltaTime();
    void updateOldTime();

  private:
    SDL_Time m_oldTime, m_currentTime, m_deltaTime;
};

#endif