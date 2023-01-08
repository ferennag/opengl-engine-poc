#ifndef ENGINE_POC_MOUSEINPUT_H
#define ENGINE_POC_MOUSEINPUT_H

#include <memory>
#include <glm/glm.hpp>

class MouseInput {
public:
    MouseInput(const MouseInput &other) = delete;
    MouseInput &operator=(const MouseInput &other) = delete;

    static MouseInput &getInstance();


    glm::vec2 getPosition() const { return m_pos; };

    void setPosition(const glm::vec2 &pos) {
        m_pos = pos;
    }

private:
    static std::unique_ptr<MouseInput> s_instance;
    glm::vec2 m_pos;

    MouseInput();
};


#endif //ENGINE_POC_MOUSEINPUT_H
