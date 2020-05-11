#include <chrono>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>

// TODO: Start using 'using' instead of 'typedef'
// using TimeVar = std::chrono::high_resolution_clock::time_point;
// https://docs.microsoft.com/en-us/cpp/cpp/aliases-and-typedefs-cpp?view=vs-2019
typedef std::chrono::high_resolution_clock::time_point TimeVar;

// TODO: Why exactly did you need macro, Could have been done using function ?
// TODO: Prefer functions instead of macros for function-like snippets. https://stackoverflow.com/questions/16433133/why-should-or-shouldnt-we-prefer-a-macro-that-accepts-arguments-over-a-function
//   We usually write macros with capital letters
#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

// TODO: Start using trailing return types for C++11 and for C++14 you don't even need to write return type
// TODO: What if the function 'func' returns some value and we need to use it. While calculating time, you made the actual function useless
//       Adding the time calculating entity, the core logic of program should not change
// TODO: Also you are making copy of arguments. We should try to avoid copying
template<typename F, typename ...Args>
double funcTime(F func,Args... args){
    TimeVar t1=timeNow();
    func((args)...);
    return duration(timeNow()-t1);
}

// TODO: level of indentation should be same
// TODO: You are making copy here and then modifying the copy. Did you want to modify original vector or copy?
void alter(std::vector<int> v)
{
    // TODO: Instead of using [], start using at() -- look for std::vector::at
    // https://en.cppreference.com/w/cpp/container/vector/at
        v[0]=4;
}

int main(){
    // TODO: It should be const
    std::vector<int> values={23,76,44,55,89};
    // TODO: funcTime function returns what? Is it seconds, minutes, milliseconds? Print the time unit
    std::cout<<"vector change"<<funcTime(alter,values);
    // TODO: you should flush the std::cout stream at end.

    return 0;
}
