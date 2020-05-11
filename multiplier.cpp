#include<iostream>
int main(){
    // TODO: indentation ?
    // TODO: 'x' should be const
auto multiplier = [](int x) {
    // TODO: 'y' should be const
  return [=](int y) { return x * y; };
};

auto twice = multiplier(2);
// TODO: At least add nextline
std::cout << twice(5) << '\n';
std::cout << twice(12) << '\n';     

auto thrice = multiplier(3);
std::cout << thrice(5) << '\n';      
std::cout << thrice(6) << '\n';      
}
