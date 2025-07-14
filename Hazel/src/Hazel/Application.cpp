#include "hzpch.h"
#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel {

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }
    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if(e.IsInCategory(EventCategoryApplication) ){
            HZ_TRACE(e.ToString());
        }
        if (e.IsInCategory(EventCategoryInput)) {
            HZ_TRACE(e.ToString());
        }
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}
