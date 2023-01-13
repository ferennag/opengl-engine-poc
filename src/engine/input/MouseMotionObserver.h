#ifndef ENGINE_POC_MOUSEMOTIONOBSERVER_H
#define ENGINE_POC_MOUSEMOTIONOBSERVER_H

using MouseMotionObserverId = int;

class MouseMotionObserver {
public:
    MouseMotionObserver() = default;
    virtual ~MouseMotionObserver() = default;
    virtual void processMouseMotion(double deltaX, double deltaY) = 0;
};

#endif //ENGINE_POC_MOUSEMOTIONOBSERVER_H
