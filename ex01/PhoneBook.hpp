#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include <string>
/* FOREGROUND */
# define RST "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

# define FRED(x) KRED x RST
# define FGRN(x) KGRN x RST
# define FYEL(x) KYEL x RST
# define FBLU(x) KBLU x RST
# define FMAG(x) KMAG x RST
# define FCYN(x) KCYN x RST
# define FWHT(x) KWHT x RST

class Contact
{
  private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
	std::string tmp;
	char *c_str;

  public:
	void GetContactInfo(std::string message);
	bool StringIsNotDigit(std::string str);
	void ShowContactInfo(std::string message, bool Table);
};

class PhoneBook
{
  private:
	int index;
	bool lock;
	Contact contact[8];
	std::string tmp;
	int len;
	std::string UserIndex;

  public:
	PhoneBook();
	void ADD();
	void SEARCH();
};

#endif