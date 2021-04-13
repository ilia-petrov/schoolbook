#include "Schoolbook.cpp"

static void fail()
{
	std::string str;
	while (true)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
		}

		std::cin >> str;
		if (str == "clear")
		{
			return;
		}
	}
}

static void Interpreter(Schoolbook* book)
{
	std::string str;

	while (std::cin >> str)
	{
		if (str == "clear")
		{
			continue;
		}
		else if (str == "end")
		{
			return;
		}
		else if (str == "add")
		{
			std::string what;
			std::cin >> what;
			if (what == "student")
			{
				std::string f_name, s_name, l_name;
				std::cin >> f_name >> s_name >> l_name;
				book->push(f_name, s_name, l_name);
			}
			else if (what == "note")
			{
				int num, note;
				std::string sub;
				std::cin >> num >> sub >> note;

				int stud = book->find_number(num, 0);
				if (stud == book->students.size())
				{
					fail();
				}
				else
				{
					book->students[stud]->push(sub, note);
				}
			}
			else if (what == "termnote")
			{
				int num, note;
				std::string sub;
				std::cin >> num >> sub >> note;

				int stud = book->find_number(num, 0);
				if (stud == book->students.size())
				{
					fail();
				}
				else
				{
					book->students[stud]->push_term(sub, note);
				}
			}
			else
			{
				std::cout << what << " is not a command\n";
				fail();
			}
		}
		else if (str == "erase")
		{
			std::string what;
			std::cin >> what;
			if (what == "student")
			{
				std::string by;
				std::cin >> by;
				if (by == "name")
				{
					std::string which, name;
					std::cin >> which >> name;
					if (which == "first")
					{
						book->erase_name(name, 0);
					}
					else if (which == "second")
					{
						book->erase_name(name, 1);
					}
					else if (which == "last")
					{
						book->erase_name(name, 2);
					}
					else
					{
						std::cout << which << " is not a command\n";
						fail();
					}
				}
				else if (by == "number")
				{
					int num;
					std::cin >> num;
					book->erase_number(num);
				}
				else
				{
					std::cout << by << " is not a commmand\n";
					fail();
				}
			}
			else if (what == "note")
			{
				int num, note;
				std::string sub;
				std::cin >> num >> sub >> note;

				int where = book->find_number(num, false);
				if (where == book->students.size())
				{
					fail();
				}
				else
				{
					book->students[where]->erase_note(sub, note);
				}
			}
			else if (what == "termnote")
			{
				int num;
				std::string sub;
				std::cin >> num >> sub;

				int where = book->find_number(num, false);
				if (where == book->students.size())
				{
					fail();
				}
				else
				{
					book->students[where]->erase_term_note(sub);
				}
			}
			else if (what == "subject")
			{
				int num;
				std::string sub;
				std::cin >> num;

				int where = book->find_number(num, false);
				if (where == book->students.size())
				{
					fail();
				}
				else
				{
					std::cin >> sub;
					book->students[where]->erase_subject(sub);
				}
			}
			else
			{
				std::cout << what << " is not a commmand\n";
				fail();
			}
		}
		else if (str == "find")
		{
			std::string what;
			std::cin >> what;

			if (what == "number")
			{
				int num;
				std::cin >> num;
				int where = book->find_number(num, true);
			}
			else if (what == "name")
			{
				std::string which, name;
				std::cin >> which >> name;

				if (which == "first")
				{
					book->find_name(name, 0, true);
				}
				else if (which == "second")
				{
					book->find_name(name, 1, true);
				}
				else if (which == "third")
				{
					book->find_name(name, 2, true);
				}
				else
				{
					std::cout << which << " is not a command\n";
					fail();
				}
			}
			else
			{
				std::cout << what << " is not a command\n";
				fail();
			}
		}
		else if (str == "output")
		{
			book->output();
		}
		else if (str == "sort")
		{
			std::string by;
			std::cin >> by;

			if (by == "number")
			{
				book->sort_by_number();
			}
			else if (by == "name")
			{
				std::string which;
				std::cin >> which;

				if (which == "first")
				{
					book->sort_by_name(0);
				}
				else if (which == "second")
				{
					book->sort_by_name(1);
				}
				else if (which == "last")
				{
					book->sort_by_name(2);
				}
				else
				{
					std::cout << which << "is not a command\n";
					fail();
				}
			}
			else
			{
				std::cout << by << " is not a command\n";
				fail();
			}
		}
		else
		{
			std::cout << str << " is not a command\n";
			fail();
		}
	}
}
