#include <iostream>
#include <string>
using namespace std;

string allfuture(string base, int pron);

string erbase(string base,string st, int pron)
{
	if(st[0]=='e')
	{
		base[base.find_last_of('e')]='\x8A';
	}

	if(st[1]=='l' || st[1]=='t')
	{
		base+=st[1];
	}

	base += "er";

	if(st=="aller")
		base = "ir";
	return base;
}
string erfuture(string base,string st, int pron)
{
	base = erbase(base,st,pron);
	return allfuture(base,pron);
	
}


string allfuture(string base, int pron)
{
	switch(pron)
	{
	case 1:
		return base+="ai";
		break;
	case 2:
		return base+="as";
		break;
	case 3:
		return base+="a";
		break;
	case 4:
		return base+="ons";
		break;
	case 5:
		return base+="ez";
		break;
	default:
		return base+="ent";
	}
}