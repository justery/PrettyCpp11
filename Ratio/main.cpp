#include <ratio>
#include <iostream>

#pragma warning(disable:4101) // which is 'line:19, 20, 21, tf, os, sum is not used'.

int main()
{
	using ThreeFifths = std::ratio<3, 5>;
	using OneSecond = std::ratio<1, 2>;
	bool usingTypeRatherThanObject = true;
	if (usingTypeRatherThanObject)
	{
		using sum = std::ratio_add<ThreeFifths, OneSecond>;
		std::cout << sum::num << "/" << sum::den << std::endl;
	}
	else
	{
		ThreeFifths tf;
		OneSecond os;
		std::ratio_add<decltype(tf), decltype(os)> sum;
		std::cout << decltype(sum)::num << "/" << decltype(sum)::den << std::endl;
	}
	
	return 0;
}
