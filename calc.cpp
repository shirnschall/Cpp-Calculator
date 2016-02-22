#include <stdio.h>
//std input/output
#include <iostream>
//system etc.
#include <stdlib.h>
//strings
#include <string>
//vectors/arrays
#include <vector>
//double -> string
#include <sstream>
//plot

//reverse
#include <algorithm>

//limits
#include <limits>

#define _USE_MATH_DEFINES // for C++
//math functions
#include <math.h>
//komplexe zahlen
#include <complex>
//setprecision -> double
#include <iomanip>

using namespace std;

#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803
#define E 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138


vector<long double> zahlen;
vector<char> zeichen,special;
vector<int> punkt, strich, klammer_auf, klammer_zu,doppeltminus;

string rechnung{ "" };

bool zwischenschritt{ false };

long double ans{ 0.00 }, x{ 0.00 }, y{ 0.00 }, z{ 0.00 }, a{ 0.00 }, b{ 0.00 }, c{ 0.00 }, d{ 0.00 };

int precision{ 10 };

//funktionen:
void help();
string scan();
long double ergebnis(string);
void clear();
void zuweisung(string);
void gleichung();
void polynom();
void lgs();
void geometrie();
void vectors();
void stats();
void verteilung();
void komplex();
void vars();
void plot(string);
void solve(string);

void options();


//Main
int main(void)
{
	while (true)
	{

		getline(cin, rechnung);
		//cout << endl << rechnung << endl;
		if (rechnung == "help")
		{
			help();
		}
		else if (rechnung == "exit")
		{
			exit(0);
		}
		else if (rechnung == "num" || rechnung == "num-solve" || rechnung == "1")
		{
			gleichung();
		}
		else if (rechnung == "poly" || rechnung == "poly-solve" || rechnung == "2")
		{
			polynom();
		}
		else if (rechnung == "lgs" || rechnung == "sys" || rechnung == "sys-solve" || rechnung == "3")
		{
			lgs();
		}
		else if (rechnung == "geo" || rechnung == "geometric" || rechnung == "4")
		{
			geometrie();
		}
		else if (rechnung == "vec" || rechnung == "vector" || rechnung == "5")
		{
			vectors();
		}
		else if (rechnung == "stat" || rechnung == "stats" || rechnung == "statistics" || rechnung == "6")
		{
			stats();
		}
		else if (rechnung == "dist" || rechnung == "distr" || rechnung == "distribution" || rechnung == "7")
		{
			verteilung();
		}
		else if (rechnung == "com" || rechnung == "comp" || rechnung == "complex" || rechnung == "8")
		{
			komplex();
		}
		else if (rechnung == "var" || rechnung == "vars" || rechnung == "variables" || rechnung == "9")
		{
			vars();
		}
		else if (rechnung == "options" || rechnung == "Options" || rechnung == "opt" || rechnung == "optionen" || rechnung == "0")
		{
			options();
		}
		else if (rechnung == "cls" || rechnung == "clc" || rechnung == "clear")
		{
			clear();
		}
		else if (rechnung.size() >= 2 && ((rechnung.at(0) == 'x' || rechnung.at(0) == 'y' || rechnung.at(0) == 'z' || rechnung.at(0) == 'a' || rechnung.at(0) == 'b' || rechnung.at(0) == 'c' || rechnung.at(0) == 'd') && rechnung.at(1) == '='))
		{
			zuweisung(rechnung);
		}
		else if (rechnung.size() >= 5 && rechnung.at(0) == 's' &&rechnung.at(1) == 'o' &&rechnung.at(2) == 'l' &&rechnung.at(3) == 'v' &&rechnung.at(4) == 'e')
		{
			solve(rechnung);
		}
		else if (rechnung == "zwischenschritte off" || rechnung == "zwischenschritte=false" || rechnung == "zwischenschritt off" || rechnung == "zwischenschritt=false")
		{
			zwischenschritt = false;
		}
		else if (rechnung == "zwischenschritte on" || rechnung == "zwischenschritte=true" || rechnung == "zwischenschritt on" || rechnung == "zwischenschritt=true")
		{
			zwischenschritt = true;
		}
		else if (rechnung.size() >= 5 && rechnung.at(0) == 'p' &&rechnung.at(1) == 'l' &&rechnung.at(2) == 'o' &&rechnung.at(3) == 't')
		{
			plot(rechnung);
		}
		else if (rechnung != "")
		{
			cout << "\t" << setprecision(precision) << ergebnis(rechnung) << endl;
		}
		

	}
}

//Help
void help()
{
	clear();
	cout << "1)   num-solve" << endl;
	cout << "2)   poly-solve" << endl;
	cout << "3)   sys-solve" << endl;
	cout << "4)   geometric" << endl;
	cout << "5)   vector" << endl;
	cout << "6)   statistics" << endl;
	cout << "7)   distribution" << endl;
	cout << "8)   complex" << endl;
	cout << "9)   VARS" << endl;

	cout << "\n0)   options" << endl;
}

//Scan for RPi -> GPIO
string scan()
{
	//Keyboard matrix goes here!
	string tmp{ "" };
	/*SCAN mit RPi-GPIO-Matrix!*/

	return tmp;
}

//Rechnung ausrechnen:
long double ergebnis(string rechnung)
{
	try
	{
		ostringstream strs;
		doppeltminus.clear();
		klammer_auf.clear();
		klammer_zu.clear();
		zahlen.clear();
		zeichen.clear();
		punkt.clear();
		strich.clear();
		//String teilen und innerste klammer in rechnung_aktuell speichern!
		for (int i = 0; i < rechnung.size(); ++i)
		{
			if (rechnung.at(i) == '(')
			{
				klammer_auf.push_back(i);
			}
			else if (rechnung.at(i) == ')')
			{
				klammer_zu.push_back(i);
			}
		}

		string rechnung_davor, rechnung_aktuell, rechnung_danach;
		if (!klammer_auf.empty() && !klammer_zu.empty())
		{
			for (int i = 0; i < rechnung.size(); ++i)
			{
				int j = 0;
				while (klammer_auf.at(klammer_auf.size() - 1)>klammer_zu.at(j) && j < klammer_zu.size())
				{
					j++;
				}
				if (i < klammer_auf.at(klammer_auf.size() - 1))
				{
					rechnung_davor += rechnung.at(i);
				}
				else if ((i>klammer_auf.at(klammer_auf.size() - 1)) && (i < klammer_zu.at(j)))
				{
					rechnung_aktuell += rechnung.at(i);
				}
				else if (i > klammer_zu.at(j))
				{
					rechnung_danach += rechnung.at(i);
				}
			}
		}
		else
		{
			rechnung_aktuell = rechnung;
		}

		//Rechenzeichen und zahlen in rechnung_aktuell erkennen!
		string tmp;
		for (int j = 0; j < rechnung_aktuell.size(); ++j)
		{
			if (rechnung_aktuell.at(j) == '-' && j == 0 ) //&& !(rechnung_aktuell.at(1) == '0' || rechnung_aktuell.at(1) == '1' || rechnung_aktuell.at(1) == '2' || rechnung_aktuell.at(1) == '3' || rechnung_aktuell.at(1) == '4' || rechnung_aktuell.at(1) == '5' || rechnung_aktuell.at(1) == '6' || rechnung_aktuell.at(1) == '7' || rechnung_aktuell.at(1) == '8' || rechnung_aktuell.at(1) == '9' || rechnung_aktuell.at(1) == '.')
			{
				//cout << "-1";
				zahlen.push_back(-1);
				zeichen.push_back('*');
				punkt.push_back(0);
				continue;
			}
			/*else if (rechnung_aktuell.at(j) == '-' && j == 0)
			{
				continue;
			}*/
			char akt = rechnung_aktuell.at(j);
			if (akt == '0' || akt == '1' || akt == '2' || akt == '3' || akt == '4' || akt == '5' || akt == '6' || akt == '7' || akt == '8' || akt == '9' || akt == '.')
			{
				tmp += akt;
			}
			else
			{

				if (tmp != "")
				{
					zahlen.push_back(stold(tmp));
				}
				tmp = "";

				if (akt == '*' || akt == '/' || akt == '^')
				{
					zeichen.push_back(akt);
					punkt.push_back(zeichen.size() - 1);
					//cout << punkt.at(punkt.size() - 1) * 2+1;
					if (rechnung_aktuell.at(j + 1) == '-')
					{
						doppeltminus.push_back(zeichen.size() - 1);
					}
				}
				else if (akt == '-' || akt == '+')
				{
					if (rechnung_aktuell.at(j - 1) != '*' && rechnung_aktuell.at(j - 1) != '/' && rechnung_aktuell.at(j - 1) != '+' && rechnung_aktuell.at(j - 1) != '-'&& rechnung_aktuell.at(j - 1) != '^')
					{
						zeichen.push_back(akt);
						strich.push_back(zeichen.size() - 1);
						//cout << strich.at(strich.size() - 1) * 2+1;
						if (rechnung_aktuell.at(j + 1) == '-')
						{
							doppeltminus.push_back(zeichen.size() - 1);
						}
					}
				}
				//variabelen etc. erkennen:
				else if ((akt == 'a' && rechnung_aktuell.size() == 1) || ((akt == 'a') && (rechnung_aktuell.at(j + 1) != 's') && (rechnung_aktuell.at(j + 1) != 'c') && (rechnung_aktuell.at(j + 1) != 't') && (rechnung_aktuell.at(j + 1) != 'n')))
				{
					zahlen.push_back(a);
				}
				else if (akt == 'a' && rechnung_aktuell.at(j + 1) == 'n' && rechnung_aktuell.at(j + 2) == 's')
				{
					zahlen.push_back(ans);
				}
				else if (akt == 'x')
				{
					zahlen.push_back(x);
				}
				else if (akt == 'y')
				{
					zahlen.push_back(y);
				}
				else if (akt == 'z' )
				{
					zahlen.push_back(z);
				}
				else if (akt == 'b')
				{
					zahlen.push_back(b);
				}
				else if ((akt == 'c' && rechnung_aktuell.size() == 1) || (akt == 'c' && rechnung_aktuell.at(j + 1) != 'o'))
				{
					zahlen.push_back(c);
				}
				else if (akt == 'd' )
				{
					zahlen.push_back(d);
				}
				else if (akt == 'p' && rechnung_aktuell.at(j + 1) == 'i')
				{
					zahlen.push_back(PI);
				}
				else if (akt == 'e')
				{
					zahlen.push_back(E);
				}
			}
		}
		if (tmp != "")
		{
			zahlen.push_back(stold(tmp));
		}

		//Rechnung_aktuell ausrechnen

		//punktrechnung
		for (int i = punkt.size() - 1; i >= 0; --i)
		{
			int index = punkt.at(i);
			bool minus = false;
			for (int minusindex : doppeltminus)
			{
				//cout << "minus" << endl;
				if (minusindex == index)
				{
					minus = true;
					break;
				}
				//else
				//{
				//	continue;
				//}
			}
			if (zeichen.at(index) == '^' && minus)
			{
				zahlen.at(index) = pow(zahlen.at(index), zahlen.at(index + 1)*-1);
				int tmp = (int)zahlen.at(index + 1);
				if ((tmp == zahlen.at(index + 1)) && tmp % 2 == 0)
				{
				}
				else
				{
					zeichen.at(index) = '+';
					//cout << "odd" << endl;
				}
				zahlen.at(index + 1) = 0;
			}
			else if (zeichen.at(index) == '^')
			{
				zahlen.at(index) = pow(zahlen.at(index), zahlen.at(index + 1));
				int tmp = (int)zahlen.at(index + 1);
				if ((tmp == zahlen.at(index + 1)) && tmp % 2 == 0)
				{
				}
				else
				{
					zeichen.at(index) = '+';
					//cout << "odd" << endl;
				}
				zahlen.at(index + 1) = 0;
			}
			if (zeichen.at(index) == '*' && minus) // && zeichen.at(index + 1) != '^'
			{
				zahlen.at(index) = zahlen.at(index)*zahlen.at(index + 1)*-1;
				zahlen.at(index + 1) = 0;
			}
			else if (zeichen.at(index) == '*')
			{
				zahlen.at(index) = zahlen.at(index)*zahlen.at(index + 1);
				zahlen.at(index + 1) = 0;
			}
			else if (zeichen.at(index) == '/' && minus) // && zeichen.at(index + 1) != '^'
			{
				zahlen.at(index) = zahlen.at(index) / zahlen.at(index + 1)*-1;
				zahlen.at(index + 1) = 0;
			}
			else if (zeichen.at(index) == '/')
			{
				zahlen.at(index) = zahlen.at(index) / zahlen.at(index + 1);
				zahlen.at(index + 1) = 0;
			}
		}
		long double ergebnis_aktuell = zahlen.at(0);

		//wenn nur mal rechnung(*)
		if (strich.empty())
		{
			ergebnis_aktuell = zahlen.at(0);
		}
		//strichrechnung
		for (int i = 0; i < strich.size(); ++i)
		{
			int index = strich.at(i);
			bool minus = false;
			for (int minusindex : doppeltminus)
			{
				if (minusindex == index)
				{
					//cout << "minus" << endl;
					minus = true;
					break;
				}
			}
			if (zeichen.at(index) == '-' && minus )//&& zeichen.at(index + 1) != '^'
			{
				ergebnis_aktuell += zahlen.at(index + 1);
				//cout << "\"" << ergebnis_aktuell << "\"" << endl;
			}
			else if (zeichen.at(index) == '-')
			{
				ergebnis_aktuell -= zahlen.at(index + 1);
				//cout << "\"" << ergebnis_aktuell << "\"" << endl;
			}
			else if (zeichen.at(index) == '+' && minus ) //&& zeichen.at(index + 1) != '^'
			{
				ergebnis_aktuell -= zahlen.at(index + 1);
				//cout << "\"" << ergebnis_aktuell << "\"" << endl;
			}
			else if (zeichen.at(index) == '+')
			{
				ergebnis_aktuell += zahlen.at(index + 1);
				//cout << "\"" << ergebnis_aktuell << "\"" << endl;
			}
		}

		//sin/cos/tan/sqrt funktionen:
		//sqrt
		if (rechnung_davor.size() >= 4)
		{
			if (rechnung_davor.at(rechnung_davor.size() - 1) == 't'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'r'&&rechnung_davor.at(rechnung_davor.size() - 3) == 'q'&&rechnung_davor.at(rechnung_davor.size() - 4) == 's')
			{
				//if (ergebnis_aktuell >= 0)
				//{
					ergebnis_aktuell = sqrt(ergebnis_aktuell);
				//}
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
		}
		//sin/cos/tan
		if (rechnung_davor.size() == 3)
		{
			if (rechnung_davor.at(rechnung_davor.size() - 1) == 'n'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'i' && rechnung_davor.at(rechnung_davor.size() - 3) == 's')
			{
				ergebnis_aktuell = sin(ergebnis_aktuell*PI / 180);
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if (rechnung_davor.at(rechnung_davor.size() - 1) == 's'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'o'&&rechnung_davor.at(rechnung_davor.size() - 3) == 'c')
			{
				ergebnis_aktuell = cos(ergebnis_aktuell*PI / 180);
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if (rechnung_davor.at(rechnung_davor.size() - 1) == 'n'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'a'&&rechnung_davor.at(rechnung_davor.size() - 3) == 't')
			{
				ergebnis_aktuell = tan(ergebnis_aktuell*PI / 180);
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
		}
		if (rechnung_davor.size() > 3)
		{
			if ((rechnung_davor.at(rechnung_davor.size() - 1) == 'n'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'i' && rechnung_davor.at(rechnung_davor.size() - 3) == 's') && (rechnung_davor.at(rechnung_davor.size() - 4) != 'a'))
			{
				ergebnis_aktuell = sin(ergebnis_aktuell*PI / 180);
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if (rechnung_davor.at(rechnung_davor.size() - 1) == 'n'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'i' && rechnung_davor.at(rechnung_davor.size() - 3) == 's' && rechnung_davor.at(rechnung_davor.size() - 4) == 'a')
			{
				ergebnis_aktuell = asin(ergebnis_aktuell)*180/PI;
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if ((rechnung_davor.at(rechnung_davor.size() - 1) == 's'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'o'&&rechnung_davor.at(rechnung_davor.size() - 3) == 'c') && (rechnung_davor.at(rechnung_davor.size() - 4) != 'a'))
			{
				ergebnis_aktuell = cos(ergebnis_aktuell*PI / 180);
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if (rechnung_davor.at(rechnung_davor.size() - 1) == 's'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'o' && rechnung_davor.at(rechnung_davor.size() - 3) == 'c' && rechnung_davor.at(rechnung_davor.size() - 4) == 'a')
			{
				ergebnis_aktuell = acos(ergebnis_aktuell) * 180 / PI;
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if ((rechnung_davor.at(rechnung_davor.size() - 1) == 'n'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'a'&&rechnung_davor.at(rechnung_davor.size() - 3) == 't') && (rechnung_davor.at(rechnung_davor.size() - 4) != 'a'))
			{
				ergebnis_aktuell = tan(ergebnis_aktuell*PI / 180);
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
			else if (rechnung_davor.at(rechnung_davor.size() - 1) == 'n'&&rechnung_davor.at(rechnung_davor.size() - 2) == 'a' && rechnung_davor.at(rechnung_davor.size() - 3) == 't' && rechnung_davor.at(rechnung_davor.size() - 4) == 'a')
			{
				ergebnis_aktuell = atan(ergebnis_aktuell) * 180 / PI;
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
				rechnung_davor.pop_back();
			}
		}
		//potenzen mit '('
		if (rechnung_danach.size() >= 2)
		{
			if (rechnung_danach.at(0) == '^')
			{
				string tmpld;
				for (int j = 1;j< rechnung_danach.size(); ++j)
				{
					if (rechnung_danach.at(j) == '0' || rechnung_danach.at(j) == '1' || rechnung_danach.at(j) == '2' || rechnung_danach.at(j) == '3' || rechnung_danach.at(j) == '4' || rechnung_danach.at(j) == '5' || rechnung_danach.at(j) == '6' || rechnung_danach.at(j) == '7' || rechnung_danach.at(j) == '8' || rechnung_danach.at(j) == '9' || rechnung_danach.at(j) == '.')
					{
						tmpld += rechnung_danach.at(j);
					}
					else
					{
						break;
					}

				}

				ergebnis_aktuell = pow(ergebnis_aktuell,stold(tmpld));
				//cout << rechnung_aktuell << "\"" << rechnung_danach << "\"" << ergebnis_aktuell << "\"" << tmpld<< endl;
				reverse(rechnung_danach.begin(), rechnung_danach.end());
				rechnung_danach.pop_back();
				for (int j = 0; j < tmpld.length(); ++j)
				{
					rechnung_danach.pop_back();
				}
				reverse(rechnung_danach.begin(), rechnung_danach.end());
			}
		}

		//ergebnis der aktuellen klammer (ergebnis_aktuell) in string strs mit prezision 10 umwandeln
		strs << setprecision(precision) << ergebnis_aktuell;

		//return wenn keine rechenzeichen mehr enthalten!
		if (rechnung_davor == "" && rechnung_danach == "")
		{
			ans = ergebnis_aktuell;
			//cout << "\t" << setprecision(precision) << ergebnis_aktuell << endl;
			return ergebnis_aktuell;
		}
		else
		{
			rechnung = rechnung_davor + strs.str() + rechnung_danach;
			if (zwischenschritt)
			{
				cout << rechnung_davor.c_str() << strs.str() << rechnung_danach.c_str() << endl;
			}
		}
		return ergebnis(rechnung);
	}
	catch (...)
	{
		cout << "\tERROR" << endl;
	}
}

//clear
void clear()
{
	//system("cls");		//Windows
	system("clear");		//UNIX
}

//variablen zuweisen:
void zuweisung(string rechnung)
{
	switch (rechnung.at(0))
	{
	case 'x':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		x = ergebnis(rechnung);
		cout << "x= " << setprecision(precision) << x << endl;
		break;
	case 'y':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		y = ergebnis(rechnung);
		cout << "y= " << setprecision(precision) << y << endl;
		break;
	case 'z':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		z = ergebnis(rechnung);
		cout << "z= " << setprecision(precision) << z << endl;
		break;
	case 'a':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		a = ergebnis(rechnung);
		cout << "a= " << setprecision(precision) << a << endl;
		break;
	case 'b':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		b = ergebnis(rechnung);
		cout << "b= " << setprecision(precision) << b << endl;
		break;
	case 'c':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		c = ergebnis(rechnung);
		cout << "c= " << setprecision(precision) << c << endl;
		break;
	case 'd':
		reverse(rechnung.begin(), rechnung.end());
		rechnung.pop_back();
		rechnung.pop_back();
		reverse(rechnung.begin(), rechnung.end());
		d = ergebnis(rechnung);
		cout << "d= " << setprecision(precision) << d << endl;
		break;
	default:
		break;
	}
}

//Rechenfunktionen:
void gleichung()
{
	cout << "num_solve..." << endl;
}
void polynom()
{
	bool tmp{ zwischenschritt };
	if (zwischenschritt)
	{
		zwischenschritt = false;
	}

	clear();

	int wahl{ 0 };
	long double a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 }, x1{ 0 }, x2{ 0 }, x3{ 0 };
	string as, bs, cs, ds;
	cout << "1: ax^2+bx+c=0" << endl;
	cout << "2: ax^3+bx^2+cx+d=0" << endl;
	cin >> wahl;
	switch (wahl)
	{
	case 1:
		clear();

		cout << "a= ";
		cin >> as;

		clear();

		cout << "b= ";
		cin >> bs;

		clear();

		cout << "c= ";
		cin >> cs;

		clear();
		//a,b,c ausrechnen:
		a = ergebnis(as);
		b = ergebnis(bs);
		c = ergebnis(cs);

		//complexe lösung:
		if ((pow(b, 2) - 4 * a*c) < 0)
		{
			x1 = (-b) / (2 * a);
			x2 = sqrt(fabs(pow(b, 2) - 4 * a*c)) / (2 * a);
			cout << "x1= " << x1 << " + " << x2 << "i" << endl;
			cout << "x2= " << x1 << " - " << x2 << "i" << endl;

		}
		//reelle lösung:
		else
		{
			x1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
			x2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
			cout << "x1= " << x1 << endl;
			cout << "x2= " << x2 << endl;
		}
		break;
	case 2:
		cout << "a= ";
		cin >> as;
		cout << "b= ";
		cin >> bs;
		cout << "c= ";
		cin >> cs;
		cout << "d= ";
		cin >> ds;
		cout << "nicht fertig";
		break;
	default:
		if (tmp)
		{
			zwischenschritt = true;
		}
		return;
	}
	if (tmp)
	{
		zwischenschritt = true;
	}
}
void lgs()
{
	try
	{
		int n{ 0 }, j{ 0 };
		clear();
		cout << "(Number of Variables)\ncolumns:  ";
		cin >> n;
		//ergebnis...
		n++;
		clear();
		cout << "(Number of Equations)\nRows: ";
		cin >> j;
		if (j > n - 1)
		{
			clear();
			cout << "To many equations for " << n-1 << " arables...";
			return;
		}
		//lösungs vector erstellen:
		vector<long double> losung;
		//matrix erstellen und größe anpassen:
		vector <vector <long double>> matrix;
		matrix.resize(j);
		for (int i = 0; i < j; ++i)
		{
			matrix[i].resize(n);
		}
		//werte einlesen:
		string wert{ "" };
		for (int i = 0; i < j; ++i)
		{
			for (int k = 0; k < n; ++k)
			{
				clear();
				//wert einlesen
				if (k != n-1)
				{
					cout << "Row: " << i + 1 << "  Column: " << k + 1 << endl << "X[" << k + 1 << "]=";
					cin >> wert;
				}
				else
				{
					cout << "Row: " << i + 1 << "  Column: " << k + 1 << endl << "Result[" << i + 1 << "]=";
					cin >> wert;
				}

				//wert prüfen und in matrix schreiben
				if (wert == "exit")
				{
					clear();
					return;
				}
				else
				{
					matrix[i][k] = ergebnis(wert);
				}
				wert = "";
			}
		}
		//matrix umformen:
		for (int zeile = 0; zeile < j; ++zeile)
		{
			//zeile normieren/1 in diagonale erzeugen:
			long double tmp{ matrix.at(zeile).at(zeile) };
			for (int spalte = 0; spalte < n; ++spalte)
			{
				matrix.at(zeile).at(spalte) = matrix.at(zeile).at(spalte) / tmp;
			}
			//andere zeilen normieren/0 unter 1 erzeugen:
			for (int subzeile = 0; subzeile < j; ++subzeile)
			{
				if (subzeile != zeile)
				{
					long double vielfaches{ matrix.at(subzeile).at(zeile) };
					for (int subspalte = 0; subspalte < n; ++subspalte)
					{
						matrix.at(subzeile).at(subspalte) = matrix.at(subzeile).at(subspalte) - (vielfaches * matrix.at(zeile).at(subspalte));
					}
				}
			}
		}
		//umgeformte matrix ausgeben:
		clear();
		for (vector<long double> zeile : matrix)
		{
			for (int i = 0; i < zeile.size();++i)
			{
				if ((int)zeile.at(i) == zeile.at(i))
				{
					cout << zeile.at(i) << "\t ";
				}
				else
				{
					cout << setprecision(precision) << zeile.at(i) << " ";
				}
				if (i == zeile.size() - 1)
				{
					losung.push_back(zeile.at(i));
				}
			}
			cout << "\n";
		}
		cout << "\n";
		if (j == n - 1)
		{
			for (int i = 0; i < j; ++i)
			{
				cout << "x[" << i + 1 << "]= " << setprecision(precision) << losung.at(i) << endl;
			}
		}
		else if (j < n - 1)
		{
			for (int k = 0; k < j; ++k)
			{
				cout << "x[" << k + 1 << "]= " << setprecision(precision) << losung.at(k);
				for (int i = j; i < n - 1; ++i)
				{
					cout << " + (" << matrix[k][i] * (-1) << ")x[" << i + 1 << "]";
				}
				cout << endl;
			}
			for (int k = j; k < n - 1; ++k)
			{
				cout << "x[" << k + 1 << "]= x[" << k + 1 << "]" << endl;
			}
		}
	}
	catch (...)
	{
		clear();
		cout << "ERROR" << endl;
	}
}
void geometrie()
{
	cout << "geometric..." << endl;
}
void vectors()
{

}
void stats()
{

}
void verteilung()
{

}
void komplex()
{

}
void vars()
{
	clear();
	cout << "Variables\n" << endl;
	cout << "X= " << x << endl;
	cout << "Y= " << y << endl;
	cout << "Z= " << z << endl;
	cout << "A= " << a << endl;
	cout << "B= " << b << endl;
	cout << "C= " << c << endl;
	cout << "D= " << d << endl;
}
void plot(string funktion)
{
	clear();
	bool bckup{ zwischenschritt };
	zwischenschritt = false;

	//mglGraph gr;
	//gr.FPlot("sin(pi*x)");

	zwischenschritt = bckup;
}
void solve(string rechnung)
{
	long long int k{ 0 };
	vector<long double> ergebnislinks(3), ergebnisrechts(3);

	while (k<numeric_limits<long long int>::max() && k>-numeric_limits<long long int>::max())
	{
		bool links{ true };
		string tmp1{ "" }, tmp2{ "" };
		//x mit int k ersetzen:
		for (int i = 5; i < rechnung.length(); ++i)
		{
			if (links)
			{
				if (rechnung.at(i) == '=')
				{
					links = false;
				}
				else if (rechnung.at(i) == 'x')
				{
					tmp1 += to_string(k);
				}
				else
				{
					tmp1+=rechnung.at(i);
				}
			}
			else
			{
				if (rechnung.at(i) == '=')
				{
					cout<<"ERROR";
					return;
				}
				else if (rechnung.at(i) == 'x')
				{
					tmp2 += to_string(k);
				}
				else
				{
					tmp2 += rechnung.at(i);
				}
			}
		}
		cout << tmp1.c_str() << "=" << tmp2.c_str() << endl;
		ergebnislinks.at(1) = ergebnis(tmp1);
		ergebnisrechts.at(1) = ergebnis(tmp2);
		cout << ergebnislinks.at(1) << "=" << ergebnisrechts.at(1) << endl;
		tmp1 = "";
		tmp2 = "";
		links = true;
		//x mit int k-j ersetzen:
		for (int i = 5; i < rechnung.length(); ++i)
		{
			if (links)
			{
				if (rechnung.at(i) == '=')
				{
					links = false;
				}
				else if (rechnung.at(i) == 'x')
				{
					tmp1 += to_string(k-1);
				}
				else
				{
					tmp1 += rechnung.at(i);
				}
			}
			else
			{
				if (rechnung.at(i) == '=')
				{
					cout << "ERROR";
					return;
				}
				else if (rechnung.at(i) == 'x')
				{
					tmp2 += to_string(k-1);
				}
				else
				{
					tmp2 += rechnung.at(i);
				}
			}
		}
		cout << tmp1.c_str() << "=" << tmp2.c_str() << endl;
		ergebnislinks.at(0) = ergebnis(tmp1);
		ergebnisrechts.at(0) = ergebnis(tmp2);
		cout << ergebnislinks.at(0) << "=" << ergebnisrechts.at(0) << endl;
		tmp1 = "";
		tmp2 = "";
		links = true;
		//x mit int k+j ersetzen:
		for (int i = 5; i < rechnung.length(); ++i)
		{
			if (links)
			{
				if (rechnung.at(i) == '=')
				{
					links = false;
				}
				else if (rechnung.at(i) == 'x')
				{
					tmp1 += to_string(k + 1);
				}
				else
				{
					tmp1 += rechnung.at(i);
				}
			}
			else
			{
				if (rechnung.at(i) == '=')
				{
					cout << "ERROR";
					return;
				}
				else if (rechnung.at(i) == 'x')
				{
					tmp2 += to_string(k + 1);
				}
				else
				{
					tmp2 += rechnung.at(i);
				}
			}
		}
		cout << tmp1.c_str() << "=" << tmp2.c_str() << endl;
		ergebnislinks.at(2) = ergebnis(tmp1);
		ergebnisrechts.at(2) = ergebnis(tmp2);
		cout << ergebnislinks.at(2) << "=" << ergebnisrechts.at(2) << endl;
		tmp1 = "";
		tmp2 = "";
		links = true;

		if (((ergebnislinks.at(0) - ergebnisrechts.at(0)<0 && ergebnislinks.at(1) - ergebnisrechts.at(1)>0) || (ergebnislinks.at(0) - ergebnisrechts.at(0)>0 && ergebnislinks.at(1) - ergebnisrechts.at(1)<0)) || ((ergebnislinks.at(0) - ergebnisrechts.at(0) == 0) || (ergebnislinks.at(1) - ergebnisrechts.at(1) == 0)))
		{
			break;
		}
		else
		{
			k++;
		}
	}
	cout << endl << ergebnislinks.at(0) << "=" << ergebnisrechts.at(0) << endl;
	cout << endl << ergebnislinks.at(1) << "=" << ergebnisrechts.at(1) << endl;
}

void options()
{
	print:
	clear();
	cout << "Toggle options:\n" << endl;
	cout << "1) Show steps: " << zwischenschritt << endl;
	
	cout << "\n0) exit" << endl;
	string option{ "" };
	getline(cin, option);

	if (option == "1" || option == "Zwischenschritt" || option == "zwischenschritt" || option == "Zwischenschritte" || option == "zwischenschritte")
	{
		if (zwischenschritt)
		{
			zwischenschritt = false;
		}
		else
		{
			zwischenschritt = true;
		}
		goto print;
	}
	else
	{
		clear();
		return;
	}
}