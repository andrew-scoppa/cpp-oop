// multiple.cpp

#include <stdexcept>
#include "trace.h"

void f1()
{
	Trace("Throwing int");
	int n = 10;
	throw n;
}
void f2()
{
	Trace("Throwing const char *");
	const char *t = "I am a null terminated array of char.";
	throw t;
}
void f3()
{
	Trace("Throwing logic_error");
	logic_error l("I am a stdexcept logic error.");
	throw l;
}
using pvf = void (*)();

int main()
{
	pvf fnarray[] = {f1, f2, f3,};
	for (auto fn : fnarray)
	{
		try
		{
			fn();
		}
		catch (logic_error &l){
			Trace("logic_error caught: ", l.what());
		}
		catch (int &n)
		{
			Trace("int caught: ", n);
		}
		catch (const char *str)
		{
			Trace("char * caught: ", str);
		}
		catch (...)
		{
			Trace("Unexpected exception");
		}
	}

	return 0;
}
