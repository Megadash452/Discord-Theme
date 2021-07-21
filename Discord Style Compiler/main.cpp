#include <iostream>
#include <fstream>
#include <string>
using std::string;

#if _DEBUG
#   define PAUSE system("pause");
#   define println(x) std::cout<<x<<std::endl
#else
#   define println(x)
#endif

#define END return 0;
#define END_ERR return 1;

// args: -i <source file/dir> [first default]
//       -o <output file/dir> [second default] (optional)
//       alternatively:
//          -o <filetype> (css, scss, sass)
//       e.g.:
//          APP -i fol/this.sass -o css
//          -i, -o (alt) - output file will have same name/dir as source, but different extension
// 
//       -f <...> optional flags
//       flag definitions:
//          compress - put everything on 1 line, with minimal whitespace (not sass)
//          
// 
// auto detect language (css, scss, sass)
// make list of discord css classes and ids

bool read_file(const char* path, string& output)
{
    std::ifstream file{ path, std::ios::in };
    if (file.is_open())
    {
        string line;

        println("Reading file: " << path);
        while (std::getline(file, line))
            output += (line + '\n');
        println("Done reading file: " << path);
        file.close();

        return true;
    }
    else
    {
        println("Error opening file: " << path);
        return false;
    }
}

int main(int argc, const char** argv)
{
    for (int i = 0; i < argc; i++)
        std::cout << i << ": " << argv[i] << '\n';

    string input_content;
    string output_content;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i] == string{ "-i" })
        {
            read_file(argv[i + 1], input_content);
            i++;
        }
        else if (argv[i] == string{ "-o" })
        {
            read_file(argv[i + 1], output_content);
            i++;
        }
        else if (argv[i] == string{ "-f" })
        {

        }
    }

    PAUSE
}