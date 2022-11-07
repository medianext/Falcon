#pragma once
#include "MediaPlayer.h"


class FilePlayer :
	public MediaPlayer
{
public:
	FilePlayer();
	explicit FilePlayer(std::string uri);
	~FilePlayer();

private:
	std::string filepath;

public:
	virtual void Play();
	virtual void Pause();
	virtual void Stop();
	virtual void Seek();
};

