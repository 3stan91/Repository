#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
bool convertStrToInt(string, int&, int&);

/*void IsCheckedData(string time)
 {
 unsigned int i=0;
 bool error = false;

 while (!error && i < time.length())
 {
 if(time[0]>2 || (time[i]==':' && time[i+1]>5) || (time[i] <= '0' && time[i] >= '9') )
 {
 cout << "Ошибка! Вы ввели неверный формат времени.\n";
 error=true;
 }
 else if(time[1]==':')
 time='0'+time;
 else
 i++;
 }
 }
 */

int main() {
	setlocale(LC_ALL, "ru");
	const int MIN60 = 60;
	string timeDeparture, timeArrival;
	cout << "Введите время отправления в формате (ЧЧ:MM)\n";
//	getline(cin, timeDeparture);
	cout << "Введите время прибытия в формате (ЧЧ:MM)\n";
//	getline(cin, timeArrival);

	timeDeparture = "23:25";
	timeArrival = "14:55";
	int hourDeparture = 0, minuteDeparture = 0;
	int hourArrival = 0, minuteArrival = 0;

	if (!convertStrToInt(timeDeparture, hourDeparture, minuteDeparture))
		return -1;

//	isCheckedData(timeArrival);
	if (!convertStrToInt(timeArrival, hourArrival, minuteArrival))
		return -1;

	int hoursTrip, minutesTrip;
	int min = 60 - minuteDeparture;

	if (minuteArrival >= minuteDeparture)
		minutesTrip = minuteArrival - minuteDeparture;
	else if (minuteArrival < minuteDeparture) {
		hourArrival -= 1;
		minutesTrip = minuteArrival + min;
	}
	//else		minutesTrip = min + minuteArrival;

	if (hourArrival == hourDeparture && minuteArrival == minuteDeparture) {
		hoursTrip = 24;
		minutesTrip = 0;
	} else if (hourArrival < hourDeparture)
		hoursTrip = abs(24 - hourDeparture) + hourArrival;
	else
		hoursTrip = hourArrival - hourDeparture - 1;

	cout << "Поездка составила " << hoursTrip << " часа " << minutesTrip
			<< " мин \n";
	return 0;
}

bool convertStrToInt(string time, int &hour, int &minute) {
	unsigned int i = 0;
	bool error = false;

	while (i < time.length()) {
		if ((time[0] >= '2' && time[1] >= '4')
				|| (time[i] == ':' && time[i + 1] > '5')
				|| (time[i] <= '0' && time[i] >= '9')) {
			cout << "Ошибка! Вы ввели неверный формат времени.\n";
			error = true;
			break;
		} else if (time[1] == ':')
			time = '0' + time;

		if (time[i] != ':') {
			switch (i) {
			case 0:
				hour = 10 * ((int) time[i] - (int) '0');
				break;
			case 1:
				hour = hour + ((int) time[i] - (int) '0');
				break;
			case 3:
				minute = 10 * ((int) time[i] - (int) '0');
				break;
			case 4:
				minute = minute + ((int) time[i] - (int) '0');
				break;
			}
		} else {
			i++;
			continue;
		}
		i++;
	}
	if (!error)
		return true;
	else
		return false;
}

