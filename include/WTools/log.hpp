#ifndef W1LTOFF_WTOOLS_LOG_HPP
#define W1LTOFF_WTOOLS_LOG_HPP

#include <format>
#include <print>

enum class WtMessageType {
    ERROR,
    ALERT,
    WARNING,
    INFO,
    MESSAGE,
    LOG,
    DEBUG,
    UNDEFINED,
};

template <>
struct std::formatter<WtMessageType, char> {
    constexpr auto parse(format_parse_context &ctx) const {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const WtMessageType &mt, FormatContext &ctx) const {

        switch (mt) {
        case WtMessageType::ERROR:
            return format_to(ctx.out(), "ERROR");
        case WtMessageType::ALERT:
            return format_to(ctx.out(), "ALERT");
        case WtMessageType::WARNING:
            return format_to(ctx.out(), "WARNING");
        case WtMessageType::INFO:
            return format_to(ctx.out(), "INFO");
        case WtMessageType::MESSAGE:
            return format_to(ctx.out(), "MESSAGE");
        case WtMessageType::LOG:
            return format_to(ctx.out(), "LOG");
        case WtMessageType::DEBUG:
            return format_to(ctx.out(), "DEBUG");
        default:
            return format_to(ctx.out(), "UNDEFINED");
        }
    }
};

class WtLogger {
  public:
    const char *m_pLogFilePath;
    bool m_bLogToFile = true;
    bool m_bShowTime = true;
    bool m_bVisible = true;
    void log(const char *pMessage);
    void message(const char *pMessage);
    void error(const char *pMessage);
    void warning(const char *pMessage);
    void consoleOutput(const char *pMessage);

  private:
    /*
    "bVisible = true" means that message will be visible in console

    "bLogToFile = true" means that message will be logged into log file
    */
    void _write(const char *pMessage, WtMessageType sMessageType, const char *pLogFilePath, bool bVisible, bool bLogToFile, bool bShowTime);
};

#endif // W1LTOFF_WTOOLS_LOG_HPP