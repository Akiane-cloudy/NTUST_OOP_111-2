#pragma once
#ifndef _HotDogStand_H_
#define _HotDogStand_H_

class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(const char *id);
	HotDogStand(const char *id, int amount);
	~HotDogStand();
	void justSold();
	void print();
	int thisStandSoldAmount();
	static int allStandSoldAmount();
private:
	char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

#endif //_HotDogStand_H_
