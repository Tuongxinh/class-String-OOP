
#include"string.h"

void testCapacity(String x)
{
	
	int input;
	char ch;
	cout << "\n-------------------------- CAPACITY --------------------------" << endl;
	cout << "\n***** Test str: " << x;
	cout << "\nSize: " << x.size();
	cout << "\nLength:"  << x.length();
	cout << "\nMax_size: "  << x.max_size();
	cout << "\nCapacity: "  << x.capacity();
	//

	cout << "\nResize: ";
	cout << "\n\t1. void resize (size_t n)";
	cout << "\n\t\t- Input new string length: ";
	cin >> input; 
	x.resize(input);
	cout << "\n\t\t- After use ( void resize (size_t n) )        length = " << x.length()  << "\t\tstr = " << x;
	cout << "\n\n\t2. void resize (size_t n, char c)";
	cout << "\n\t\t- Input new string length: "; cin >> input;
	cout << "\n\t\t- Resize  the string to a length of ???? characters: "; 
	cin >> ch;
	x.resize(input, ch);
	cout << "\n\t\t- After use ( void resize (size_t n, char c) )        length = " <<x.length()<< "\t\tstr = " << x;
 
		

	//
	cout << "\nReserve: "; cout << "\n\t-New string capacity: "; cin >> input; x.reserve(input);
	cout << "\n\t-After reserve, capacity = " << x.capacity();
	//
	
	//
	cout << "\nIs string empty: " << x.empty();
	cout << "\nShrink to fit: ";
	x.shrink_to_fit();
	cout << "\t\tLength = " << x.length();
	cout << "\t\tCapacity = " << x.capacity();
	//
	cout << "\nClear: ";
	x.clear();
	cout << "\n\t- After clear, str = " << x;
	cout << "\t\tlength = " << x.length();
	cout << "\t\tcapacity = " << x.capacity();

}
void main()
{

	/*String y("cat btuong dep gai");*/
	//copy

	/*char s[100];
	try{
	int len = y.copy(s, 25, 9);
	s[len] = '\0';
	cout << "\nlen= " << len;
	cout << "\nCopy string: ";
	for (int i = 0; i < len; i++)
	{
	cout << s[i];
	}
	}
	catch (char* c)
	{
	cout << c;
	}*/

	//find_first_of
	/*String a("adfafkdn");
	String b("xyz");
	cout << "\nBefore a: " << a.data() << "\tBefore b: " << b.data() << endl;
	a.swap(b);
	cout << "\nAfter a: " << a.data() << "\tAfter b: " << b.data() << endl;

	cout<<b.erase(2, 3).data();

	a.push_back('t');
	cout << a.data();*/
	////pop back
	//String s("tuong");
	//s.pop_back();
	//cout << s.data();

	////compare
	//String t("zz");
	//cout << s.compare(t);
	/*String y("Hey.");
	y.back() = '!';
	cout << y.data();*/



	//int 	sz= x.length();
	//cout << sz << endl;
	//cout << "capacity: " << x.capacity()<<endl;
	//x.resize(sz+2,'+');
	//cout << x.data() << endl;
	//cout << "new len:" << x.length() << endl;

	/*String x("liu tuong");

	cout << x.data()<<endl;
	cout << "\nlen: " << x.length();
	cout << "\ncapa: " << x.capacity();

	x.append(" xinh dep");
	cout << "\n sau : ";
	cout << x.data() << endl;
	cout << "\nlen: " << x.length();
	cout << "\ncapa: " << x.capacity();

	x += "...";
	cout << x.data();
	x.shrink_to_fit();
	cout << endl;
	cout << x.capacity() << endl;
	cout << x.length();*/

	/*String x("look for non-alphabetic characters...");

	int kq = x.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
	cout << kq;*/


	/*String x(" Doing Insert test here");
	String y("@.@");

	x.insert(6,y,0,3);
	cout << x.length();
	cout << x.data();*/

	/*String x("Lieu Tuong");
	String t("Lion");
	x.replace(5, 5, t);
	cout << x.data();*/
	String str1("test capacity");
	CT::iterator i = str1.begin();
	for (i; i != str1.end(); i++)
	{
		cout << *i;
	}

}