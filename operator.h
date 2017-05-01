#pragma once
#include <string>

class Operators {
public:
	static std::string addition(std::string, std::string);	
	template <class T2>
	static std::string addition(std::string , T2);
	template <class T1>
	static std::string addition(T1, std::string);
	
	
	static int addition(int, int);

	template<class T1, class T2>
	static double addition(T1, T2);
};
