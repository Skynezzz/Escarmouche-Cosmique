#include "pch.h"
#include <windows.h>
#include "Timer.h"

Timer::Timer() :
    mSecondsPerCount(0.0), mDeltaTime(-1.0), mBaseTime(0), mStopTimePressed(0),
    mStopTime(0), mPreviousTime(0), mCurrentTime(0), mIsStopped(false) 
{
    __int64 countsPerSec;
    QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
    mSecondsPerCount = 1.0 / static_cast<double>(countsPerSec);
}

float Timer::TotalTime() {
    if (mIsStopped == true) {
        return static_cast<float>(((mStopTime - mStopTimePressed) - mBaseTime) * mSecondsPerCount);
    }
    else {
        return static_cast<float>(((mCurrentTime - mStopTime) - mBaseTime) * mSecondsPerCount);
    }
}

float Timer::DeltaTime() {
    return static_cast<float>(mDeltaTime);
}

void Timer::Start() {
    __int64 startTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
    if (mIsStopped == true) {
        mStopTime += (startTime - mStopTimePressed);
        mPreviousTime = startTime;
        mStopTimePressed = 0;
        mIsStopped = false;
    }
}

void Timer::Stop() {
    if (mIsStopped == false) {
        __int64 stopTime;
        QueryPerformanceCounter((LARGE_INTEGER*)&stopTime);

        mStopTimePressed = stopTime;
        mIsStopped = true;
    }
}

void Timer::Reset() {
    __int64 currentTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

    mBaseTime = currentTime;
    mPreviousTime = currentTime;
    mStopTime = 0;
    mStopTimePressed = 0;
    mIsStopped = false;
}

void Timer::Tick() {

    if (mIsStopped == true) {
        mDeltaTime = 0.0;
        return;
    }

    __int64 currentTime;
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    mCurrentTime = currentTime; 

    mDeltaTime = ((mCurrentTime - mPreviousTime) * mSecondsPerCount);

    if (mDeltaTime > 0) {
        mDeltaTime = 0;
    }
    mPreviousTime = mCurrentTime;
}