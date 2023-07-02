#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
//#include "IntQueue.h"
#include "charStack.h"
#include "charQueue.h"
#include "doubleStack.h"
/*
* 1.중위 ?�기법에????글?�씩 ?�어?�인??
* 2. ?�어?�인 글?��? ?�산?�이�?
*	?�쪽 괄호?�면 그냥 추�?
*	?�른�?괄호?�면 ?�택?�서 괄호�?만날 ?�까지 ?�나??꺼내 ?�에 ???
*	?�쪽 괄호?� 만나�?????버린??
*	?�머지 ?�칙 ?�산?� �??�산?��? ?�택?�서 꺼낸 ?�산?�보???�선?�위가 ?�거??같�? ?�안?�는 계속 ?�로 ??��준?? 그리�??�신???�택??추�??�다.
*	?�어?�인 글?��? ?�연?�자?�면 ?�에 ?�는??
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

	string num = "";//2?�리???�상???��? ?�한 string
	

	for (int i = 0; i < newStr.size(); i++)
	{
		//?�산?�인지 ?�닌지 구분?�기
		if (isOperator(newStr[i]) == 1)
		{
			//?�산?�면 ?�선?�위 ?�져???�기
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