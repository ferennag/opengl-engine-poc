#ifndef ENGINE_POC_MOUSEINPUT_H
#define ENGINE_POC_MOUSEINPUT_H

#include <iostream>
#include <map>
#include <memory>
#include <glm/glm.hpp>
#include "MouseMotionObserver.h"

class MouseInput {
public:
    MouseInput(const MouseInput &other) = delete;
    MouseInput(const MouseInput &&other) = delete;
    MouseInput &operator=(const MouseInput &other) = delete;
    MouseInput &operator=(const MouseInput &&other) = delete;
    ~MouseInput();

    static MouseInput &getInstance();

    MouseMotionObserverId subscribeToMouseMotion(MouseMotionObserver *observer);
    [[nodiscard]] glm::vec2 getPosition() const;

    void setPosition(const glm::vec2 &pos);

private:
    static std::unique_ptr<MouseInput> s_instance;
    MouseMotionObserverId m_lastMotionObserverId { 0 };
    std::map<MouseMotionObserverId, MouseMotionObserver *> m_motionObservers;
    bool m_hasLastPos { false };
    glm::vec2 m_pos, m_lastPos;

    MouseInput();
};


#endif //ENGINE_POC_MOUSEINPUT_H
