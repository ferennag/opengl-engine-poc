#include <GLFW/glfw3.h>
#include "KeyboardInput.h"

std::unique_ptr<KeyboardInput> KeyboardInput::s_instance = std::unique_ptr<KeyboardInput>(new KeyboardInput());

KeyboardInput &KeyboardInput::getInstance() {
    return *s_instance;
}

void KeyboardInput::processKeyEvent(int key, KeyActionType action) {
    if (m_keyboardMapping.contains(key)) {
        auto type = m_keyboardMapping.find(key)->second;

        if (action == KeyActionType::PRESS) {
            m_pressedKeys.insert(type);
        } else if (action == KeyActionType::RELEASE) {
            m_pressedKeys.erase(type);
        }
    }

}

bool KeyboardInput::isPressed(KeyboardInputType &type) const {
    return m_pressedKeys.contains(type);
}

std::set<KeyboardInputType> KeyboardInput::getPressedKeys() const {
    return m_pressedKeys;
}

void KeyboardInput::registerDefaultFPSKeys() {
    m_keyboardMapping.insert({ GLFW_KEY_W, KeyboardInputType::MOVEMENT_FORWARD });
    m_keyboardMapping.insert({ GLFW_KEY_UP, KeyboardInputType::MOVEMENT_FORWARD });

    m_keyboardMapping.insert({ GLFW_KEY_S, KeyboardInputType::MOVEMENT_BACKWARD });
    m_keyboardMapping.insert({ GLFW_KEY_DOWN, KeyboardInputType::MOVEMENT_BACKWARD });

    m_keyboardMapping.insert({ GLFW_KEY_A, KeyboardInputType::MOVEMENT_LEFT });
    m_keyboardMapping.insert({ GLFW_KEY_LEFT, KeyboardInputType::MOVEMENT_LEFT });

    m_keyboardMapping.insert({ GLFW_KEY_D, KeyboardInputType::MOVEMENT_RIGHT });
    m_keyboardMapping.insert({ GLFW_KEY_RIGHT, KeyboardInputType::MOVEMENT_RIGHT });

    m_keyboardMapping.insert({ GLFW_KEY_SPACE, KeyboardInputType::MOVEMENT_JUMP });
    m_keyboardMapping.insert({ GLFW_KEY_LEFT_CONTROL, KeyboardInputType::MOVEMENT_CROUCH });
    m_keyboardMapping.insert({ GLFW_KEY_RIGHT_CONTROL, KeyboardInputType::MOVEMENT_CROUCH });
}

