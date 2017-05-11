#include <RuntimeLib\Type\LanguageType\LanguageType.h>
#include <string>

using namespace std;

string LanguageType::_getType() {
	return "undefined";
}

LanguageType *ToLanguageType(Type * argu)
{
	auto _argu = dynamic_cast<LanguageType *>(argu);
	return _argu;
}


