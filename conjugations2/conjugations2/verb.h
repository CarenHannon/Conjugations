#include <iostream>
#include <string>
#include "present.h"
#include "imperfect.h"
#include "future.h"
#include "conditional.h"
#include "subjonctive.h"
using namespace std;

struct Verb{
	string original;
	string root;
	string type;
	string sub;
	string conj;
	int c;

	/*to Low method
	Switches first character to lowercase if needed
	*/
	void tolow()
	{
		switch(original[0])
		{
		case 'A':
			original[0]='a';
			break;
		case 'B':
			original[0]='b';
			break;
		case 'C':
			original[0]='c';
			break;
		case 'D':
			original[0]='d';
			break;
		case 'E':
			original[0]='e';
			break;
		case 'F':
			original[0]='f';
			break;
		case 'G':
			original[0]='g';
			break;
		case 'H':
			original[0]='h';
			break;
		case 'I':
			original[0]='i';
			break;
		case 'J':
			original[0]='j';
			break;
		case 'K':
			original[0]='k';
			break;
		case 'L':
			original[0]='l';
			break;
		case 'M':
			original[0]='m';
			break;
		case 'N':
			original[0]='n';
			break;
		case 'O':
			original[0]='o';
			break;
		case 'P':
			original[0]='p';
			break;
		case 'Q':
			original[0]='q';
			break;
		case 'R':
			original[0]='r';
			break;
		case 'S':
			original[0]='s';
			break;
		case 'T':
			original[0]='t';
			break;
		case 'U':
			original[0]='u';
			break;
		case 'V':
			original[0]='v';
			break;
		case 'W':
			original[0]='w';
			break;
		case 'X':
			original[0]='x';
			break;
		case 'Y':
			original[0]='y';
			break;
		case 'Z':
			original[0]='z';
			break;
		default:
			original[0]=original[0];
		}
	}


	/*
	Make method
	Constructor for Verbs
	*/
	void make(string passed)
	{
		int length = passed.length();
		if(length<4)
			return;
		original = passed;
		tolow();
		type = original.substr(length-2);
		fixType();

		//get cons must be before fixchars
		c = getCons();
		fixchars();
		length=original.length();
		root = original.substr(0,original.length()-type.length());
		getSub();
		conj = "n/a";

	}

	/*Fix Type
	Changes verb type if it can't be easily told the usually way
	Changes -oir from IR verbs to OIR verbs
	*/
	void fixType()
	{
		if(type == "ir")
			if(original[original.length()-3]=='o')
				type = "oir";
	}

	/*
	Fix Chars
	Changes character encoding input to character codes
	e* and e^ support only
	*/
	void fixchars()
	{
		int pos = -1;
		for(int i = 0; i < (int)(original.length()); i++)
		{
			if(original[i]=='*')
			{
				original[i-1]='\x82';
				original = original.substr(0,i)+ original.substr(i+1);
			}
			else if(original[i]=='^')
			{
				original[i-1]='\x88';
				original = original.substr(0,i)+ original.substr(i+1);
			}
		}
		if(original[original.length()-(2+c)]=='\x82')
			c--;

	}

	/*Get Sub
	Calls the proper function to determin subtype
	ER and IR support only
	*/
	void getSub()
	{
		if(type=="er")
			geterSub();
		else if(type=="ir")
			getirSub();
		else if(type=="oir")
			getoirSub();
		else
			sub = "n/a";
		return;
	}

	/*
	Get OIR sub
	*/
	void getoirSub()
	{
		sub="......";
		if(root.length()<2)
			return;
		if(root[root.length()-1]=='s' || root[root.length()-1]=='e')
		{
			//asseoir, assoir, etc..
			sub[1]='s';
			return;
		}
		else if(root[root.length()-1]=='r')
		{
			//special
			sub="~roir";
			return;
		}
		else if(root[root.length()-1]=='h')
			return;
		if(c>0)
		{

			sub[1] = 'c';
			//vowel determiners
			if(root[root.length()-(c+1)]=='a')
			{
				if(root[root.length()-1]=='v')
				{
					sub[0]='i';
					return;
				}
				sub[0]='a';
			}
			else if(root[root.length()-(c+1)]=='e')
			{
				
				if(root.length()>=3)
				{ //revoir
					if(root=="rev")
					{
						sub[1]='.';
						return;
					}
					if(root.length()>=6)
					{
						if(root.substr(root.length()-6)=="entrev")
						{
							sub[1]='.';
							return;
						}
					}

					sub[0]='e';
				}
			}
			else if(root[root.length()-(c+1)]=='u')
			{
				if(root.length()>=4)
				{
					if(root.substr(root.length()-4)=="pouv"||root.substr(root.length()-4)=="voul")
						sub[4]='x';
				}

				//pourvoir
				if(root.length()>=5)
				{
					if(root.substr(root.length()-5)=="pourv")
					{
						sub[1]='.';
						return;
					}
				}

				sub[0]='u';
			}
			//consonant determiners
			if(root[root.length()-1]=='l')
			{
				sub[1]='l';
				sub[4]='x';
			}
			if(root.length()>=4)
			{								

				if(root.substr(root.length()-4)=="pr\x82v")
				{
					sub[1]='.';
					return;
				}
			}
		}
	}
	/*
	Get IR Sub
	Get subtypes for all  ir verbs. Mostly determines irregularity.
	*/
	void getirSub()
	{
		sub = "..";
		if(root.length()<=1)
			return;

		//u subtype for ~fuir verbs
		if(root.substr(root.length()-2)=="fu")
			sub[1] = 'u';

		if(root.length()<=2)
			return;

		//v subtype for ~rvir verbs
		if(root.substr(root.length()-2)=="rv")
		{
			if(root.length()>=6)
				if(root.substr(root.length()-6)=="asserv")
					return;
			sub[1] = 'v';
		}

		//s subtype for ~e*sir verbs
		else if(root.substr(root.length()-2)=="\x82s")
			sub[1] = 's';

		//n subtype for ~enir verbs
		else if(root.substr(root.length()-2)=="en")
			sub[1] = 'n';

		//various rir subtypes
		else if(root.substr(root.length()-1)=="r")
		{
			if(root.substr(root.length()-2)=="fr")
				sub[1] = 'F';
			else if(root.substr(root.length()-3)=="f\x82r")
				sub[1] = 'f';

			if(root.length()>=4)
			{
				if(root.substr(root.length()-4)=="qu\x82r")
					sub[1] = 'q';
				else if(root.substr(root.length()-3)=="our")
					sub[1] = 'o';
			}
		}

		//various tir subtypes
		else if(root.substr(root.length()-1)=="t")
		{
			if(root.substr(root.length()-3)=="v\x88t")
				sub="\x88t";
			if(root.length()>=4)
			{
				if(root.substr(root.length()-3)=="ent")
				{
					if(root[root.length()-4]=='m'||root[root.length()-4]=='s'||
						root[root.length()-4]=='p')
						sub="et";
				}
				else if (root.substr(root.length()-4)=="part")
				{
					if(root.length()==6)
					{
						if(root=="impart")
							sub = "impartir";
					}
					else 
						sub = "at";
				}
				else if (root.substr(root.length()-4)=="sort")
				{
					if(root.length()>=6)
					{
						if(root.substr(root.length()-6)=="assort")
							sub = "..";
					}
					else 
						sub = "ot";
				}
			}
		}

		if(root.length()<=3)
			return;

		//m subtype for ~ormir verbs
		if(root.substr(root.length()-4)=="dorm")
			sub[1] = 'm';

		//L subtype for ill verbs
		else if (root.substr(root.length()-3)=="ill")
		{
			sub[1] = 'L';
			if(root.length()>=5)
			{
				//aillir
				if(root[root.length()- 4]=='a')
				{
					if(root=="jaill")
						sub="..";
					else
						sub[0] = 'a';
				}
				//uillir
				else if(root[root.length()-4]=='u')
					sub[0] = 'u';
				if(root.length()>=6)
				{
					if(root.substr(root.length()-5)=="ueill")
					{
						if(root[root.length()-6]=='c')
						sub[0] = 'e';
						else
							sub="..";
					}
				}
			}
		}
	}

	/*
	Determines ER subtypes
	Including aller, stem changes, and spelling changes
	*/
	void geterSub()
	{
		sub = "..";
		if(root=="all")
		{
			sub = "aller";
			return;
		}
		if(c > 0)
		{
			if(root[root.length()-(c+1)] == '\x82')
			{
				sub[0]= '\x82';

			}
			if(root[root.length()-1] == 'g')
			{
				if(root[root.length()-2] == 'e')
					sub[0]='e';
				sub[1]= 'g';
				return;
			}
			else if(root[root.length()-1] == 'c')
			{
				if(root[root.length()-2] == 'e')
					sub[0]='e';
				sub[1]= 'c';
				return;
			}

			else if(root[root.length()-1] == 'u')
			{
				sub = "..";
				return;
			}

			if(root[root.length()-(c+1)] == 'e')
			{	
				sub[0] = 'e';
				if(root[root.length()-1] == 'l')
				{
					if(root == "gel" || root == "harcel" || root =="pel")
						sub[0] = 'e';
					else if(root[root.length()-2] == 'e')
						sub = ".l";
					else
						sub = "..";
				}
				else if(root[root.length()-1] == 't')
				{
					if(root == "achet")
						sub[0] = 'e';
					else if(root[root.length()-2] == 'e')
						sub = ".t";
					else
						sub = "..";
				}
				return;
			}
			return;
		}
		if(root[root.length()-1] == 'y')
		{
			sub = ".y";
			return;
		}
		sub = "..";

	}

	/*
	Get cons
	Helping function for ER subtypes
	Determines consonants between ending and previous vowels
	*/
	int getCons()
	{
		int k = 1;
		char check[6] = {'a','e','i','o','u','y'};
		int cons = 0;
		bool pass = true;
		if(original.substr((original.length()-4), (original.length()-(original.length()-2)))=="gu")
		{
			cons=2;
			k = 3;
		}
		while(pass)
		{
			char temp = original[original.length()-(type.length()+k)];
			for(int j = 0; j < 6; j++)
			{
				if(temp==check[j])
				{
					pass = false;
				}
			}

			if(pass == true)
				cons++;
			k++;
			if((k-1) == (original.length()-type.length()))
				pass = false;
		}
		return cons;

	}

	//Gets Present Tense
	//ER and regular IR support only
	void present()
	{
		if(this->type=="er")
		{
			for(int j = 1; j <= 6; j++)
				cout<<erpresent(root,sub,j)<<endl;
			cout<<endl;
		}
		else if(type=="oir")
		{
			for(int j = 1; j <= 6; j++)
				cout<<oirpresent(root,sub,j)<<endl;
			cout<<endl;
		}

		else if(type=="ir" && sub =="..")
		{
			for(int j = 1; j <= 6; j++)
				cout<<irpresent(root,sub,j)<<endl;
			cout<<endl;
		}
		else
			cout<<"Cannot Conjugate"<<endl;
	}

	/*
	Present (single)
	Gets single present
	Helping function for other tenses
	ER and Regular IR support only
	*/
	string present(int pick)
	{
		if(type=="er")
			return erpresent(root,sub,pick);
		else if(type=="ir" && sub =="..")
			return irpresent(root,sub,pick);
		cout<<"Cannot Conjugate"<<endl;		
	}

	/*
	Imperfect
	ER and Reg IR support only
	*/
	void imperfect()
	{
		if(type!="er" && (!(type=="ir" && sub=="..")))
		{
			cout<<"Cannot Conjugate"<<endl;
			return;
		}

		conj = present(4);
		for(int j = 1; j <= 6; j++)
		{
			cout<<allimperfect(conj,sub,j)<<endl;
		}
		cout<<endl;
	}

	/*
	Future Tense
	ER and reg IR support only
	*/
	void future()
	{

		if(type=="er")
		{
			for(int j = 1; j <= 6; j++)
				cout<<erfuture(root,sub,j)<<endl;
			cout<<endl;

		}
		else if(type=="ir" && sub=="..")
		{
			for(int j = 1; j <= 6; j++)
				cout<<allfuture(original,j)<<endl;
			cout<<endl;
		}
		else 
			cout<<"Cannot Conjugate"<<endl;


	}

	/*Subjonctive tense
	ER and reg IR support
	*/
	void subjonctive()
	{
		if(type!="er" && (!(type=="ir"&&sub=="..")))
		{
			cout<<"Cannot Conjugate"<<endl;
			return;
		}
		for(int j = 1; j <=6; j++)
		{
			if(type!="..")
			{
				if(j == 4 || j == 5)
					cout<<ersubj(present(4),sub,j)<<endl;
				else
					cout<<ersubj(present(6),sub,j)<<endl;
			}
			else
				cout<<ersubj(present(6),sub,j)<<endl;

		}
		cout<<endl;
	}

	/*
	Conditional
	ER support
	*/
	void conditional()
	{
		if(type=="er")
		{
			for(int j = 1; j <= 6; j++)
				cout<<erconditional(erbase(root,sub,j),sub,j)<<endl;
			cout<<endl;
		}
		else if(type=="ir" && sub=="..")
		{
			for(int j = 1; j <= 6; j++)
				cout<<allconditional(original,j)<<endl;
			cout<<endl;
		}
		else
			cout<<"Cannot Conjugate"<<endl;

	}

	//ToString
	void toString()
	{
		cout<<endl<<"Verb Profile: ";
		cout<<endl<<"Verb:" + original;
		cout<<endl<<"Root:" + root +"\tType:" + type;
		cout<<endl<<"SubType:" + sub;
		cout<<endl<<"Consonants: "<<c<<endl;
	}
};