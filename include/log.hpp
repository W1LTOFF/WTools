#ifndef W1LTOFF_WTOOLS_LOG_HPP
#define W1LTOFF_WTOOLS_LOG_HPP

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

struct WtMessage {
    const char *message;
    WtMessageType type;
    bool visible;

    WtMessage(const char *message, WtMessageType type, bool visible = true);
};

template <typename Derived>
class WtOutput {
};

#endif // W1LTOFF_WTOOLS_LOG_HPP