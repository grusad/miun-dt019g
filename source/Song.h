/*
* Filename:		Song.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/


#pragma once

#include "time.h"
#include <string>

//------------------------------------------------------------------------------
//	A class that represents a Song
//------------------------------------------------------------------------------
class Song
{

private:

	std::string m_title;
	std::string m_artist;
	Time m_time;

public:
	
	// Constructors.
	Song() : m_title(""), m_artist(""), m_time(0, 0, 0) {};
	Song(std::string title, std::string artist, Time time);
	Song(const Song &song);

	// Getters.
	std::string getTitle() const { return m_title; };
	std::string getArtist() const { return m_artist; };
	Time getTime() const { return m_time; };

	// Setters.
	void setTitle(const std::string title) { m_title = title; };
	void setArtist(const std::string artist) { m_artist = artist; };
	void setTime(const Time time) { m_time = time; };

};

/*
	A function that overloads the "<<"-operator that writes a Song-object to a stream.
*/
std::ostream &operator<<(std::ostream &stream, const Song &song);

/*
	A function that overloads the "<<"-operator that writes a Song-object to a stream.
*/
std::istream &operator>>(std::istream &stream, Song &song);
