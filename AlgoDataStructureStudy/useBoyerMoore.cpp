#include <iostream>
#include <string>
#include "StrComp.h"

using namespace std;

int main()
{
	std::string str = "TRUSTHARDTOOTHBRUSH";
	std::string word = "TOOTH";
	cout << "str : " << str << endl;
	cout << "word : " << word << endl;
	cout << word << "는 " << BoyerMoore(str, word) << "번 째 인덱스에 있습니다.\n";

}
/*
TRUSTHARDTOOTHBRUSH
         TOOTH

*/