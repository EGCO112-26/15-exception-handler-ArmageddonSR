#include<iostream>
using namespace std;

class my_cin : public exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Stupid it's not a number";
	}


};

class div0 : public exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Devided by 0";
	}
};

class outOfRange : public exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Out of range";
	}
};

int main(){
	int x,y;
    double d;
	
	my_cin* c = new my_cin();
	div0* f = new div0();
	outOfRange* g = new outOfRange();

	do
	{
		try{ 
				cin>>x>>y;
				if(cin.fail()) throw *c;
				if(abs(x)>10000 ||abs(y)>10000) throw *g;
				if (y==0) throw *f;
				
				d=(double) x/y;
				cout<< "The result is " <<d<<endl;
				
				double* arr;
				for(int i = 0 ;i < 999999999999999999; i++)
				{
					try
					{
						cout<<"allocating stuff....."<<endl;
						arr = new double[999999999999999999];

					}
					catch(bad_alloc& e)
					{
						std::cerr << e.what() << '\n';
					}
					break;
				}
				break;	
				
			}
	
			catch(exception& e )
			{
				cout<<e.what()<<endl;
				cin.clear();
				cin.ignore(10000,'\n');
				continue;
			}
	
	} while (1);
	
	return 1;

}
