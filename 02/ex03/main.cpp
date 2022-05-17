#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  
  // 이거 해야하나?
  std::cout << a + 1 << std::endl;
  std::cout << 1 + a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max( a, b ) << std::endl;

  return 0;
}
