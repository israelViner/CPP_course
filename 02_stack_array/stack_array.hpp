#include "cstddef" 


template <class T>
class stack_array 
{
public:    
    explicit stack_array();
    explicit stack_array(int size);
    stack_array(const stack_array& stack);
    stack_array& operator=(const stack_array& stack);    
    ~stack_array();    
    
    void push(T num);
    T pop();
    T pick() const;
    bool is_fool() const;
    bool is_empty() const;    
    std::size_t get_size() const;
    std::size_t get_top() const;
    void print_stack_elements();

private:
    bool operator==(const stack_array& stack);

private:
    std::size_t m_top = 0;
    std::size_t m_size;
    T *m_array;
};

#include "stack_array.inl"

