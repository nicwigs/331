#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

/***********************************
 ***********************************
 *****Do not modify this file. *****
 ***********************************
 ***********************************/

/** Do not modify this class. */
class StackEmptyException : public std::exception {
    virtual const char* what() const throw() { return "The stack is empty!"; }
};

/** Do not modify this class. */
class StackFullException : public std::exception {
    virtual const char* what() const throw() { return "The stack is full!"; }
};

/** Do not modify this class. */
class MissingImplementationException : public std::exception {
    virtual const char* what() const throw() { return "Did you fill in this function?"; }
};

#endif //EXCEPTIONS_H
