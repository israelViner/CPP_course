#include "iostream"
#include "cassert"
#include "cstddef" 


template <class T>
stack_array <T>::stack_array()
    : m_size(20)
    , m_array(new T[m_size]())
{ 
}


template <class T>
stack_array <T>::stack_array(int s) 
     : m_size(s)
     , m_array(new T[m_size]())
{
    assert(m_size > 0);
}


template <class T>
stack_array <T>::stack_array(const stack_array& stack)
     : m_top(stack.m_top)
     , m_size(stack.m_size)
     , m_array(new T[m_size]())
{
    for (std::size_t i(0); i < m_top; ++i) {
        m_array[i] = stack.m_array[i];
    }
}


template <class T>
stack_array <T>& stack_array<T>::operator=(const stack_array& stack)
{
    if (*this == stack) {
        return *this;
    }
    if (*(this->m_array)) {
        delete [] m_array;
    }
    this->m_size = stack.m_size; 
    this->m_top = stack.m_top;
    this->m_array = new T[this->m_size]();
    for (std::size_t i(0); i < this->m_top; ++i) {
        this->m_array[i] = stack.m_array[i];
    }
    return *this;
}


template <class T>
stack_array <T>::~stack_array() 
{
    delete [] m_array;
}


template <class T>
void stack_array <T>::push(T num) 
{
    assert(!is_fool());
    m_array[m_top++] = num;
    return;
}


template <class T>
T stack_array <T>::pop() 
{
    assert(!is_empty());
    T res = m_array[--m_top];
        return res;    
}


template <class T> 
T stack_array <T>::pick() const
{
    assert(!is_empty());
    T res = m_array[m_top];
    return res;
}


template <class T> 
bool stack_array <T>::is_empty() const
{
    return (m_top == 0);
}


template <class T> 
bool stack_array <T>::is_fool() const
{
    return (m_top == m_size);
}


template <class T> 
std::size_t stack_array <T>::get_size() const
{
    return m_size;
}
 

template <class T> 
std::size_t stack_array <T>::get_top() const
{
    return m_top;
}


template <class T> 
bool stack_array <T>::operator==(const stack_array& stack)
{
    if (!(m_size == stack.m_size && m_top == stack.m_top)) {
        return 0;
    }
    for (std::size_t i(0); i < m_top; ++i) {
        if (m_array[i] != stack.m_array[i]) {
            return 0;
        }
    }
    return 1;
}


template <class T>
void stack_array <T>::print_stack_elements() 
{
    for (std::size_t i(0); i < m_top; ++i) {
        std::cout << m_array[i] << ",  "; 
    } 
    std::cout << std::endl; 
}
