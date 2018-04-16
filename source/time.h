/*
* Filename:		time.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#pragma once

#include <iostream>
#include <string>


//------------------------------------------------------------------------------
//	A class that represents a time in the format of hours, minutes and seconds.
//------------------------------------------------------------------------------
class Time
{
private:

	int m_hours;
	int m_minutes;
	int m_seconds;

public:

	// Constructors.
	Time() : m_hours(0), m_minutes(0), m_seconds() {};
	Time(int hours, int minutes, int seconds);
	Time(const Time &time);

	// Getters.
	int getHour() const { return m_hours; };
	int getMinute() const { return m_minutes; };
	int getSecond() const { return m_seconds; };
	
	// Setters.
	void setHour(int hour) { m_hours = hour; };
	void setMinute(int minute) { m_minutes = minute; };
	void setSecond(int second) { m_seconds = second; };

	std::string toString();
	Time operator+(const Time &time) const;
	bool operator<(const Time &time) const;
	bool operator>(const Time &time) const;
	bool operator==(const Time &time) const;

};

int toSeconds(const Time &time);
Time fromSeconds(const int &seconds);
std::ostream &operator<<(std::ostream &stream, const Time &time);
std::istream &operator>>(std::istream &stream, Time &time);