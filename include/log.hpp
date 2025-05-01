#ifndef W1LTOFF_WTOOLS_LOG_HPP
#define W1LTOFF_WTOOLS_LOG_HPP

enum class WtMessageType {
    UNDEFINED,
    ERROR,
    ALERT,
    WARNING,
    INFO,
    MESSAGE,
    LOG,
    DEBUG,
};

struct WtMessage {
    const char *message;
    WtMessageType type;
    bool visible = true;

    WtMessage(const char *message, WtMessageType type, bool visible = true);
};

#endif // W1LTOFF_WTOOLS_LOG_HPP