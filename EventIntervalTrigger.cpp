//
// Created by drlim on 22/01/2021.
//

#include "EventIntervalTrigger.h"

EventIntervalTrigger::EventIntervalTrigger(std::chrono::microseconds interval) : interval(interval) {}

void EventIntervalTrigger::start(std::chrono::microseconds currentTime) {
    startTime = currentTime;
    running = true;
    eventCounter = 0;
}

void EventIntervalTrigger::startNext(std::chrono::microseconds currentTime) {
    startTime = currentTime;
    running = true;
    eventCounter = 1;
}

void EventIntervalTrigger::stop() {
    running = false;
}

bool EventIntervalTrigger::hasElapsed(std::chrono::microseconds currentTime) {
    if (running) {
        std::chrono::microseconds nextTrigger = startTime + interval * eventCounter;
        if (currentTime >= nextTrigger) {
            eventCounter++;
            return true;
        }
    }
    return false;
}

void EventIntervalTrigger::setInterval(const std::chrono::microseconds interval) {
    EventIntervalTrigger::interval = interval;
}
