#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int index = 1; argv[index]; index++)
        {
            for (int i = 0; argv[index][i]; i++)
                std::cout << (char)std::toupper(argv[index][i]);
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return 0;
}
