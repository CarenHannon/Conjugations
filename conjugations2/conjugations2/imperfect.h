#include <iostream>
#include <string>
using namespace std;

string allimperfect(string base,string st, int pron)
{
	if(base=="sommes")
	{
		base = "\x82t";
	}
	base = base.substr(0,base.length()-3);
	
	switch(pron)
	{
	case 3:
		return base + "ait";
		break;
	case 4:
		if(st[1]=='g')
		base = base.substr(0,base.length()-1);

		else if(st[1]=='c')
			base[base.length()-1]='c';
		return base + "ions";
		break;
	case 5:
		if(st[1]=='g')
			base = base.substr(0,base.length()-1);

		else if(st[1]=='c')
			base[base.length()-1]='c';
		return base + "iez";
		break;
	case 6:
		return base + "aient";
		break;
	default:
		return base + "ais";
	}
}