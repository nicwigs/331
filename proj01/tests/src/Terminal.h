#ifndef STACK_HOMEWORK_TERMINAL_H
#define STACK_HOMEWORK_TERMINAL_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Stack.h"

/***************************
 ***************************
 DO NOT MODIFY THIS FILE 
 ***************************
 ***************************/

class Terminal
{
    public:
        Terminal(string h = "/user/cse331");

        void cd(string path);

        void pushd(string path);

        void popd();

        string pwd();

        vector<string> splitPath(string path);

    private:
        /// Pointer to the current stack
        Stack<string> *activeStack = nullptr;

        /// Stack of the pointers to the stored stacks
        Stack<Stack<string> *> storedStacks;

        /// String which is the path to the home directory
        string home;
};

#endif //STACK_HOMEWORK_TERMINAL_H