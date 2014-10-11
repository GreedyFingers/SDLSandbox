#pragma once
class Clock
{
private:
	int _lastUpdateTime;
	int _lastDrawTime;

	int _timeSinceLastUpdate;
	int	_timeSinceLastDraw;

public:
	Clock();
	~Clock();

	int getTimeSinceLastUpdate();
	int getTimeSinceLastDraw();

	void setTimeSinceLastUpdate(int time);
	void setTimeSinceLastDraw(int time);

};

