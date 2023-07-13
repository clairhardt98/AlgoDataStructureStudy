#include "StrComp.h"

int main()
{
	std::string s = "BANANAAPPLEKIWISTRAWBERRY";
	std::string word = "KIWI";
	int idx = KMP(s, word);
	std::cout << std::endl;
	std::cout << "in " << idx << std::endl;
}