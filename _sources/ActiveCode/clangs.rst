C and C++
---------

Now for the most famous program of all time!  This program is often the first program someone will write in a new language.  Here it is presented in the original C language!

.. activecode:: hw_in_c
    :language: c

    #include <stdio.h>

    int main() {
        printf("Hello World!");
    }


You can also have C++ code in an activecode.

.. activecode:: lc2
    :language: cpp
    :stdin: 100
    :compileargs: ['-std=c++11', '-Wall', '-Wpedantic']

    #include <iostream>
    using namespace std;
    int main() {
        cout << "Hello World!" << endl;   cout << "Welcome to C++ Programming" << endl;
    }

.. reveal:: lc2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block:: rst

      .. activecode:: lc2
         :language: cpp
         :stdin: 100
         :compileargs: ['-std=c++11', '-Wall', '-Wpedantic']

         #include <iostream>
         using namespace std;
         int main() {
             cout << "Hello World!" << endl;   cout << "Welcome to C++ Programming" << endl;
         }


Unit Tests in C++
---------------------

You can also have hidden unit tests in C++ using catch.hpp.  Place the unit tests after '===='.

.. activecode:: cpp_units
    :language: cpp
    :autograde: unittest

    Write a function to compute the factorial of a. number
    ~~~~
    unsigned int Factorial( unsigned int number ) {
        return number <= 1 ? number : Factorial(number-1)*number;
    }

    ====

    #define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
    #include <catch.hpp>

    TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
    }

    TEST_CASE( "Factorial of 0", "[fact0]" ) {
    REQUIRE( Factorial(0) == 1);
    }


.. reveal:: catch2_src
   :showtitle: Show Source
   :hidetitle: Hide Source
   :modaltitle: Source for the example above

   .. code-block::

      .. activecode:: cpp_units
          :language: cpp
          :autograde: unittest

          Write a function to compute the factorial of a. number
          ~~~~
          unsigned int Factorial( unsigned int number ) {
              return number <= 1 ? number : Factorial(number-1)*number;
          }

          ====

          #define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do   this in one cpp file
          #include <catch.hpp>

          TEST_CASE( "Factorials are computed", "[factorial]" ) {
          REQUIRE( Factorial(1) == 1 );
          REQUIRE( Factorial(2) == 2 );
          REQUIRE( Factorial(3) == 6 );
          REQUIRE( Factorial(10) == 3628800 );
          }

          TEST_CASE( "Factorial of 0", "[fact0]" ) {
          REQUIRE( Factorial(0) == 1);
          }

