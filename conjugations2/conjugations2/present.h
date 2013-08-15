#include <iostream>
#include <string>
using namespace std;

/*
OIR PRESENT
*/
string oirpresent(string base, string st, int pron)
{
	if(base=="av")
	{
		switch (pron)
		{
		case 1:
			return "ai";
		case 2:
			return "as";
		case 3:
			return "a";
		case 6:
			return "ont";
		default:
			break;
		}
	}
	if(st[1]=='.' && st[0]=='.')
	{
		switch(pron)
		{
		case 4:
			base+="oy";
			break;
		case 5:
			base+="oy";
			break;
		default:
			base+="oi";
		}
	}

	if(st[1]=='c' || st[1]=='l')
	{
		if(pron<4)
			base = base.substr(0,base.length()-1);
	}

	if(st[0]=='u')
	{
		if(pron!=4&&pron!=5)
			base[base.find_last_of('u')-1]='e';
	}
	else if(st[0]=='i')
	{
		if(pron < 4)
		base+='i';
	}
	else if(st[0]=='a')
	{
		if(pron < 4)
		{
			if(base[base.length()-1]=='a')
				base+='u';
			else
				base[base.length()-1]='u';
		}
	}
	else if(st[0]=='e')
	{
		if(pron<4)
		{
			base = base.substr(0,base.length()-1);
			if(base[base.length()-1]=='c')
				base[base.length()-1]='\x87';
			base += "oi";
		}
		else if(pron >5)
		{
			if(base[base.length()-3]=='c')
				base[base.length()-3]='\x87';
			base[base.length()-2]='o';
			base = base.substr(0,base.length()-1)+"i"+base[base.length()-1];
		}
	}
	switch(pron)
	{
	case 3:
		return base +"t";
		break;
	case 4:
		return base +"ons";
		break;
	case 5:
		return base+"ez";
		break;
	case 6:
		return base+"ent";
		break;
	default:
		if(st[4]=='x')
			return base + "x";
		return base+"s";
	}
}


/*
IR PRESENT
Regular
*/
string irpresent(string base, string st, int pron)
{
	switch(pron)
	{
	case 3:
		return base + "it";
		break;
	case 4:
		return base + "issons";
		break;
	case 5:
		return base + "issez";
		break;
	case 6:
		return base + "issent";
		break;
	default:
		return base + "is";
	}
}

/*
ER Present
*/
string erpresent(string base,string st, int pron)
{
	if(st=="aller")
	{
		switch(pron)
		{
		case 1:
			return "vais";
			break;
		case 2:
			return "vas";
			break;
		case 3:
			return "va";
			break;
		case 4:
			return "allons";
			break;
		case 5:
			return "allez";
			break;
		default:
			return "vons";
		}
	}

	//stem changers
	if(st[0]=='\x82' || st[0]=='e')
	{
		switch(pron)
		{
		case 1:
			base[base.find_last_of(st[0])]='\x8A';
			break;
		case 2:
			base[base.find_last_of(st[0])]='\x8A';
			break;
		case 3:
			base[base.find_last_of(st[0])]='\x8A';
			break;
		case 6:
			base[base.find_last_of(st[0])]='\x8A';
		}
	}

	if(st.length()<2)
		return base;
	//spelling changers
	//g
	if(st[1]=='g')
	{
		//add e for nous
		switch(pron)
		{
		case(4):
			base+="e";
			break;
		}

	}
	//c
	else if(st[1]=='c')
	{
		//add c/ for nous and vous
		switch(pron)
		{
		case(4):
			base[base.length()-1]='\x87';
			break;
		case(5):
			base[base.length()-1]='\x87';
			break;
		}

	}

	//l and t
	else if(st[1]=='l'||st[1]=='t')
	{
		switch(pron)
		{
		case(4):
			break;
		case(5):
			break;
		default:
			base+=st[1];
		}
	}


	//y
	else if(st[1]=='y')
	{
		//change to i on other than nous/vous
		switch(pron)
		{
		case(4):
			break;
		case(5):
			break;
		default:
			base[base.length()-1]='i';
		}
	}


	//no matter what
	//add endings
	switch(pron)
	{
	case 2:
		return (base+"es");
		break;
	case 4:
		return (base+"ons");
		break;
	case 5:
		return (base+"ez");
		break;
	case 6:
		return (base+"ent");
		break;
	default:
		return (base+"e");
	}

}


