#include<iostream>
#include<string>

using namespace std;
void convertValues(string time, int& hour, int& minute);
int main(){
	setlocale(LC_ALL, "ru");

	string timeDeparture, timeArrival;
	cout << "Введите время отправления(HH:MM) :";
	//getline(cin, timeDeparture);
	cout << "Введите время прибытия(HH:MM) : ";
	//getline(cin, timeArrival);

	timeDeparture = "12:33";
	timeArrival = "15:40";
	int hourDeparture=0, minuteDeparture=0;
	int hourArrival =0, minuteArrival=0;
/*
 unsigned int i = 0,

	while (i < timeDeparture.length())
	{
		if (timeDeparture[i] <= '0' && timeDeparture[i] >= '9'&& timeDeparture[i] != ':')
			cout << "Ошибка!";

		if(timeDeparture[i]!=':')
		{
			switch(i)
			{
			 case 0:
				hourDeparture = 10 * ((int)timeDeparture[i] - (int)'0');
				break;
			 case 1:
				hourDeparture = hourDeparture + ((int)timeDeparture[i] - (int)'0');
				break;
			 case 3:
				minuteDeparture = 10* ((int)timeDeparture[i] - (int)'0');
				break;
			 case 4:
				minuteDeparture = minuteDeparture + ((int)timeDeparture[i] - (int)'0');
				break;
			}
		}
		else
		{
			i++;
			continue;
		}
	    i++;
	}

	//hours=h1+h2;
	//minutes=min1+min2;
	//cout << h<< " : "<<min<< endl;

	 */
	convertValues(timeDeparture, hourDeparture, minuteDeparture);
	convertValues(timeArrival, hourArrival, minuteArrival);

	int hoursResult;
	if(hourArrival<hourDeparture)
		hoursResult = abs(24 - hourDeparture)+hourArrival;
	else
		hoursResult=hourArrival-hourDeparture;
	cout << "Поездка составила " << hoursResult <<" ч."<< minuteDeparture << " мин \n";

	system("pause>1");
	return 0;
}

void convertValues(string time, int& hour, int& minute)
{
	unsigned int i = 0;

	while (i < time.length())
		{
			if (time[i] <= '0' && time[i] >= '9'&& time[i] != ':')
				cout << "Ошибка!";

			if(time[i]!=':')
			{
				switch(i)
				{
				 case 0:
					hour = 10 * ((int)time[i] - (int)'0');
					break;
				 case 1:
					hour = hour + ((int)time[i] - (int)'0');
					break;
				 case 3:
					minute = 10* ((int)time[i] - (int)'0');
					break;
				 case 4:
					minute = minute + ((int)time[i] - (int)'0');
					break;
				}
			}
			else
			{
				i++;
				continue;
			}
		    i++;
		}
	return;
}
