#pragma once


class MediaPlayer
{
public:
	virtual ~MediaPlayer();

public:
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Stop() = 0;
	virtual void Seek() = 0;
};

