#include <iostream>
#include <algorithm>
using namespace std;

int INF=987654321; // 12시를 맞추기 위해 사용되는 큰 수
char linkedclock[10][17] = { // 각각의 버튼에 연결된 시계('X')
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
	cin >> c; // testcase
	for (int i=0;i<c;i++) {
		for (int j=0;j<16;j++){
			cin >> arry[j];
		}
		answer=findcase(arry,0);
		cout << (answer==INF ? -1 : answer) << endl; // 못 만들면 -1 출력
	}
	return 0;
}

int findcase(int *arry, int NumSwitch){
	if(NumSwitch==10) return checkclock(arry) ? 0 : INF; // 10번 스위치까지 누르면 종료
	int ret=INF;
	for(int i=0;i<4;i++) { // 스위치를 4번 누르는 경우 수행 (4번 누르면 원래시간으로 복귀)
		ret=min(ret,i+findcase(arry, NumSwitch+1)); // 12시로 만드는 최소값 반환
		for(int j=0;j<16;j++) { // 각각의 버튼에 연결된 시계의 시간 +3
			if(linkedclock[NumSwitch][j]=='X'){
				arry[j]+=3;
				if(arry[j]==15) arry[j]=3;
			}
		}
	}
	return ret;
}

bool checkclock (int * arry) { // 시계가 모두 12시가 됐는지 확인
	for(int i=0;i<16;i++) {
		if(arry[i]!=12) return false;
	}
	return true;
}
