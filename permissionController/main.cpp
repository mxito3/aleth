#include "cstring"
#include "fstream"
#include "iostream"
#include "checkPermission.h"
int main()
{
    const char* source = "641b168b-70d9-4c9c-b89f-6748ead526cd";
    checkPermission checker;
    std::string md5 = checker.generateMD5(source);
    std::cout<<checker.check(md5);
}
