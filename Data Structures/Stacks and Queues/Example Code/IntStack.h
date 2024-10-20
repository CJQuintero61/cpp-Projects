#ifndef INTSTACK_H
#define INTSTACK_H


class IntStack
{
private:
    int *stackArray; // pointer to stack array
    int stackSize;
    int top; // indicates the top of the stack

public:
    IntStack(int); // constructor
    IntStack(const IntStack &); // copy constructor
    ~IntStack();

    // stack operations
    void push(int);
    void pop(int &);
    bool isFull() const;
    bool isEmpty() const;

    // math
    void add();
    void sub();
};


#endif //INTSTACK
