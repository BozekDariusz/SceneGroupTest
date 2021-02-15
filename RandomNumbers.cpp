#include"RandomNumbers.h"


float RandomNumbers::generateRandomNumber(float rangeStart, float rangeEnd)
{

	return  rangeStart + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (rangeEnd - rangeStart)));

}

 RandomNumbers& RandomNumbers::getInstance()
{
    static RandomNumbers   instance;

    return instance;
}
