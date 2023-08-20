#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP

#include "cstddef" 
#include "../02_stack_array/stack_array.hpp"


template <class T>
class queue_array
{
public:    
    explicit queue_array();
    explicit queue_array(int size);
    queue_array(const queue_array& stack) = default;
    queue_array& operator=(const queue_array& stack) = default;
        
    /* Functions */
    void enqueue(T num);
    T dequeue();
    T pick();
    bool is_fool() const;
    bool is_empty() const;
    std::size_t get_size() const;
    std::size_t get_top() const;
    void print_queue_elements();

private:
    void swap();

private:
    stack_array <T> m_en;
    stack_array <T> m_de;
    bool m_queue_status = true;
};

#include "queue_array.inl"

#endif
