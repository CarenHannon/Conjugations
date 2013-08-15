#include <iostream>
#include <string>
using namespace std;

string allconditional(string base, int pron)
{
	switch(pron)
	{

	case 3:
		return base+="ait";
		break;
	case 4:
		return base+="ions";
		break;
	case 5:
		return base+="iez";
		break;
	case 6:
		return base+="aient";
	default:
		return base+="ais";
	}
}

string erconditional(string base,string st, int pron)
{
	return allconditional(base,pron);
	
}