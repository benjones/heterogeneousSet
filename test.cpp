#include "heterogeneousSet.hpp"

#include <set>
#include <iostream>

template <typename T> using realSet = std::set<T>;

int main(int argc, char** argv){
  
  
  HeterogeneousSet<realSet , int, float> hs;
  hs.insert(3);
  hs.insert(5);
  hs.insert(4.5f);
  hs.insert(9.5f);

  auto print = [](auto x){
	std::cout << x << std::endl;
  };

  hs.foreach(print);

  hs.removeIf([](auto x){ return x < 5;});

  hs.foreach(print);
  
  return 0;
}
