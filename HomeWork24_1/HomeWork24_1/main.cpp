#include <iostream>

using namespace std;

class Time
{
public:
	Time() = default;
	Time(int hours, int minutes, int seconds);
	~Time();
	void setTime();
	void display();
	Time operator+ (Time &t);
	Time operator- (Time &t);
	int count();
	bool operator> (Time &t);
	bool operator<= (Time &t);
	bool operator== (Time &t);
	void convert();

private:
	int hours, minutes, seconds;
	int maxHours = 24, maxMinutes = 60, maxSeconds = 60;
	int minHours = 0, minMinutes = 0, minSeconds = 0;
};

int Time::count(){
	return seconds + minutes * 60 + hours + 3600;
}

Time Time::operator+(Time &t){
	Time x;
	if ((seconds + t.seconds) > maxSeconds)
	{
		x.minutes = (minutes + t.minutes + 1) % maxMinutes;
	}
	else
	{
		x.minutes = (minutes + t.minutes) % maxMinutes;;
	}

	if ((minutes + t.minutes) > maxMinutes)
	{
		x.hours = (hours + t.hours + 1) % maxHours;
	}
	else
	{
		x.hours = (hours + t.hours) % maxHours;
	}

	x.seconds = (seconds + t.seconds) % maxHours;

	return x;
}

Time Time::operator-(Time &t){
	seconds = seconds - t.seconds;
	if (seconds < minSeconds)
	{
		seconds = maxSeconds + seconds; minutes--;
	}
	if (minutes < minMinutes)
	{
		minutes = maxMinutes + minutes; hours--;
	}
	if (hours < minHours) hours = maxHours + hours;

	minutes = minutes - t.minutes;
	if (minutes < minMinutes)
	{
		minutes = maxMinutes + minutes; hours--;
	}
	if (hours < minHours) hours = maxHours + hours;

	hours = hours - t.hours;
	if (hours < 0) hours = 24 + hours;

	return *this;
}

bool Time::operator>(Time &t){
	if (count() > t.count())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator<= (Time &t){
	if (count() <= t.count())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator== (Time &t){
	if (count() == t.count())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Time::setTime(){
	cout << "\nEnter hours : ";
	cin >> hours;
	cout << "Enter minutes : ";
	cin >> minutes;
	cout << "Enter seconds : ";
	cin >> seconds;
}

void Time::display(){
	cout << hours << "h:" << minutes << "m:" << seconds << "s" << endl;
}

Time::Time(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

void Time::convert(){
	cout << hours << "h:" << minutes << "m:" << seconds << "s" << " = ";
	if (hours >= 0 && hours < 12)
	{
		cout << hours << "h:" << minutes << "m:" << seconds << "s" << " am" << endl;
	}
	else
	{
		cout << hours - 12 << "h:" << minutes << "m:" << seconds << "s" << " pm" << endl;
	}
}

Time::~Time()
{
}

void main(){
	Time a(23, 50, 30), b(5, 3, 35), c;
	a.display();
	b.display();
	cout << endl;

	c = a + b;
	c.display();
	cout << endl;

	c = a - b;
	c.display();
	cout << endl;

	cout << (a > b) << endl;
	cout << (a <= b) << endl;
	cout << (a == b) << endl << endl;

	a.convert();
	cout << endl;
	b.convert();
	cout << endl;
}