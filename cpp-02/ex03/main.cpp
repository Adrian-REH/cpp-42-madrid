
#include "Fixed.hpp"
#include <iostream>
/**      A
 *     /   \
 *    /     \
 *   /       \
 *  B_ _ _ _ _C
 * A = (1, 5)
 * B = ()
 */
int main()
{
	Fixed		a;
	std::cout << "test "<< Fixed( 5.05f ) << std::endl;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b) << std::endl;
	
	return 0;
}
