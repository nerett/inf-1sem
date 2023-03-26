#include <iostream>

using namespace std;

class Lin
{
	public:
		int cm; // сантиметры
		int mm; // миллиметры
};

void printLin( Lin a )
{
	cout<< a.cm << " " << a.mm << endl;
}

Lin convertToLin( int kletki )
{
	Lin ret_obj;

	ret_obj.mm = kletki * 5;
	while( ret_obj.mm >= 10 )
	{
		ret_obj.cm++;
		ret_obj.mm -= 10;
	}

	return ret_obj;
}

int main()
{
	return 0;
}
