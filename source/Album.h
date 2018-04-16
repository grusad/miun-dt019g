/*
* Filename:		Album.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#pragma once

#include <vector>
#include "Song.h"

//------------------------------------------------------------------------------
//	A class that represent an album conaining songs.
//------------------------------------------------------------------------------
class Album
{

private:
	std::string m_name;
	std::vector<Song> m_songs;

public:
	// Constructors.
	Album() : m_name("") {};
	Album(std::string name) : m_name(name) {};

	void addSong(const Song &song) { m_songs.push_back(song); };

	// Getters.
	Time getTotalTime() const;
	Song getSong(const int index) const { return m_songs[index]; };
	int getCount() const { return m_songs.size(); };
	std::string getName() const { return m_name; };
	std::vector<Song> &getAllSongs() { return m_songs; };

	// Setters.
	void setName(const std::string name) { m_name = name; };

	bool operator<(const Album &album) const;
	bool operator==(const Album &album) const;

};

std::ostream &operator<<(std::ostream &stream, const Album &album);
std::istream &operator>>(std::istream &stream, Album &album);