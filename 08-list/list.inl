#include <iostream>
#include <cassert>

namespace ds {

template <typename T>
List<T>::List(List const& other)
    :  m_head(nullptr)
{
    iterator it = other.begin();
    iterator end_it = other.end();
    while (it != end_it) {
        push_back(*it);
        ++it;
    }
}

template <typename T>
List<T>::~List()
{
    if (m_head != nullptr) {
        clear();
    }
}
    
template <typename T>
List<T>& List<T>::operator=(List const& other)
{
    m_head = nullptr;
        
    if (other.m_head == nullptr) {
        return *this;
    }

    iterator it = other.begin();
    iterator end_it = other.end();
    while (it != end_it) {
        push_back(*it);
        ++it;
    }

    return *this;    
}

template <typename T>
void List<T>::push_front(T const& data)
{
    Node<T> *new_node = new Node<T>(data, m_head);
    m_head = new_node;
}

template <typename T>
T List<T>::pop_front()
{
    assert(m_head != nullptr);
    
    T res = m_head->m_value;
    Node<T> *temp = m_head;
    m_head = m_head->m_next;
    delete temp;
    return res;
}

template <typename T>
void List<T>::push_back(T const& data)
{
    Node<T> *new_node = new Node<T>(data);

    if (m_head == nullptr) {
        m_head = new_node;
        return;
    }

    Node<T> *temp = m_head;    
    while (temp->m_next != nullptr) {
        temp = temp->m_next;
    }

    temp->m_next = new_node;
}

template <typename T>
T List<T>::pop_back()
{
    assert(m_head != nullptr);

    if (m_head->m_next == nullptr) {
        return pop_front();
    }
    
    Node<T> *temp = m_head;    
    while (temp->m_next->m_next != nullptr) {
        temp = temp->m_next;
    }       

    T res = temp->m_next->m_value;
    delete temp->m_next;
    temp->m_next = nullptr;
    return res;  
}

template <typename T>
size_t List<T>::size() const
{
    if (m_head == nullptr) {
        return 0;
    }
    
    size_t count = 0;
    Node<T> *temp = m_head;
    while (temp->m_next != nullptr) {
        ++count;
        temp = temp->m_next;
    }
    ++count;
    
    return count;
}

template <typename T>
bool List<T>::find(T const& data) const
{
    if (m_head == nullptr) {
        return false;
    }
    
    iterator it = this->begin();
    iterator end_it = this->end();
    while (it != end_it) {
        if (*it == data) {
            return true;
        }
        ++it;
    }
    
    return false;
}

template <typename T>
void List<T>::clear()
{
    size_t size_list = size();
    for (size_t i = 0; i < size_list; ++i) {
        pop_front();
    }
}

template <typename T>
T List<T>::pop_by_index(size_t index)
{
    assert(index < size());
    
    if (index == 0) {
        return pop_front();
    }

    size_t count = 1;
    Node<T> *temp = m_head;
    while (count < index) {
        temp = temp->m_next;
        ++count;
    }
    T res = temp->m_next->m_value;
    Node<T>* t = temp->m_next; 
    temp->m_next = temp->m_next->m_next;
    delete t;

    return res;   
}


template <typename T>
T const& List<T>::get_front() const
{
    assert(m_head != nullptr);
    
    return m_head->m_value;      
}

template <typename T>
T const& List<T>::get_back() const
{
    assert(m_head != nullptr);

    if (m_head->m_next == nullptr) {
        return m_head->m_value;
    }
    
    Node<T> *temp = m_head;    
    while (temp->m_next != nullptr) {
        temp = temp->m_next;
    }       

    return temp->m_value;     
}

template <typename T>
T const& List<T>::get_by_index(size_t index) const
{
    assert(index < size());
    
    if (index == 0) {
        return get_front();
    }

    size_t count = 1;
    Node<T> *temp = m_head;
    while (count < index) {
        temp = temp->m_next;
        ++count;
    }
    return temp->m_next->m_value;
} 

// class Node functions

template <typename T>
List<T> weave(List<T> const& list_a, List<T> const& list_b)
{
    List<T> res;
    typename List<T>::iterator it_1 = list_a.begin();
    typename List<T>::iterator it_2 = list_b.begin();

    while (it_1 != list_a.end() && it_2 != list_b.end()) {
        res.push_back(*it_1);
        res.push_back(*it_2);
        ++it_1;
        ++it_2;
    }

    while (it_1 != list_a.end()) {
        res.push_back(*it_1);
        ++it_1;
    }

    while (it_2 != list_b.end()) {
        res.push_back(*it_2);
        ++it_2;
    }

    return res;
}

template <typename T>
List<T> concatenate(List<T> const& list_a, List<T> const& list_b)
{
    List<T> res;
    typename List<T>::iterator it = list_a.begin();
    typename List<T>::iterator end_it = list_a.end();

    while (it != end_it) {
        res.push_back(*it);
        ++it;
    }
    it = list_b.begin();
    end_it = list_b.end();
    while (it != end_it) {
        res.push_back(*it);
        ++it;
    }

    return res;
}

// class iterator functions

template <typename T> 
typename List<T>::iterator& List<T>::iterator::operator++()
{
    m_ptr = m_ptr->m_next;
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, ds::List<T> const& list)
{
    typename List<T>::iterator it = list.begin();
    typename List<T>::iterator end_it = list.end();
    while (it != end_it) {
        os << *it << ", ";
        ++it;
    }
    os << "\n";

    return os;
}

} //namespace ds