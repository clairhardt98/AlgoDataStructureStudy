#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
//#include "IntQueue.h"
#include "charStack.h"
#include "charQueue.h"
#include "doubleStack.h"
/*
* 1.ì¤‘ìœ„ ?œê¸°ë²•ì—????ê¸€?ì”© ?½ì–´?¤ì¸??
* 2. ?½ì–´?¤ì¸ ê¸€?ê? ?°ì‚°?ì´ë©?
*	?¼ìª½ ê´„í˜¸?´ë©´ ê·¸ëƒ¥ ì¶”ê?
*	?¤ë¥¸ìª?ê´„í˜¸?´ë©´ ?¤íƒ?ì„œ ê´„í˜¸ë¥?ë§Œë‚  ?Œê¹Œì§€ ?˜ë‚˜??êº¼ë‚´ ?ì— ???
*	?¼ìª½ ê´„í˜¸?€ ë§Œë‚˜ë©?????ë²„ë¦°??
*	?˜ë¨¸ì§€ ?¬ì¹™ ?°ì‚°?€ ê·??°ì‚°?ê? ?¤íƒ?ì„œ êº¼ë‚¸ ?°ì‚°?ë³´???°ì„ ?œìœ„ê°€ ?’ê±°??ê°™ì? ?™ì•ˆ?ëŠ” ê³„ì† ?ë¡œ ??²¨ì¤€?? ê·¸ë¦¬ê³??ì‹ ???¤íƒ??ì¶”ê??œë‹¤.
*	?½ì–´?¤ì¸ ê¸€?ê? ?¼ì—°?°ì?´ë©´ ?ì— ?£ëŠ”??
*/

std::string getNewStr(char* str);
int getPriority(char& i);
int isOperator(char& i);
int main()
{
	using namespace std;

	ifstream f;
	f.open("calc.txt");
	char str[100];
	f.getline(str,strlen(str) + 1);
	std::cout << str << endl;
	string newStr = getNewStr(str);
	cout << newStr << endl;
	charStack operatorStk;
	doubleStack operandStk;
	charQueue que;
	Initialize(&operatorStk, newStr.size());
	Initialize(&operandStk, newStr.size());
	Initialize(&que, 100);

	string num = "";//2?ë¦¬???´ìƒ???˜ë? ?„í•œ string
	

	for (int i = 0; i < newStr.size(); i++)
	{
		//?°ì‚°?ì¸ì§€ ?„ë‹Œì§€ êµ¬ë¶„?˜ê¸°
		if (isOperator(newStr[i]) == 1)
		{
			//?°ì‚°?ë©´ ?°ì„ ?œìœ„ ?°ì ¸???£ê¸°
			switch (getPriority(newStr[i]))
			{
			case 0:// (
			{
				Push(&operatorStk, newStr[i]);
				break;
			}
			case 1:
			{
				char temp = 0;
				
				while (!IsEmpty(&operatorStk))
				{
					Peek(&operatorStk, &temp);
					if (getPriority(temp) >= getPriority(newStr[i]))
					{
						Pop(&operatorStk, &temp);
						Enque(&que, temp);
					}
					else
						break;
				}
				Push(&operatorStk, newStr[i]);
			}
			break;
			case 2:
			{
				char temp;
				
				while (!IsEmpty(&operatorStk))
				{
					Peek(&operatorStk, &temp);
					if (getPriority(temp) >= getPriority(newStr[i]))
					{
						Pop(&operatorStk, &temp);
						Enque(&que, newStr[i]);
					}
					else
						break;
				}
				Push(&operatorStk, newStr[i]);
			}
			break;
			case 3:// )
			{
				char temp = 0;
				while (!IsEmpty(&operatorStk))
				{
					Peek(&operatorStk, &temp);
					if (temp == '(')
					{
						Pop(&operatorStk, &temp);
						break;
					}
					else
					{
						Pop(&operatorStk, &temp);
						Enque(&que, temp);
					}
					
					
				}
				break;
			}
			}
		}
		
		else
		{
			Enque(&que, newStr[i]);
			if (i == newStr.size() - 1 || isOperator(newStr[i + 1]) == 1)
				Enque(&que, ' ');
		}
	}
	while (!IsEmpty(&operatorStk))
	{
		char temp;
		Pop(&operatorStk, &temp);
		Enque(&que, temp);
		//Enque(&que, ' ');

	}
	Print(&que);

	char temp;
	int minus = 1;
	while (!IsEmpty(&que))
	{
		
		//Print(&que);
		Deque(&que, &temp);
		//cout << "temp : " << temp<<endl;
		if (isOperator(temp) == -1)
			minus = -1;
		else if (isOperator(temp) == 0 && temp !=' ')
		{
			num += temp;
			//cout << num << endl;
		}
		else if(temp == ' ')
		{
			cout << "pushing " << minus * stod(num) << " to operandStk" << endl;
			Push(&operandStk, minus * stod(num));
			num = "";
			if (minus == -1)
				minus = 1;
		}
		else
		{
			cout << " met operator " << temp << endl;
			double operand1;
			Pop(&operandStk, &operand1);
			cout << " poped " << operand1 << endl;
			double operand2;
			Pop(&operandStk, &operand2);
			cout << " poped " << operand2 << endl;
			double op;
			switch (temp)
			{
			case '*' :
				op = operand2 * operand1;
				cout << "pushing " << op << " to operandStk" << endl;
				Push(&operandStk, op);
				break;
			case '/':
				op = operand2 / operand1;
				cout << "pushing " << op << " to operandStk" << endl;
				Push(&operandStk, op);
				break;
			case '+':
				op = operand2 + operand1;
				cout << "pushing " << op << " to operandStk" << endl;
				Push(&operandStk, op);
				break;
			case '-':
				op = operand2 - operand1;
				cout << "pushing " << op << " to operandStk" << endl;
				Push(&operandStk, op);
				break;
			}
		}
	}
	double res;
	//Print(&operandStk);
	Peek(&operandStk, &res);
	std::cout <<"answer: "<< res;
	f.close();
}
std::string getNewStr(char* str)
{
	std::string newStr = "";
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-')
		{
			if (i == 0)
			{
				newStr += "~";
				i++;
			}
			if (str[i - 1] == '(' ) newStr += "~";
			else
				newStr += str[i];
		}
		else
			newStr += str[i];
	}
	return newStr;
}

int getPriority(char& i)
{
	if (i == '(')
		return 0;
	else if (i == '+' || i == '-')
		return 1;
	else if (i == '*' || i == '/')
		return 2;
	else
		return 3;
}

int isOperator(char& i)
{
	if (i == '(' || i == ')' || i == '+' || i == '-' || i == '*' || i == '/')
		return 1;
	else if (i == '~')
		return -1;
	else return 0;
}