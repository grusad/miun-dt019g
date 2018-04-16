/*
* Filename:		Album.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#include "Album.h"

//------------------------------------------------------------------------------
//	Get the total time of all songs.
//------------------------------------------------------------------------------
Time Album::getTotalTime() const
{
	Time time;

	for (auto &song : m_songs)
	{
		time = time + song.getTime();
	}
	
	return time;
}

//------------------------------------------------------------------------------
//	Overloaded operator. Compares the total length of the two albums.
//------------------------------------------------------------------------------
bool Album::operator<(const Album &album) const
{
	return getTotalTime() < album.getTotalTime();
}

//------------------------------------------------------------------------------
//	Overloaded operator. Compares the two albums if their names are equal.
//------------------------------------------------------------------------------
bool Album::operator==(const Album &album) const
{
	return m_name == album.getName();
}

//------------------------------------------------------------------------------
//	Overloaded operator. Writes information about the album and all songs to the stream.
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &stream, const Album &album)
{

	stream << album.getName() << std::endl;
	stream << album.getCount() << std::endl;

	for (int i = 0; i < album.getCount(); i++)
	{
		stream << album.getSong(i) << std::endl;
	}

	return stream;
}

//------------------------------------------------------------------------------
// Overloaded operator. Reads information about the album and all the songs from the stream.
//------------------------------------------------------------------------------
std::istream &operator>>(std::istream &stream, Album &album)
{

	std::string str;
	std::getline(stream, str);
	album.setName(str);
	int count = 0;
	stream >> count;
	stream.get();

	for (int i = 0; i < count; i++)
	{
		Song song;
		stream >> song;
		album.addSong(song);
	}
	return stream;
}
