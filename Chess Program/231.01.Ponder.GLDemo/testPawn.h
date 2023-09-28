#pragma once
class testPawn
{
public:
	void run()
	{
		getBlocked();
		getSimpleMove();
		getInitialMove();
		getCapture();
		getEnpassant();
		getPromotion();
	}
private:
	void getBlocked();
	void getSimpleMove();
	void getInitialMove();
	void getCapture();
	void getEnpassant();
	void getPromotion();
};

