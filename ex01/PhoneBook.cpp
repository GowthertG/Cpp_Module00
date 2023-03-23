#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	len = 0;
	lock = false;
}

void PhoneBook::ADD()
{
	contact[index % 8].GetContactInfo("FIRST NAME");
	contact[index % 8].GetContactInfo("LAST NAME");
	contact[index % 8].GetContactInfo("NICKNAME");
	contact[index % 8].GetContactInfo("PHONE NUMBER");
	contact[index % 8].GetContactInfo("DARKEST SECRET");
	std::cout << FMAG("\n\nContact has been added successfully\n\n");
	index++;
}

void PhoneBook::SEARCH()
{
	if (index < 8)
		len = index;
	else
		len = 8;
	if (!len)
	{
		std::cout << FRED("Contact Empty !\n");
		return ;
	}
	std::cout << "│  ";
	std::cout << FYEL("INDEX   ");
	std::cout << "│";
	std::cout << FYEL("FIRST NAME");
	std::cout << "│";
	std::cout << FYEL("LAST  NAME");
	std::cout << "│";
	std::cout << FYEL("NICK  NAME");
	std::cout << "│\n";
	for (int i = 0; i < len; i++)
	{
		std::cout << "│    ";
		std::cout << i;
		std::cout << "     │";
		contact[i].ShowContactInfo("FIRST NAME", true);
		std::cout << "│";
		contact[i].ShowContactInfo("LAST NAME", true);
		std::cout << "│";
		contact[i].ShowContactInfo("NICKNAME", true);
		std::cout << "│\n";
	}
	do
	{
		if (std::cin.eof())
		{
			std::cout << FCYN("\n******** Thank you for using our software! ********\n\n");
			exit(1);
		}
		std::cout << FCYN("Please Enter Contact Index : ");
		getline(std::cin, UserIndex);
		if (contact->StringIsNotDigit(UserIndex) || UserIndex.length() != 1
			|| atoi(UserIndex.c_str()) >= len)
		{
			(std::cout << KRED "index must be under " << len << " and decimal\n" RST,
				lock = true);
			continue ;
		}
		lock = false;
	} while ((UserIndex.empty() || lock) && len);
	std::cout << "\n\n\n";
	std::cout << FYEL("FIRST NAME : ");
	contact[atoi(UserIndex.c_str())].ShowContactInfo("FIRST NAME", false);
	std::cout << std::endl;
	std::cout << FYEL("LAST NAME : ");
	contact[atoi(UserIndex.c_str())].ShowContactInfo("LAST NAME", false);
	std::cout << std::endl;
	std::cout << FYEL("NICKNAME : ");
	contact[atoi(UserIndex.c_str())].ShowContactInfo("NICKNAME", false);
	std::cout << std::endl;
	std::cout << FYEL("PHONE NUMBER : ");
	contact[atoi(UserIndex.c_str())].ShowContactInfo("PHONE NUMBER", false);
	std::cout << std::endl;
	std::cout << FYEL("DARKEST SECRET : ");
	contact[atoi(UserIndex.c_str())].ShowContactInfo("DARKEST SECRET", false);
	std::cout << "\n\n\n";
	lock = false;
}

bool Contact::StringIsNotDigit(std::string str)
{
	c_str = (char *)str.c_str();
	for (int i = 0; c_str[i]; i++)
	{
		if (c_str[i] < '0' || c_str[i] > '9')
			return (true);
	}
	return (false);
}

void Contact::GetContactInfo(std::string message)
{
	do
	{
		if (std::cin.eof())
		{
			std::cout << FCYN("\n******** Thank you for using our software! ********\n\n");
			exit(1);
		}
		std::cout << "\n\x1B[34mENTER " << (message.c_str()) << " : \x1B[0m";
		getline(std::cin, tmp);
	} while (tmp.empty());
	if (message == "FIRST NAME")
		FirstName = tmp;
	else if (message == "LAST NAME")
		LastName = tmp;
	else if (message == "NICKNAME")
		NickName = tmp;
	else if (message == "PHONE NUMBER")
	{
		if (StringIsNotDigit(tmp))
		{
			std::cout << FRED("*****the phone number must be in digits format *****\n");
			GetContactInfo("PHONE NUMBER");
		}
		if (tmp.length() > 15)
		{
			std::cout << FRED("***** this number is too long please enter number under 15 numbers*****\n");
			GetContactInfo("PHONE NUMBER");
		}
		PhoneNumber = tmp;
	}
	else if (message == "DARKEST SECRET")
	{
		DarkestSecret = tmp;
	}
}

void Contact::ShowContactInfo(std::string message, bool Table)
{
	if (message == "FIRST NAME")
	{
		if (Table)
		{
			for (int i = 0; FirstName.length() + i < 9; i++)
				std::cout << " ";
			if (FirstName.length() <= 9)
			{
				std::cout << " ";
				std::cout << FirstName;
			}
			else
			{
				std::cout.write(FirstName.c_str(), 9);
				std::cout << ".";
			}
		}
		else
			std::cout << FirstName;
	}
	else if (message == "LAST NAME")
	{
		if (Table)
		{
			for (int i = 0; LastName.length() + i < 9; i++)
				std::cout << " ";
			if (LastName.length() <= 9)
			{
				std::cout << " ";
				std::cout << LastName; 
			}
			else
			{
				std::cout.write(LastName.c_str(), 9);
				std::cout << ".";
			}
		}
		else
			std::cout << LastName;
	}
	else if (message == "NICKNAME")
	{
		if (Table)
		{
			for (int i = 0; NickName.length() + i < 9; i++)
				std::cout << " ";
			if (NickName.length() <= 9)
			{
				std::cout << " ";
				std::cout << NickName;
			}
			else
			{
				std::cout.write(NickName.c_str(), 9);
				std::cout << ".";
			}
		}
		else
			std::cout << NickName;
	}
	else if (message == "PHONE NUMBER")
		std::cout << PhoneNumber;
	else if (message == "DARKEST SECRET")
		std::cout << DarkestSecret;
}
