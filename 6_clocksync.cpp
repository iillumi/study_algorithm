#include <iostream>
#include <algorithm>
using namespace std;

int INF=987654321;
char linkedclock[10][17] = {
	"XXX.............",
	"...X...X.X.X....",
	"....X.....X...XX",
	"X...XXXX........",
	"......XXX.X.X...",
	"X.X...........XX",
	"...X..........XX",
	"....XX.X......XX",
	".XXXXX..........",
	"...XXX...X...X.."};

int findcase (int *, int);
bool checkclock(int *);

int main () {
	int answer;
	int c;
	int arry[16]={0,};
	cin >> c;
	for (int i=0;i<c;i++) {
		for (int j=0;j<16;j++){
			cin >> arry[j];
		}
		answer=findcase(arry,0);
		cout << (answer==INF ? -1 : answer) << endl;
	}
	return 0;
}

int findcase(int *arry, int NumSwitch){
	if(NumSwitch==10) return checkclock(arry) ? 0 : INF;
	int ret=INF;
	for(int i=0;i<4;i++) {
		ret=min(ret,i+findcase(arry, NumSwitch+1));
		for(int j=0;j<16;j++) {
			if(linkedclock[NumSwitch][j]=='X'){
				arry[j]+=3;
				if(arry[j]==15) arry[j]=3;
			}
		}
	}
	return ret;
}

bool checkclock (int * arry) {
	for(int i=0;i<16;i++) {
		if(arry[i]!=12) return false;
	}
	return true;
}
