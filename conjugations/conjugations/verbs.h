#include <iostream>
#include <string>
using namespace std;

string pronouns[6] = {"je/j'", "tu", "il/elle/on", "nous", "vous","ils/elles"};
struct Verb{
	string original;
	string root;
	string type;
	string conj;
	bool reg;

	//initializer
	void start(string passed)
	{
		int length = passed.length();
		if(length<2)
			return;
		original = passed;
		root = passed.substr(0,length-2);
		type = passed.substr(length-2);
		reg = checkReg();
		conj = "n/a";
	}

	void reset()
	{
		root = original.substr(0,original.length()-2);
	}

	//er checkRegular
	bool checkReg()
	{
		if(this->type=="er")
			if(this->root=="all")
				return 0;
			else
				return 1;
		return 0;
	}

	int consonantcheck()
	{
		int k = 1;
		char check[6] = {'a','e','i','o','u','y'};
		int cons = 0;
		bool pass = true;
		while(pass)
		{
			char temp = this->root[root.length()-k];
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
		}
		return cons;

	}

	//Displays all conjugations
	void present()
	{
		bool success = false;
		for(int i = 0; i < 6; i++)
		{
			success=this->present(i+1);
		}
		if(!success)
			cout<<"Could Not Conjugate"<<endl;

	}

	//Gets one conjugation
	bool present(int conjugate)
	{
		if(this->type=="er")
		{
			erpresent(conjugate);
			return true;
		}
		return false;
	}

	//ER Present Conjugations
	void erpresent(int place)
	{
		bool finish = false;
		//handles cer
		if(this->root[(this->root.length()-1)]=='c')
		{
			if(place==4)
			{
				conj =root.substr(0,root.length()-1) + "\x87" +erendings[place-1];
			}
			else
				conj = root + erendings[place-1];
			finish = true;
		}

		//handles ger
		else if(this->root[(this->root.length()-1)]=='g')
		{
			if(place==4)
				conj = root + 'e' + erendings[place-1];
			else
				conj = root + erendings[place-1];
			finish = true;
		}

		//handles yer
		if(this->root[(this->root.length()-1)]=='y')
		{
			if(place==4 || place==5)
				conj = root + erendings[place-1];
			else
				conj =root.substr(0,root.length()-1) + "i" +erendings[place-1];
			finish = true;

		}

		//yer verbs
		else if(this->root[(this->root.length()-1)]=='y')
		{
			if(place==4)
				conj = root + 'e' + erendings[place-1];
			else
				conj = root + erendings[place-1];
			finish = true;
		}	

		//eler
		//eter


		else if(this->root.substr(root.length()-2)=="el")
		{
			if(place==4 || place==5)
				conj = root +erendings[place-1];
			else
				conj = root + "l"+ erendings[place-1];
			finish = true;
			if(root == "gel" || root=="harcel" || root=="pel")
				finish = false;
		}

		else if(this->root.substr(root.length()-2)=="et")
		{
			if(place==4 || place==5)
				conj = root +erendings[place-1];
			else
				conj = root + "t"+ erendings[place-1];
			finish = true;
			if(root == "achet")
				finish = false;
		}

		int cons = this->consonantcheck();
		if(!finish&&(root[root.length()-(cons+1)]== 'e' || root[root.length()-(cons+1)]== '*'))
		{
			if(root[root.length()-(cons)]=='*')
			{
				root = root.substr(0,root.length()-(cons))+root.substr(root.length()-(cons-1));
				root[(root.length()-cons)]='\x82';
				cons--;
			}
			if(place < 4 || place >5)
			{
				root[root.length()-(cons+1)]='\x8A';
			}
			conj = root +erendings[place-1];
			
			finish = true;
		}

		//eler
		//eter
		//e er
		//e' er

		//handles ALLER
		else if(root=="all")
		{
			if(place >= 4)
				if(place == 6)
					conj = "vons";
				else
					conj = root + erendings[place-1];
			else if(place == 1)
				conj = "vais";
			else if(place == 2)
				conj = "vas";
			else if(place == 3)
				conj = "va";
			finish = true;
		}
		//handles all other regulars
		if(!finish)
		{
			conj = root + erendings[place-1];
		}
		cout<<pronouns[place-1]<<" "<<conj<<endl;
		reset();
	}

};


