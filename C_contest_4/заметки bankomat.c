#define MAXSUM 1024000
#define MAXNOTES 128

int best[MAXSUM];
how[MAXSUM];

notes[MAXNOTES];

for(....
	best[i]=INT32_MAX;

best[0] = 0;
how[0] = 0;
foreach note in notes
{

if(best[i] < INT32_MAX) //нашли вариант
	for(...
		if( //улучшаем ситуацию?
			best[i+note] = best[i] + 1;
			how[i+note] = note;

}		

best[sum] => ответ
while(how[sum])
{
	how[sum] => вывести
	sum = sum - how[sum];
}
