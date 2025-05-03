#include "WTools/log.hpp"
#include <cstring>
#include <ctime>
#include <format>
#include <print>
#include <string>

void WtLogger::_write(const char *pMessage, WtMessageType sMessageType, const char *pLogFilePath, bool bVisible, bool bLogToFile, bool bShowTime) {
    std::time_t t = time(0);
    struct tm sNow;
    localtime_s(&sNow, &t);

    std::string strCurrentTime = std::format("{:0>2}:{:0>2}:{:0>2}", sNow.tm_hour, sNow.tm_min, sNow.tm_sec);

    if (bVisible) {
        // std::print("{:<12} {} ({:0>2}:{:0>2}:{:0>2})\n", std::format("[{}]:", sMessageType), pMessage, sNow.tm_hour, sNow.tm_min, sNow.tm_sec);
        std::print("{} {} ({})\n", std::format("[{}]:", sMessageType), pMessage, strCurrentTime);
    }

    if (bLogToFile) {
        std::print("__log__ {} {} ({})\n", std::format("[{}]:", sMessageType), pMessage, strCurrentTime);
    }
}

inline bool WtLogger::needToLog(const char *pLogFilePath) {
    return true ? pLogFilePath : false;
}

inline const char *WtLogger::determinePath(const char *pLogFilePath) {
    return pLogFilePath ? pLogFilePath : m_pLogFilePath;
}

void WtLogger::log(const char *pMessage, const char *pLogFilePath) {
    pLogFilePath = determinePath(pLogFilePath);
    bool bLogToFile = needToLog(pLogFilePath);

    _write(pMessage, WtMessageType::LOG, pLogFilePath, false, true, m_bShowTime);
}

void WtLogger::message(const char *pMessage, const char *pLogFilePath, bool bVisible) {
    pLogFilePath = determinePath(pLogFilePath);
    bool bLogToFile = needToLog(pLogFilePath);

    _write(pMessage, WtMessageType::MESSAGE, pLogFilePath, bVisible, bLogToFile, m_bShowTime);
}

void WtLogger::error(const char *pMessage, const char *pLogFilePath, bool bVisible) {
    pLogFilePath = determinePath(pLogFilePath);
    bool bLogToFile = needToLog(pLogFilePath);

    _write(pMessage, WtMessageType::ERROR, pLogFilePath, bVisible, bLogToFile, m_bShowTime);
}

void WtLogger::warning(const char *pMessage, const char *pLogFilePath, bool bVisible) {
    pLogFilePath = determinePath(pLogFilePath);
    bool bLogToFile = needToLog(pLogFilePath);

    _write(pMessage, WtMessageType::WARNING, pLogFilePath, bVisible, bLogToFile, m_bShowTime);
}

void WtLogger::debug(const char *pMessage, const char *pLogFilePath, bool bVisible) {
    pLogFilePath = determinePath(pLogFilePath);
    bool bLogToFile = needToLog(pLogFilePath);

    _write(pMessage, WtMessageType::WARNING, pLogFilePath, bVisible, bLogToFile, m_bShowTime);
}

void WtLogger::consoleOutput(const char *pMessage) {
    _write(pMessage, WtMessageType::MESSAGE, nullptr, true, false, m_bShowTime);
}
