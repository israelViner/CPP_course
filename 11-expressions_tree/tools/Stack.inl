
namespace et {
    
template <typename T>
Stack<T>::Stack() 
    : m_stack() 
{    
} 

template <typename T>
T Stack<T>::pop()
{
    T res = m_stack.top();
    m_stack.pop();
    return res;
}

template <typename T>
T Stack<T>::top()
{
    T res = m_stack.top();
    return res;
}

template <typename T>
void Stack<T>::push(T const& data)
{
    m_stack.push(data);
}

template <typename T>
bool Stack<T>::empty()
{
    return m_stack.empty();
}

} // namespace et 
