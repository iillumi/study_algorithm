#include <iostream>
using namespace std;

int block[4][3][2]=
	{{(0,0),(0,1),(1,0)},
        {(0,0),(0,1),(1,1)},
        {(0,0),(1,0),(1,1)},
	{(0,0),(1,0),(1,-1)}};

bool SetBoard(char arry[][20], int, int, int, int, int, int);
int CoverBoard(char arry[][20], int, int);

int main () {
	int c,h,w;
	int count;
	char arry[20][20]={0,};
	char ch;
	cin >> c;
	for (int i=0;i<c;i++) {
		cin >> h >> w;
		count=0;
		for (int i=0;i<h;i++) {
			cin>>arry[i];
			for (int j=0;j<w;j++) {
				if(arry[i][j]=='.') count++;
			}
		}
		if(count%3==0) cout << CoverBoard(arry,h,w) << endl;
		else cout << '0' << endl;
	}
	return 0;
}

bool SetBoard(char arry[][20], int y, int x, int data, int type, int h, int w){
	int dx,dy;
	for (int i=0;i<3;i++) {
		dx=x+block[type][i][1];
		dy=y+block[type][i][0];
		if(dy<0 || dx<0 || dy>=h || dx>=w) return false;
		else if(data==1){
			if(arry[dy][dx]=='$' || arry[dy][dx]=='#') return false;
			arry[dy][dx]='$';
		}
		else if(data==-1){
			if(arry[dy][dx]=='$') arry[dy][dx]='.';
		}
	}
	return true;
}

int CoverBoard(char arry[][20], int h, int w){
	int ret=0;
	int x=-1;
	int y=-1;
	for(int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			if(arry[i][j]=='.'){
				x=j;
				y=i;
				break;
			}
		}
		if(y!=-1) break;
	}
	if(y==-1) return 1;
	for(int i=0;i<4;i++) {
		if(SetBoard(arry, y, x, 1, i, h, w) == true) ret+=CoverBoard(arry,h,w);
		SetBoard(arry, y, x, -1, i, h, w);
	}
	return ret;
}
