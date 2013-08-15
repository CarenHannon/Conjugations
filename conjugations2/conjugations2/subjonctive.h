#include <iostream>
#include <string>
using namespace std;

string allsubj(string base, int pron);
//All subj
//though it may really be an ER subj
string ersubj(string base, string st, int pron)
{
	if(st=="aller")
	{
		base = "aill";
		return allsubj(base,pron);
	}
	base = base.substr(0,base.length()-3);
	if(pron == 4 || pron == 5)
	{
		if(st[1]=='g')
			base=base.substr(0,base.length()-1);
		else if(st[1]=='c')
			base[base.length()-1]='c';
	}

	return allsubj(base,pron);
	
}
string allsubj(string base, int pron)
{
	switch(pron)
	{
	case 2:
		return base += "es";
	case 4:
		return base += "ions";
	case 5:
		return base += "iez";
	case 6:
		return base += "ent";
	default:
		return base +="e";
	}
}