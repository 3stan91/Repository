#include<iostream>
#include<string>

using namespace std;
int main(){

	/*
	string s, word;

	cout << "vedite stroku\n";
	getline(cin, s);
	cout << "vedite slovo\n";
	getline(cin, word);
	int si = 0, wi = 0, count = 0, found=0;

	while (wi <= word.length())
	{
		while (si <= s.length())
		{
			if (s[si] == word[wi])
			{
				count++;
				si++;

				if (count == word.length())
					found++;
				break;
			}

			si++;
		}

		if (wi == word.length())
			wi = 0;
		else
			z

		cout << word[wi] << "   " << s[si] << endl;

	}
	*/
	string timeDeparture, timeArrival;
	cout << "Введите время отправления(HH:MM) :";
	//getline(cin, timeDeparture);
	cout << "Введите время прибытия(HH:MM) : ";
	//getline(cin, timeArrival);
	int i = 0,h=0;
	int hours=0, minutes=0;
	timeDeparture = "12:03";

	while (i < timeDeparture.length())
	{
		if (timeDeparture[i] <= '0' && timeDeparture[i] >= '9'&& timeDeparture[i] != ':')
			cout << "Ошибка!";

		while (timeDeparture[i] != ':')
		{
			if (i == 0)
			{
				h = h + 10 * ((int)timeDeparture[i] - (int)'0');
				cout << h << endl;
			}
			else if (i == 1)
			{
				h += (int)timeDeparture[i] - (int)'0';
				cout << h << endl;
			}
			i++;
		}
		i++;
	}
	//if()

	cout << "Поездка составила " << hours <<" ч."<< minutes << " мин";

	system("pause>1");
	return 0;
}
