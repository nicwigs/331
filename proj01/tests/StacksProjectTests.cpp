#include <iostream>
using std::cout;
using std::endl;
#include "gtest/gtest.h"
#include "src/Terminal.h"
#include "src/Terminal.cpp"
#include <vector>
using std::vector;
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>

/** Testing for the Stacks Project.
 */
class StacksProjectTests : public ::testing::Test
{
  protected:
    virtual void SetUp()
    {
    }

    // virtual void TearDown() {}
};

/** Tests to make sure Terminals can be Instantiated.
 */
TEST_F(StacksProjectTests, TestTerminalInstance)
{
    Terminal t("/user/cse331");
}

/** Tests to make sure home pwd is set correctly.
 */
TEST_F(StacksProjectTests, TestTerminalHomePwd)
{
    Terminal t("/user/cse331");
    auto path = t.pwd();
    ASSERT_EQ(path, "/user/cse331/") << "pwd on constructed terminal should print home directory!";
}

/** Tests to make sure cd on subdirectory works properly.
 */
TEST_F(StacksProjectTests, TestTerminalCdSubDir)
{
    Terminal t("/user/cse331");
    t.cd("Documents");
    auto path = t.pwd();
    ASSERT_EQ(path, "/user/cse331/Documents/") << "cd into a subdirectory should be reflected in the path!";
}

/** Tests to make sure cd .. works properly.
 */
TEST_F(StacksProjectTests, TestTerminalCdUp)
{
    Terminal t("/user/cse331");
    t.cd("Documents");
    auto path = t.pwd();
    ASSERT_EQ(path, "/user/cse331/Documents/") << "cd into a subdirectory should be reflected in the path!";
    t.cd("..");
    path = t.pwd();
    ASSERT_EQ(path, "/user/cse331/") << "cd .. should move up one directory";
}

/** Tests to make sure Stacks can be instantiated.
 */
TEST_F(StacksProjectTests, TestStackInstance)
{
    Stack<int> s(10);
}

/** Tests for the Stack::pop operation
 */
TEST_F(StacksProjectTests, TestStackPopEmpty)
{
    Stack<int> s(10);
    try
    {
        s.pop();
        FAIL() << "Popping on an empty stack should throw StackEmptyException!";
    }
    catch( const StackEmptyException& expected ) {} // this catch is for the correct exception
    catch( const std::exception& e)
    {
        FAIL() << "Pop threw an incorrect exception! Popping on an empty stack should throw StackEmptyException!";
    }
}

/** Tests for stack push. */
TEST_F(StacksProjectTests, TestStackPush)
{
    Stack<int> s(10);
    const int testValue = 42;

    // push testValue and pop it to see if the methods worked correctly (on one push/pop)
    s.push(testValue);
    ASSERT_EQ(0, s.getIndex()) << "Index should be incremented after a push.";

    auto value =  s.top();
    ASSERT_EQ(testValue, value) << "The last item pushed to a stack should be the first item popped.";

    const int testValue2 = 15;
    s.push(testValue2);
    ASSERT_EQ(1, s.getIndex()) << "Index should be incremented after a push";

    value = s.top();
    ASSERT_EQ(testValue2, value) << "The last item pushed to a stack should be the first item popped.";
}

/** Tests for stack pop. */
TEST_F(StacksProjectTests, TestStackPop)
{
    Stack<int> s(10);
    const int testValue = 42;

    // push testValue and pop it to see if the methods worked correctly (on one push/pop)
    s.push(testValue);
    auto value = s.pop();
    ASSERT_EQ(-1, s.getIndex()) << "Index should be decremented after a pop.";

    ASSERT_EQ(testValue, value) << "The last item pushed to a stack should be the first item popped.";
}
