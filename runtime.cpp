#include <chrono>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
template<typename F, typename ...Args>
double funcTime(F func,Args... args){
    TimeVar t1=timeNow();
    func((args)...);
    return duration(timeNow()-t1);
}
void alter(std::vector<int> v)
{
        v[0]=4;
}

int main(){
    std::vector<int> values={23,76,44,55,89};
    std::cout<<"vector change"<<funcTime(alter,values);


    return 0;
}
