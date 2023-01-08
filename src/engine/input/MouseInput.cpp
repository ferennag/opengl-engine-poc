#include "MouseInput.h"

std::unique_ptr<MouseInput> MouseInput::s_instance = std::unique_ptr<MouseInput> (new MouseInput());

MouseInput &MouseInput::getInstance() {
    return *s_instance;
}

MouseInput::MouseInput() = default;


