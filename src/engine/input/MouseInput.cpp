#include "MouseInput.h"

std::unique_ptr<MouseInput> MouseInput::s_instance = nullptr;

MouseInput &MouseInput::getInstance() {
    if (s_instance == nullptr) {
        s_instance = std::unique_ptr<MouseInput>(new MouseInput());
    }

    return *s_instance;
}

MouseMotionObserverId MouseInput::subscribeToMouseMotion(MouseMotionObserver* observer) {
    auto id = ++m_lastMotionObserverId;
    m_motionObservers.insert({id, observer});
    return id;
}

void MouseInput::setPosition(const glm::vec2 &pos) {
    m_pos = pos;

    if (!m_hasLastPos) {
        m_lastPos = pos;
        m_hasLastPos = true;
        return;
    }

    const glm::vec2 delta = pos - m_lastPos;
    m_lastPos = pos;

    for (auto &observer: m_motionObservers) {
        observer.second->processMouseMotion(delta.x, -delta.y);
    }
}

glm::vec2 MouseInput::getPosition() const {
    return m_pos;
}

MouseInput::~MouseInput() {
    m_motionObservers.clear();
}

MouseInput::MouseInput() = default;


