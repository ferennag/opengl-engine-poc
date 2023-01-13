#ifndef ENGINE_POC_KEYBOARDINPUT_H
#define ENGINE_POC_KEYBOARDINPUT_H

#include <set>
#include <map>
#include <memory>

enum class KeyboardInputType {
    MOVEMENT_FORWARD,
    MOVEMENT_BACKWARD,
    MOVEMENT_LEFT,
    MOVEMENT_RIGHT,
    MOVEMENT_JUMP,
    MOVEMENT_CROUCH,
};

enum class KeyActionType {
    PRESS,
    RELEASE,
    REPEAT
};

class KeyboardInput {
public:
    KeyboardInput(const KeyboardInput &other) = delete;
    KeyboardInput(const KeyboardInput &&other) = delete;
    KeyboardInput& operator=(const KeyboardInput &other) = delete;
    KeyboardInput& operator=(const KeyboardInput &&other) = delete;
    virtual ~KeyboardInput() = default;

    static KeyboardInput& getInstance();

    void registerDefaultFPSKeys();

    void processKeyEvent(int key, KeyActionType action);
    bool isPressed(KeyboardInputType &type) const;
    [[nodiscard]] std::set<KeyboardInputType> getPressedKeys() const;
protected:
    static std::unique_ptr<KeyboardInput> s_instance;

    std::map<int, KeyboardInputType> m_keyboardMapping;
    std::set<KeyboardInputType> m_pressedKeys;

    KeyboardInput() = default;
};


#endif //ENGINE_POC_KEYBOARDINPUT_H
