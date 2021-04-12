#include "Interpreter.cpp"

int main()
{

    Schoolbook* book = new Schoolbook;

	Interpreter(book);

    delete book;

	return 0;
}
