// object.cpp

#include <typeinfo>
#include "object.h"

const char* Object::ToString()
{
	//return "Object";
	return typeid(*this).name();
}
