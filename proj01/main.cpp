#include <iostream>
using std::cout;
using std::endl;
#include "Terminal.h"

/** Used to run the program and test the changing of the directory. */
int main()
{

    
    Terminal t("/user/cse331");

    cout << t.pwd() << endl;

    t.cd("hello");
    cout << t.pwd() << endl;

    t.cd("deeper/even_deeper/");
    cout << t.pwd() << endl;
    t.cd("6/7/8/9/10/11");
    cout << t.pwd() << endl;
    t.cd("deeper/even_deeper/");
    cout << t.pwd() << endl;
    t.cd("..");
    cout << t.pwd() << endl;

    t.cd("../..");
    cout << t.pwd() << endl;

    t.cd("/etc");
    cout << t.pwd() << endl;

    t.cd("");  
    cout << t.pwd() << endl;

    t.cd("hello");
    cout << t.pwd() << endl;

    t.cd("~/D");
    cout << t.pwd() << endl;

    t.pushd("/2");
    cout << t.pwd() << endl;
    t.pushd("/3");
    cout << t.pwd() << endl;
    t.pushd("/4");
    cout << t.pwd() << endl; 
    t.pushd("/5");
    cout << t.pwd() << endl;
    t.pushd("/6");
    cout << t.pwd() << endl; 
    t.pushd("/7");
    cout << t.pwd() << endl;  
    t.pushd("/8");
    cout << t.pwd() << endl;
    t.pushd("/9");
    cout << t.pwd() << endl; 
    t.pushd("/10");
    cout << t.pwd() << endl;
    t.pushd("/11");
    cout << t.pwd() << endl;
    t.popd();
    cout << t.pwd() << endl;

    t.popd();
    cout << t.pwd() << endl;

    
    return 0;
}