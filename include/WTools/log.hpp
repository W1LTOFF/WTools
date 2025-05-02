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

// struct WtMessage {
//     const char *message;
//     WtMessageType type;
//     bool visible;
//     bool logged;

//     WtMessage(const char *message, WtMessageType type, bool visible = true, bool logged = true);
// };

class WtLogger {
  public:
    void log(const char *message);
    void message(const char *message);
    void error(const char *message);
    void warning(const char *message);

  private:
    /*
    "visible = true" means that message will be visible in console

    "log = true" means that message will be logged into log file
    */
    void _write(const char *message, WtMessageType type, const char *logFilePath, bool visible, bool log);
};

#endif // W1LTOFF_WTOOLS_LOG_HPP