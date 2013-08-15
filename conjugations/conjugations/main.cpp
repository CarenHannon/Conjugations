#include <iostream>
#include <string>
#include "verbs.h"

using namespace std;

/*Needs
Future - Hard!
Present Participle (ant)
Imperative
Composite Past
Imperfect
More-than-perfect
Conditional
Future Perfect
Past Imperative


Simple past
Imperfect Subjunctive
More-than-perfect subjunctive
Conditional Perfect
Interior Past
*/

int main()
{
	bool go = true;
	while(go)
	{
	string verb = "";
	cout<<"Enter a Verb"<<endl;
	cout<<"To enter an \x82 write e*"<<endl;
	cout<<"Currently this only does ER words"<<endl;
	cout<<"Except:prot\x82ger"<<endl;
	cin>>verb;
	cout<<endl<<"Conjugation"<<endl;
	Verb newverb;
	newverb.start(verb);
	newverb.present();
	cout<<"Type y to go again (case matters)"<<endl;
	cin>>verb;
	if(verb != "y")
		go = false;
	}
	return 0;
}