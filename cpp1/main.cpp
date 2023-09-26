
#include <iostream>
#include <boost/dll/import.hpp>
#include <boost/function.hpp>
#include "icompute.hpp"


int main()
{
    // write to std::cout and flush each time
    std::cout << "start" << std::endl;
    std::cout << "Loading so/dll" << std::endl;

    boost::filesystem::path lib_path_add("C:\\code\\cpp_R\\Cpp_reflection\\cpp1\\libaddition.dll");
    boost::filesystem::path lib_path_mul("C:\\code\\cpp_R\\Cpp_reflection\\cpp1\\libmultiplication.dll");

   // boost::function<int(int, int)> compute_add, compute_mul;
    auto compute_add = boost::dll::import_symbol<int(int, int)>(lib_path_add, "compute");
    auto compute_mul = boost::dll::import_symbol<int(int, int)>(lib_path_mul, "compute");
    try
    {
        int a = compute_add(3, 4);
        int b = compute_mul(3, 4);

        std::cout << "Addition (3 + 4): " << compute_add(3, 4) << std::endl;
        std::cout << "Multiplication (3 * 4): " << compute_mul(3, 4) << std::endl;
    }
    catch (const boost::system::system_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "end" << std::endl;
    return 0;
}
