#include <iostream>
using namespace std;

int block[4][3][2]= // board를 덮을 block
	{{{0,0},{0,1},{1,0}},
        {{0,0},{0,1},{1,1}},
        {{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}};

bool ableBoard(char arry[][20], int, int, int, int, int); // board를 덮는 것이 가능한지 확인하는 함수
bool SetBoard(char arry[][20], int, int, char, int); // 보드를 덮는 함수
int CoverBoard(char arry[][20], int, int); // 문제를 푸는 함수

int main () {
	int c,h,w; // testcase, 행, 열
	int count; // '.'의 개수
	char arry[20][20]={0,}; // board 판
	cin >> c;
	for (int i=0;i<c;i++) { // testcase 만큼 반복
		cin >> h >> w;
		count=0;
		for (int i=0;i<h;i++) { //board setting
			cin>>arry[i];
			for (int j=0;j<w;j++) {
				if(arry[i][j]=='.') count++;
			}
		}
		if(count%3==0) cout << CoverBoard(arry,h,w) << endl; // count가 3의 배수면 실행
		else cout << '0' << endl;
	}
	return 0;
}

bool ableBoard(char arry[][20], int y, int x, int h, int w, int type){
	int dy,dx;
	for (int i=0;i<3;i++) { // block에 대해 확인한다
		dx=x+block[type][i][1];
		dy=y+block[type][i][0];
		if(dy<0||dx<0||dx>=w||dy>=h) return false; // board의 범위를 벗어날 때
		if(arry[dy][dx]=='#' || arry[dy][dx]=='$') return false; // 검은판이나 block으로 덮어진 판
	}
	return true;
}

bool SetBoard(char arry[][20], int y, int x, char index, int type){
	int dx,dy;
	for (int i=0;i<3;i++) { // index로 board를 덮는다
		dx=x+block[type][i][1];
		dy=y+block[type][i][0];
		arry[dy][dx]=index;
	}
	return true;
}

int CoverBoard(char arry[][20], int h, int w){
	int ret=0;
	int x=-1;
	int y=-1;
	for(int i=0;i<h;i++) { // 덮어야 되는 board의 칸 찾기
		for (int j=0;j<w;j++) {
			if(arry[i][j]=='.'){ 
				x=j;
				y=i;
				break;
			}
		}
		if(y!=-1) break;
	}
	if(y==-1) return 1; // 덮을 칸이 없으면 case를 하나 찾은 것
	for(int i=0;i<4;i++) {
		if(ableBoard(arry, y, x, h, w, i) == true) { // board를 덮을 수 있는지 확인
			SetBoard(arry, y, x, '$', i); // 덮을 수 있으면 '$'로 덮기
			ret+=CoverBoard(arry,h,w);
			SetBoard(arry, y, x, '.', i); // 다시 '.'으로 걷어내기
		}
	}
	return ret;
}
