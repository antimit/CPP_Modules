#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
         return 0;
	}
	int i = 1;
    int j = 0;
    while(argv[i])
    {
        while(argv[i][j])
        {
            std::cout << (char)std::toupper( argv[i][j]);
            j++;
        }
        j= 0;
        i++;
    }

    return 0;
}