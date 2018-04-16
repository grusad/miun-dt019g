/*
* Filename:		Time.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/


#include "time.h"

//------------------------------------------------------------------------------
//	A constructor that sets the member-variables.
//------------------------------------------------------------------------------
Time::Time(int hours, int minutes, int seconds)
{
	m_hours = hours;
	m_minutes = minutes;
	m_seconds = seconds;
}

//------------------------------------------------------------------------------
//	A construcor that sets the member-variables by another Time-object.
//------------------------------------------------------------------------------
Time::Time(const Time &time)
{
	m_hours = time.getHour();
	m_minutes = time.getMinute();
	m_seconds = time.getSecond();
}

//------------------------------------------------------------------------------
//	An overloaded operator. Adds two time-object together.
//------------------------------------------------------------------------------
Time Time::operator+(const Time &time) const
{
	Time sum;

	sum.m_seconds = m_seconds + time.m_seconds;
	sum.m_minutes = m_minutes + time.m_minutes + sum.m_seconds / 60;
	sum.m_seconds %= 60;
	sum.m_hours = m_hours + time.m_hours + sum.m_minutes / 60;
	sum.m_minutes %= 60;

	return sum;

}

//------------------------------------------------------------------------------
//	An overloaded operator. Compares two Time-object by their length.
//------------------------------------------------------------------------------
bool Time::operator<(const Time &time) const
{
	return toSeconds(*this) < toSeconds(time);
}

//------------------------------------------------------------------------------
//	An overloaded operator. Compares two Time-object by their length.
//------------------------------------------------------------------------------
bool Time::operator>(const Time &time) const
{
	return toSeconds(*this) > toSeconds(time);
}

//------------------------------------------------------------------------------
//	An overloaded operator. Tests if two Time-objects are equal in length.
//------------------------------------------------------------------------------
bool Time::operator==(const Time &time) const
{
	return m_hours == time.m_hours && m_minutes == time.m_minutes && m_seconds == time.m_seconds;
}

//------------------------------------------------------------------------------
//	Returns a Time-object as a string with a specific format.
//------------------------------------------------------------------------------
std::string Time::toString()
{
	std::string str;
	if (m_hours > 0) str = std::to_string(m_hours) + ":";
	str += std::to_string(m_minutes) + ":";
	if (m_seconds < 10) str += "0";
	str += std::to_string(m_seconds);
	return str;
}

//------------------------------------------------------------------------------
//	Convers a Time-object to seconds.
//------------------------------------------------------------------------------
int toSeconds(const Time &time) 
{
	return (time.getHour() * 60 * 60) + (time.getMinute() * 60) + time.getSecond();
}

//------------------------------------------------------------------------------
//	Converts from seconds to a Time-object.
//------------------------------------------------------------------------------
Time fromSeconds(const int &sec)
{

	int seconds = sec;

	Time time;

	int minutes = seconds / 60;
	seconds %= 60;
	int hours = minutes / 60;
	minutes %= 60;

	time.setHour(hours);
	time.setMinute(minutes);
	time.setSecond(seconds);
	
	return time;
}

//------------------------------------------------------------------------------
//	Overloaded operator. Writes the Time-object to stream.
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &stream, const Time &time)
{
	int seconds = toSeconds(time);
	stream << seconds;
	return stream;
}

//------------------------------------------------------------------------------
//	Overloaded operator. Reads a Time-object from stream.
//------------------------------------------------------------------------------
std::istream &operator>>(std::istream &stream, Time &time)
{
	int seconds = 0;
	stream >> seconds;
	stream.get();

	Time t = fromSeconds(seconds);

	time.setHour(t.getHour());
	time.setMinute(t.getMinute());
	time.setSecond(t.getSecond());

	return stream;

}
