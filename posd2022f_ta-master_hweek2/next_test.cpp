// next example
#include <iostream>     // std::cout
#include <iterator>     // std::next
#include <list>         // std::list
#include <algorithm>    // std::for_each

#include <typeinfo>


int main () {
  // std::list<int> mylist;
  // for (int i=0; i<10; i++) mylist.push_back (i*10);

  // std::cout << "mylist:";
  // std::for_each (mylist.begin(),
  //                std::next(mylist.begin(),3),
  //                [](int x) {std::cout << ' ' << x;} );

  // std::cout << '\n';
  std::string k;

  std::cout << typeid(k).name() << std::endl;



  return 0;
}