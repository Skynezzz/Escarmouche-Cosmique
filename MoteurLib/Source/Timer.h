#pragma once

class Timer
{
public:
	Timer();
	float TotalTime(); 
	float DeltaTime();

	void Start(); //Sert à lancer le timer
	void Stop(); //Sert à mettre en pause le timer
	void Reset(); //Sert à réinitialiser le timer
	void Tick();

private:
	float mSecondsPerCount;
	float mDeltaTime;

	float mBaseTime;
	float mStopTimePressed; //Sert à récupérer le temps où le timer à été mis en pause (Sert ensuite de point de départ lors du resume)
	float mStopTime; //Sert à contenir tout le temps écoulé lors de l'état "EN PAUSE" 
	float mPreviousTime;
	float mCurrentTime; //Sert à contenir le temps actuel

	bool mIsStopped; //Sert d'état pour savoir si oui ou non le temps est en pause
};

