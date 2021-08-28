#include <iostream>
using namespace std;

int SetBoard(char arry[][20]);

int main () {
	int c,h,w;
	char arry[20][20]={0,};
	char ch;
	cin >> c;
	for (int i=0;i<c;i++) {
		cin >> h >> w;
		for (int i=0;i<h;i++) {
			cin>>arry[i];
		}
		SetBoard(arry);
	}
	return 0;
}

int SetBoard(char arry[][20]){
	return 0;
}
