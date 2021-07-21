#include <iostream>
#include <string>
using std::string;

#define PAUSE system("pause");

// args: -i <source file/dir> (optional)
//       -o <output file/dir>
//       -f <...> optional flags
//       flag definitions:
//          
// auto detect language (css, scss, sass)
// make list of discord css classes and ids

int main(int argc, const char** argv)
{
    for (int i=0; i < argc; i++)
        std::cout << i << ": " << argv[i] << '\n';


    PAUSE
}