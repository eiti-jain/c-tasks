#include<iostream>
int main(){
auto multiplier = [](int x) {
  return [=](int y) { return x * y; };
};

auto twice = multiplier(2);
std::cout << twice(5);      
std::cout << twice(12);     

auto thrice = multiplier(3);
std::cout << thrice(5);      
std::cout << thrice(6);      
}
