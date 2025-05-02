#include "WTools/log.hpp"
#include <ctime>
#include <format>
#include <print>

void WtLogger::_write(const char *pMessage, WtMessageType sMessageType, const char *pLogFilePath, bool bVisible, bool bLogToFile, bool bShowTime) {
    std::time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);
    if (bVisible) {
        // std::print("{:<12} {} ({:0>2}:{:0>2}:{:0>2})\n", std::format("[{}]:", type), message, now.tm_hour, now.tm_min, now.tm_sec);
        std::print("{} {} ({:0>2}:{:0>2}:{:0>2})\n", std::format("[{}]:", sMessageType), pMessage, now.tm_hour, now.tm_min, now.tm_sec);
    }
}

void WtLogger::consoleOutput(const char *pMessage) {
    _write(pMessage, WtMessageType::MESSAGE, nullptr, true, false, m_bShowTime);
}
