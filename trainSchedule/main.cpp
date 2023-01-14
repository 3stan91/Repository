#include<iostream>
#include<string>

using namespace std;
void convertValues(string time, int& hour, int& minute);
bool isCheckedData(string time);

int main(){
	setlocale(LC_ALL, "ru");
	const int MIN60 = 60;
	string timeDeparture, timeArrival;
	cout << "Введите время отправления в формате (ЧЧ:MM)\n";
	getline(cin, timeDeparture);
	cout << "Введите время прибытия в формате (ЧЧ:MM)\n";
	getline(cin, timeArrival);

	int hourDeparture=0, minuteDeparture=0;
	int hourArrival =0, minuteArrival=0;

	if(isCheckedData(timeDeparture))
		convertValues(timeDeparture, hourDeparture, minuteDeparture);

	if(isCheckedData(timeArrival))
		convertValues(timeArrival, hourArrival, minuteArrival);

	int hoursTrip, minutesTrip;
	//int min = 60 - minuteDeparture;

	if((minuteArrival + MIN60 - minuteDeparture)>= MIN60)
		{
		   minutesTrip=(minuteArrival + MIN60 - minuteDeparture) % MIN60;
		}

	if(hourArrival == hourDeparture && minuteArrival == minuteDeparture)
	{
		hoursTrip = 24;
		minutesTrip = 0;
	}
	else if(hourArrival < hourDeparture)
		hoursTrip = abs(24 - hourDeparture) + hourArrival;
	else
		hoursTrip=hourArrival-hourDeparture;

	cout << "Поездка составила " << hoursTrip <<" часа "<< minutesTrip << " мин \n";
	return 0;
}

void convertValues(string time, int& hour, int& minute)
{
	unsigned int i = 0;

	while (i < time.length())
		{
			//if (time[i] <= '0' && time[i] >= '9'&& time[i] != ':')
				//cout << "Ошибка!";

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

bool IsCheckedData(string t)
{
	unsigned int i=0;
	bool error = false;
	while (i < t.length())
	{
		if (t[i] <= '0' && t[i] >= '9' && t[i] != ':')
		{
			cout << "Ошибка! Вы ввели неверный формат времени.\n";
			error=true;
		}
		else
			i++;
	}
	if(!error)
		return true;
	else
		return false;
}
