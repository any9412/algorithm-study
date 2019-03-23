#include <iostream>
#include <exception>
#include <memory>

template <typename T>
class Node
{
public:
    Node() = default;

    Node(T val)
    {
        this->val = val;
    }

    T val;
    std::shared_ptr<Node<T>> next;
};

template <typename T>
class Stack
{
public:
    Stack() = default;

    Stack(T val)
    {
        top = std::make_shared<Node<T>>(val);
    }

    T pop()
    {
        if (top == nullptr)
            throw std::runtime_error("Stack is null!");
        T val = top->val;
        top = top->next;
        return val;
    }

    void push(T val)
    {
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(val);
        node->next = top;
        top = node;
    }

    T peek()
    {
        if (top == nullptr)
            throw std::runtime_error("Stack is null");
        return top->val;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

private:
    std::shared_ptr<Node<T>> top;
};

template <typename T>
class Queue
{
public:
    Queue() = default;

    Queue(T val)
    {
        first = std::make_shared<Node<T>>(val);
        last = first;
    }

    void add(T val)
    {
        std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(val);
        if (first == nullptr) {
            first = node;
            last = first;
        } else {
            last->next = node;
            last = node;
        }
    }

    T remove()
    {
        if (first == nullptr)
            throw std::runtime_error("Queue is null");
        T val = first->val;
        first = first->next;
        return val;

    }

    T peek()
    {
        if (last == nullptr)
            throw std::runtime_error("Queue is null");
        return last->val;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }

private:
    std::shared_ptr<Node<T>> first;
    std::shared_ptr<Node<T>> last;
};

int main()
{
    std::cout << "Test Stack" << std::endl;
    Stack<int> mystack;
    mystack.push(0);
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);

    std::cout << "mystack is " << (mystack.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "top node is " << mystack.peek() << std::endl;

    while(!mystack.isEmpty()) {
        std::cout << "pop " << mystack.pop() << std::endl;
    }

    try {
        mystack.pop();
    } catch (std::runtime_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "mystack is " << (mystack.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << "Stack test done!" << std::endl;
    std::cout << "=============================================" << std::endl;

    std::cout << "Test Queue" << std::endl;
    Queue<int> myqueue;
    myqueue.add(0);
    myqueue.add(1);
    myqueue.add(2);
    myqueue.add(3);
    myqueue.add(4);
    myqueue.add(5);

    std::cout << "myqueue is " << (myqueue.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "last node is " << myqueue.peek() << std::endl;

    while(!myqueue.isEmpty()) {
        std::cout << "remove " << myqueue.remove() << std::endl;
    }

    try {
        myqueue.remove();
    } catch (std::runtime_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "myqueue is " << (myqueue.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "Queue test done!" << std::endl;
    std::cout << "=============================================" << std::endl;

    return 0;
}
