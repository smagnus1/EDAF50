#include <ctime>  // time and localtime
#include "date.h"

#include <iomanip> 
#include <iostream>


using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if(day != daysPerMonth[month]-1) {
		day++;
	} else {
		if(month != 12) {
			month++;
		} else {
			month = 1;
			year++;
		}
		day = 1;
	}	
}

ostream& operator<<(ostream& out, const Date &date) {
	out << setw(4) << setfill('0') << date.getYear() << '-';
	out << setw(2) << setfill('0') << date.getMonth() << '-';
	out << setw(2) << setfill('0') << date.getDay(); 

	return out;
}

istream& operator>>(istream& in, const Date &date) {
	int year, month, day;
	char c1, c2;

	in >> year;
	in >> c1;
	in >> month;
	in >> c2;
	in >> day;
	
	date = Date(year, month, day);


	if(month <= 0 || month > 12 || day <= 0 || day > Date::daysPerMonth[month - 1]) {
		in.setstate(ios_base::failbit);
	}

	return in;


}