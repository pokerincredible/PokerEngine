//
// Created by poker on 2022/7/5.
//

#ifndef POKERENGINE_MOUSEEVENT_H
#define POKERENGINE_MOUSEEVENT_H

#include "Event.h"

namespace PE{

    class PE_API MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y){}
        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY;
    };

    class PE_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset){}

        inline float GetXOffset() const { return m_XOffset; }
        inline float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_XOffset, m_YOffset;
    };

    class PE_API MouseButtonEvnet : public Event
    {
    public:
        inline int GetMouseButton() const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvnet(int button)
            : m_Button(button){}
        int m_Button;
    };

    class PE_API MouseButtonPressedEvent : public MouseButtonEvnet
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvnet(button){}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class PE_API MouseButtonReleasedEvent : public MouseButtonEvnet
    {
    public:
        MouseButtonReleasedEvent(int button)
                : MouseButtonEvnet(button){}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif //POKERENGINE_MOUSEEVENT_H
