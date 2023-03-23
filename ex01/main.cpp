#include "PhoneBook.hpp"

int main (void)
{
    PhoneBook PhoneB;
    std::string tmp;
	
    do{
        std::cout << FGRN("Enter Command : ");
        getline(std::cin ,tmp);
        if (std::cin.eof())
        {
            std::cout << FCYN("\n******** Thank you for using our software! ********\n\n");
            return (1);
        }

		if (tmp == "ADD")
			PhoneB.ADD();
        else if (tmp == "SEARCH")
			PhoneB.SEARCH();
        else if (tmp == "EXIT")
            std::cout << FCYN("\n******** Thank you for using our software! ********\n\n");
        else if (!tmp.empty())
            std::cout << FRED("*****      Error    *****\nhint :  use ADD or SEARCH or EXIT\n");
    }
	while(tmp != "EXIT");
			
}