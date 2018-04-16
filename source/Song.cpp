/*
* Filename:		Song.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/


#include "Song.h"
#include <iostream>

//------------------------------------------------------------------------------
//	A constructor that copies from another song.
//------------------------------------------------------------------------------
Song::Song(const Song &song)
{
	m_title = song.m_title;
	m_artist = song.m_artist;
	m_time = song.m_time;
}

//------------------------------------------------------------------------------
//	A constructor that sets the member-variables.
//------------------------------------------------------------------------------
Song::Song(std::string title, std::string artist, Time time)
{
	m_title = title;
	m_artist = artist;
	m_time = time;
}

//------------------------------------------------------------------------------
//	An overloaded operator. Writes the song in the correct format to the stream.
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &stream, const Song &song)
{
	stream << song.getTitle() << '|' << song.getArtist() << '|';
	stream << song.getTime();
	return stream;
}

//------------------------------------------------------------------------------
//	An overloaded operator. Reads a song from stream.
//------------------------------------------------------------------------------
std::istream &operator>>(std::istream &stream, Song &song)
{
	std::string str;
	std::getline(stream, str, '|');
	song.setTitle(str);
	std::getline(stream, str, '|');
	song.setArtist(str);
	Time time;
	stream >> time;
	song.setTime(time);
	return stream;
}