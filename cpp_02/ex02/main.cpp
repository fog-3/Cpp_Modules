/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:59:48 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/11/01 18:44:43 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main( void ) {
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    return 0;
}

/* void printTest(const std::string& testName) {
    std::cout << "\n\033[36m=== " << testName << " ===\033[0m" << std::endl;
}

int main( void ) {
    std::cout << std::fixed << std::setprecision(3);
    
    printTest("CONSTRUCTORS AND CONVERSIONS");
    Fixed a;                    // Default
    Fixed b(10);                // Int
    Fixed c(3.14f);             // Float
    Fixed d(c);                 // Copy
    
    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 10): " << b << std::endl;
    std::cout << "c (float 3.14): " << c << std::endl;
    std::cout << "d (copy of c): " << d << std::endl;
    std::cout << "b.toInt(): " << b.toInt() << std::endl;
    std::cout << "c.toInt(): " << c.toInt() << std::endl;
    
    printTest("ARITHMETIC OPERANDS");
    Fixed e(5.5f);
    Fixed f(2.2f);
    
    std::cout << e << " + " << f << " = " << e + f << std::endl;
    std::cout << e << " - " << f << " = " << e - f << std::endl;
    std::cout << e << " * " << f << " = " << e * f << std::endl;
    std::cout << e << " / " << f << " = " << e / f << std::endl;
    
    // Division by cero
    Fixed zero(0);
    std::cout << e << " / " << zero << " = " << e / zero << std::endl;
    
    printTest("COMPARISON OPERATORS");
    Fixed x(5.0f);
    Fixed y(3.0f);
    Fixed z(5.0f);
    
    std::cout << x << " > " << y << " : " << (x > y) << std::endl;
    std::cout << x << " < " << y << " : " << (x < y) << std::endl;
    std::cout << x << " >= " << z << " : " << (x >= z) << std::endl;
    std::cout << x << " <= " << z << " : " << (x <= z) << std::endl;
    std::cout << x << " == " << z << " : " << (x == z) << std::endl;
    std::cout << x << " != " << y << " : " << (x != y) << std::endl;
    
    printTest("INCREASE AND DECREASE");
    Fixed counter(1.5f);
    
    std::cout << "Init value: " << counter << std::endl;
    std::cout << "++counter: " << ++counter << std::endl;
    std::cout << "counter++: " << counter++ << std::endl;
    std::cout << "After: " << counter << std::endl;
    std::cout << "--counter: " << --counter << std::endl;
    std::cout << "counter--: " << counter-- << std::endl;
    std::cout << "After: " << counter << std::endl;
    
    printTest("MIN AND MAX FUNCTIONS");
    Fixed num1(7.8f);
    Fixed num2(4.2f);
    const Fixed num3(9.1f);
    const Fixed num4(2.3f);
    
    std::cout << "min(" << num1 << ", " << num2 << ") = " << Fixed::min(num1, num2) << std::endl;
    std::cout << "max(" << num1 << ", " << num2 << ") = " << Fixed::max(num1, num2) << std::endl;
    std::cout << "min(const " << num3 << ", " << num4 << ") = " << Fixed::min(num3, num4) << std::endl;
    std::cout << "max(const " << num3 << ", " << num4 << ") = " << Fixed::max(num3, num4) << std::endl;
    
    printTest("ASSIGNMENT OPERATOR");
    Fixed original(15.75f);
    Fixed copy;
    copy = original;
    std::cout << "original: " << original << std::endl;
    std::cout << "copy = original: " << copy << std::endl;
    
    printTest("COMPLEX OPERATIONS");
    Fixed result = (Fixed(10) + Fixed(2.5f)) * Fixed(2) - Fixed(1) / Fixed(4);
    std::cout << "(10 + 2.5) * 2 - 1/4 = " << result << std::endl;
    
    printTest("ACCURACY AND LIMITS");
    Fixed small(0.0039f);  // ≈ 1/256 (min accuracy)
    Fixed large(100.5f);
    std::cout << "Small: " << small << std::endl;
    std::cout << "Big: " << large << std::endl;
    std::cout << "Sum: " << small + large << std::endl;
    
    printTest("CHAINING");
    Fixed chain(1.0f);
    chain = chain + Fixed(2.0f) * Fixed(3.0f);
    std::cout << "1.0 + 2.0 * 3.0 = " << chain << std::endl;
    
    std::cout << "\n\033[32m✅ All tests completed!\033[0m" << std::endl;
    
    return 0;
} */
