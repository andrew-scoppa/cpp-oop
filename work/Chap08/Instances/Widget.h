#pragma once

class Widget
{
public:
    Widget()
    {
        ++m_instances;
    }
    Widget(const Widget &)
    {
        ++m_instances;
    }
    ~Widget()
    {
        --m_instances;
    }
    static long GetInstances()
    {
        return m_instances;
    }

private:
    static long m_instances;
};