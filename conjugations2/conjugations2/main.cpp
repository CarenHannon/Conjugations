#include <iostream>
#include <string>
#include "verb.h"

using namespace std;

int main()
{
	bool go = true;
	while(go)
	{
		string verb = "";
		cout<<endl<<"Enter a Verb"<<endl;
		cout<<"To enter an \x82 write e*"<<endl;
		cout<<"Currently this only does ER words"<<endl;
		cin>>verb;
		cout<<endl<<"Conjugation"<<endl;
		Verb newverb;
		cout<<"1"<<endl;
		newverb.make(verb);
		cout<<"2"<<endl;
		newverb.toString();
		cout<<"3"<<endl;
		cout<<"Present"<<endl;
		newverb.present();
		cout<<"Conditional"<<endl;
		newverb.conditional();
		cout<<"Future"<<endl;
		newverb.future();
		cout<<"Imperfect"<<endl;
		newverb.imperfect();
		cout<<"Subjonctive"<<endl;
		newverb.subjonctive();
		cout<<endl;
	}
	return 0;
}
