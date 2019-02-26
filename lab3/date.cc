#include <ctime>  // time and localtime
#include "date.h"

#include <iomanip> 
#include <iostream>

#include <istream>
#include <ostream>


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



//SE NIKLAS METOD
istream& operator>>(istream& is, Date &date) {
	int year, month, day;
	char c1, c2;

	is >> year;
	is >> c1;
	is >> month;
	is >> c2;
	is >> day;
	
	//...declaration of ‘Date date’ shadows a parameter if declared as date
	Date date1 = Date(year, month, day);


	if(date1.getMonth() <= 0 || date1.getMonth() > 12 || date1.getDay() <= 0 || 
		date1.getDay() > Date::daysPerMonth[date1.getMonth() - 1]) {
		is.setstate(ios_base::failbit);
	}

	return is;
}