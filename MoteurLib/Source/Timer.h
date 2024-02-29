#pragma once

class Timer
{
public:
	Timer();
	float TotalTime(); 
	float DeltaTime();

	void Start(); //Sert � lancer le timer
	void Stop(); //Sert � mettre en pause le timer
	void Reset(); //Sert � r�initialiser le timer
	void Tick();

private:
	float mSecondsPerCount;
	float mDeltaTime;

	float mBaseTime;
	float mStopTimePressed; //Sert � r�cup�rer le temps o� le timer � �t� mis en pause (Sert ensuite de point de d�part lors du resume)
	float mStopTime; //Sert � contenir tout le temps �coul� lors de l'�tat "EN PAUSE" 
	float mPreviousTime;
	float mCurrentTime; //Sert � contenir le temps actuel

	bool mIsStopped; //Sert d'�tat pour savoir si oui ou non le temps est en pause
};

