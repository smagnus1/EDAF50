#include <ctime>  // time and localtime
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>


#include "date.h"



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
	if(day != daysPerMonth[month-1]) {
		day++;
	} else {
		if(month == 12) {
			year++;
			month = 1;
		} else {
			month++;
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

istream& operator>>(istream& is, Date &date) {

	string in;
	getline(is, in);
	replace(in.begin(), in.end(), ' ', '-');

	istringstream stringstream(in);
	stringstream >> date.day;
	stringstream >> date.month;
	stringstream >> date.year;

	if(date.getMonth() <= 0 || date.getMonth() > 12 || date.getDay() <= 0 || date.getDay() > Date::daysPerMonth[date.getMonth() - 1]) {
		is.setstate(ios_base::failbit);
	}

	return is;
}