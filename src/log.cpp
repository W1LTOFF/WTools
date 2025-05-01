#include "log.hpp"

WtMessage::WtMessage(const char *message, WtMessageType type, bool visible) : message(message), type(type), visible(visible) {
    if (type == WtMessageType::LOG && this->visible) {
        this->visible = false;
    }
}