#include "Terminal.h"
#include <vector>
using std::vector;
using std::begin;
#include <iostream>
using std::cout;
using std::endl;
#include <string>

/** Constructor for Terminal objects.
 *
 * \param h The home directory of the terminal.
 */
Terminal::Terminal(string h) : storedStacks(10)
{
    activeStack = new Stack<string>(10);            //make stack
    vector<string> path = splitPath(h);

    for(string dir : path)                          //push directories
            activeStack->push(dir);

    home = h;
    storedStacks.push(activeStack);                 //push active stack pointer onto stack
}

/** Changes the directory of the terminal.
 *
 * \param path The path to change into.
 */
void Terminal::cd(string path)
{
    if(path != "" && path !="~"){                           //case go to home directory
        vector<string> command = splitPath(path);           //split new path

        if (path[0] == '/') activeStack->clear();           //remove current path if starts w/ '/'    

        for(string part : command ){                        //loops through all commands
            if(part == ".." && !activeStack->isEmpty()){    //pop command
                activeStack->pop();                         //remove directory
            }else if(part == "~"){
                activeStack->clear();                       //clear
                vector<string> directories = splitPath(home);
                for(string dir : directories)               //push home back onto stack
                    activeStack->push(dir);    
            }else if(!activeStack->isFull())                //push as long as not full
                activeStack->push(part);                    //add directory
        }
    }else{                                                  //if path is "" and "~"
        activeStack->clear();                               //clear
        vector<string> directories = splitPath(home);
        for(string dir : directories)                       //push home back onto stack
                activeStack->push(dir);
    }
}

/** Gives the current directory of the terminal.
 *
 * \returns The current directory.
 */
string Terminal::pwd()
{
    string pathDir ="/";                                             //all end with '/'
    
    vector<string> directories;
    while(!activeStack->isEmpty()){                                    
        pathDir = "/" + activeStack->top() + pathDir;                //add onto front of string
        directories.insert(begin(directories),activeStack->pop());   //front insert path names into vector
    }   
    for(string dir : directories)                                    //push full path all back onto the stack
            activeStack->push(dir);
    
    return pathDir;                                                  //return working directory string
}

/** Push a directory onto the stack.
 *
 * \param path The path to push onto the stack.
 */
void Terminal::pushd(string path)
{
    if(!storedStacks.isFull()){                         //as long as not full
        activeStack = new Stack<string>(10);            //make stack
        vector<string> directories = splitPath(path);   
        for(string dir : directories)                   //push directories
              activeStack->push(dir);
        storedStacks.push(activeStack);                 //push new stack
    }
}

/** Pop a directory off of the stack.
 *
 */
void Terminal::popd()
{
    if(!storedStacks.isEmpty()){
        Stack<string>* temp = storedStacks.pop();       //make temp pointer to free memory
        if(storedStacks.isEmpty()){                     //if stored stack is now empty, thats bad. Linux says popped then puts the home back on
            storedStacks.push(temp);                    //push it back on, need at least 1 stack from Onsay talked 03/02 at class 
        }else{                                          //if not empty, proceed with pop!
            activeStack = storedStacks.top();           //new activeStack
            delete temp;                                //free memory
        }
    }
}

/** Splits the current path.
 *
 * Takes a path string like “/user/cse331/Documents” and
 * returns a vector of the directories in order, so 
 * “/user/cse331/Documents” => {“user”, “cse331”, “Documents”}.
 *
 * \returns The split in a vector.
 */
vector<string> Terminal::splitPath(string path)
{
    Stack <char> tempStack = Stack<char>(path.length());
    vector<string> directories;

    for (int i = path.length() - 1;i >= 0;i--)  //push the whole path onto stack such that path[0] is stack.top()
        tempStack.push(path[i]);                 

    if (path[0] == '/') tempStack.pop();        //remove top '/'  ie->(top)/user/cse331    

    string word = "";                           //initalize string
    
    while(!tempStack.isEmpty()){        
        if(tempStack.top() == '/'){             //see if end of a word path        
            tempStack.pop();                    //remove '/'
            directories.push_back(word);        //store word in vector
            word = "";                          //reinitalize the word
        }else
            word += tempStack.pop();            //if good, pop into string 
    }
    if(word != "") directories.push_back(word); //if path/morepath/ the end / will cause the last word to be ""..not needed
    return directories;                         //return vector 
}
