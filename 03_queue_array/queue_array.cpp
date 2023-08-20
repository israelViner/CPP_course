#include "iostream"
#include "cassert"

#define DEFAULT_SIZE 20

/* Constructors */
template <class T>
queue_array<T>::queue_array()
    : m_en(DEFAULT_SIZE), m_de(DEFAULT_SIZE)
{
}

template <class T>
queue_array<T>::queue_array(int size)
    : m_en(size), m_de(size)
{
    assert(size > 0);
}

/* Functions */
template <class T>
void queue_array<T>::enqueue(T num)
{
    assert(!is_fool());

    if (!m_queue_status)
    {
        swap();
    }

    m_en.push(num);
    return;
}

template <class T>
T queue_array<T>::dequeue()
{
    assert(!is_empty());

    if (m_queue_status)
    {
        swap();
    }

    T res = m_de.pop();
    return res;
}

template <class T>
T queue_array<T>::pick()
{
    assert(!is_empty());
    if (m_queue_status)
    {
        swap();
    }
    T res = m_de.pick();
    return res;
}

template <class T>
bool queue_array<T>::is_empty() const
{
    return ((m_en.is_empty() && m_de.is_empty()));
}

template <class T>
bool queue_array<T>::is_fool() const
{
    return ((m_en.is_fool() || m_de.is_fool()));
}

template <class T>
std::size_t queue_array<T>::get_size() const
{
    if (m_queue_status)
    {
        return m_en.get_size();
    }
    return m_de.get_size();
}

template <class T>
void queue_array<T>::swap()
{
    if (m_queue_status)
    {
        std::size_t top = m_en.get_top();
        for (std::size_t i(0); i < top; ++i)
        {
            m_de.push(m_en.pop());
        }
    }
    else
    {
        std::size_t top = m_de.get_top();
        for (std::size_t i(0); i < top; ++i)
        {
            m_en.push(m_de.pop());
        }
    }
    m_queue_status = !m_queue_status;
    return;
}

template <class T>
std::size_t queue_array<T>::get_top() const
{
    if (m_queue_status)
    {
        return m_en.get_top();
    }
    return m_de.get_top();
}

template <class T>
void queue_array<T>::print_queue_elements()
{
    if (!m_queue_status)
    {
        swap();
    }
    m_en.print_stack_elements();
}