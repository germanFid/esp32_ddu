//
// Created by sputnik on 10/20/2026.
//

#ifndef HUD_DEV_CARDATA_H
#define HUD_DEV_CARDATA_H
#include <cstdint>

enum class Gear : int8_t {
    Reverse = -1,
    Neutral = 0,
    First   = 1,
    Second  = 2,
    Third   = 3,
    Fourth  = 4,
    Fifth   = 5,
    Sixth   = 6,
    Seventh = 7,
    Eighth  = 8,
    Ninth   = 9
};

class SpeedInfo {
public:
    SpeedInfo() : speed(0), rpm(0), gear(Gear::Neutral) {}

    bool setData(int newSpeed, int newRpm, Gear newGear) {
        if (static_cast<int8_t>(newGear) < -1 || static_cast<int8_t>(newGear) > 9) {
            return false;
        }

        if (newSpeed < 0 || newRpm < 0) {
            return false;
        }

        speed = newSpeed;
        rpm = newRpm;
        gear = newGear;
        return true;
    }

    int getSpeed() const { return speed; }
    int getRPM() const { return rpm; }
    Gear getGear() const { return gear; }

private:
    int speed;
    int rpm;
    Gear gear;
};

class TimingInfo {
public:
    TimingInfo() : currentLapTimeMs(0), bestLapTimeMs(0), deltaMs(0) {}

    bool setData(uint32_t currentLap, uint32_t bestLap, int32_t currentDelta) {
        currentLapTimeMs = currentLap;
        bestLapTimeMs = bestLap;
        deltaMs = currentDelta;
        return true;
    }

    uint32_t getCurrentLapTimeMs() const { return currentLapTimeMs; }
    uint32_t getBestLapTimeMs() const { return bestLapTimeMs; }
    int32_t getDeltaMs() const { return deltaMs; }

private:
    uint32_t currentLapTimeMs;
    uint32_t bestLapTimeMs;
    int32_t deltaMs;
};

class AssistInfo {
public:
    AssistInfo() : tcLevel(0), absLevel(0), tcActive(false), absActive(false) {}

    bool setData(uint8_t tc, uint8_t abs, bool tcTriggered, bool absTriggered) {
        if (tc > 12 || abs > 12) {
            return false;
        }

        tcLevel = tc;
        absLevel = abs;
        tcActive = tcTriggered;
        absActive = absTriggered;
        return true;
    }

    uint8_t getTcLevel() const { return tcLevel; }
    uint8_t getAbsLevel() const { return absLevel; }

    bool isTcActive() const { return tcActive; }
    bool isAbsActive() const { return absActive; }

private:
    uint8_t tcLevel;
    uint8_t absLevel;
    bool tcActive;
    bool absActive;
};

class CarData {
public:
    const SpeedInfo& getSpeedInfo() const { return speedInfo; }
    const TimingInfo& getTimingInfo() const { return timingInfo; }
    const AssistInfo& getAssistInfo() const { return assistInfo; }

    bool updateSpeedInfo(int speed, int rpm, Gear gear) {
        return speedInfo.setData(speed, rpm, gear);
    }

    bool updateTimingInfo(uint32_t currentLap, uint32_t bestLap, int32_t delta) {
        return timingInfo.setData(currentLap, bestLap, delta);
    }

    bool updateAssistInfo(uint8_t tc, uint8_t abs, bool tcActive, bool absActive) {
        return assistInfo.setData(tc, abs, tcActive, absActive);
    }

private:
    SpeedInfo speedInfo;
    TimingInfo timingInfo;
    AssistInfo assistInfo;
};
#endif //HUD_DEV_CARDATA_H
