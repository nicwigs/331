#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include "Exceptions.h"


/***************************
 ***************************
 DO NOT MODIFY THIS CLASS
 ***************************
 ***************************/
template<typename T>
class Stack
{
    public:
        // disable default constructor
        Stack() = delete;
        
        // 1 arg constructor constructor
        Stack(int s) : size(s), values(new T[size]), index(-1) {}
        
        // destructor
        ~Stack()
        {
            delete[] values;
        }

        void push(const T);
        T pop();
        T top() const;
        void clear();
        bool isEmpty() const;
        bool isFull() const;

        /** Getter for the index member.
         *
         * \returns Value of index member
         */
        int getIndex() const { return index; }

    private:
        /// The max size of the stack
        int size;

        /// An array of values in the stack.
        T *values;

        /// The current index in the stack.
        int index;
};

/** Checks if the stack is full.
 */
template <typename T>
bool Stack<T>::isFull() const
{
    return (size-1) == index;                     //full if the index is size -1 
}

/** Pushes a value onto the stack if there is room for it.
 */
template <typename T>
void Stack<T>::push(const T x)
{
    if(isFull())  throw StackFullException();
    values[++index] = x;                         //indexing starts at -1, so add one to get to current index
}

/** Checks if the stack is empty.
 */
template <typename T>
bool Stack<T>::isEmpty() const
{
    return (index == -1);                        //empty if index is -1
}

/** Pop returns and removes the value at the top of the stack.
 */
template <typename T>
T Stack<T>::pop()
{
    if(isEmpty()) throw StackEmptyException();      //dont try if empty 
    T popped = values[index--];                     //pops at index, then decrements index
    return popped;                                  //return popped
}

/** Top returns the value at the top of the stack without removing it.
 */
template <typename T>
T Stack<T>::top() const
{
    if(isEmpty()) throw StackEmptyException();      //dont try if empty
    T peak = values[index];                         //pops at index, do NOT decrement index
    return peak;                                    //return peaked
}
template <typename T>
void Stack<T>::clear()
{
    index = -1;                                     //set index to empty value 
}

#endif //STACK_H