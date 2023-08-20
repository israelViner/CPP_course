#ifndef LIST_H
#define LIST_H

#include <cstddef> // std::size_t

namespace ds
{

template <typename T>
class List
{
private:
    template <typename U> class Node;

public:
    class iterator;
    
    using value_type = T;

    List() : m_head(nullptr) {}
    ~List();
    List(List const &other);
    List &operator=(List const &other);

    size_t size() const;
    bool find(T const &data) const;
    void clear();

    void push_front(T const &data);
    void push_back(T const &data);
    T pop_front();
    T pop_back();
    T pop_by_index(size_t index);

    T const& get_front() const;
    T const& get_back() const;
    T const& get_by_index(size_t index) const;

    iterator begin() const { return m_head; }
    iterator end() const { return nullptr; }

    class iterator
    {
    public:
        explicit iterator() : m_ptr(nullptr) {}
        iterator(Node<T> *other) : m_ptr(other) {}
        iterator(iterator const& other) : m_ptr(other.m_ptr) {}

        T &operator*() { return m_ptr->m_value; }
        bool operator!=(iterator const &other) const { return (m_ptr != other.m_ptr); }
        iterator &operator++();        

    private:
        Node<T> *m_ptr;
    }; // End class iterator

private:
    Node<T> *m_head;

    template <typename U>
    class Node
    {
    public:
        explicit Node(U data) : m_value(data), m_next(nullptr){};
        explicit Node(U data, Node *other) : m_value(data), m_next(other){};      

        U m_value;
        Node *m_next;
    }; // End class Node

}; // End class List

template <typename T>
List<T> weave(List<T> const &list_a, List<T> const &list_b);

template <typename T>
List<T> concatenate(List<T> const &list_a, List<T> const &list_b);

template <typename T>
std::ostream &operator<<(std::ostream &os, ds::List<T> const &list);

} // namespace ds

#include "list.inl"

#endif