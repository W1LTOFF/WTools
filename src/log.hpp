#ifndef W1LTOFF_WTOOLS_LOG_HPP
#define W1LTOFF_WTOOLS_LOG_HPP

enum class MessageType {
  UNDEFINED,
  ERROR,
  ALERT,
  WARNING,
  INFO,
  MESSAGE,
  LOG,
  DEBUG,
};

struct Message {
  const char *text;
  MessageType type;
  bool visible = true;

  Message(const char *message, MessageType type, bool visible = true)
      : text(message), type(type), visible(visible) {
    if (type == MessageType::LOG && this->visible) {
      this->visible = false;
    }
  }
};

#endif // W1LTOFF_WTOOLS_LOG_HPP