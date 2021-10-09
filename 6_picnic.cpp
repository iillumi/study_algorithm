#include <iostream>
#include <cstring>
using namespace std;

int c,n,m; //testcase와 학생수, 친구 쌍의 수
int arry[10][10]={0,}; // 친구를 저장할 배열
int pairarry[10]={0,}; // 짝을 지었는지 확인하는 배열

int SetPair();

int main () {
	int a,b;
	cin >> c;
	for(int i=0;i<c;i++){
		cin >> n >> m;
		for(int j=0;j<m;j++) { // 친구 배열을 세팅
			cin >> a >> b;
			arry[a][b]=1;
		}
		cout << SetPair() << "\n";
		memset(arry,0,sizeof(arry)); // 사용한 배열들 초기화
		memset(pairarry,0,sizeof(pairarry));
	}
	return 0;
}

int SetPair(){
	int finish=-1; // 짝이 없는 학생들 중 가장 빠른 번호
	int ret=0;
	for(int i=0;i<n;i++) { // 가장 빠른 번호 찾기
		if(pairarry[i]==0) {
			finish=i;
			break;
		}
	}
	if(finish==-1) return 1; // 모두 짝이 생기면 1가지 case 생성

	for(int i=finish+1;i<n;i++) { // 짝이 없고 친구일 때 짝 생성
		if(pairarry[i]==0 && (arry[finish][i]==1 || arry[i][finish]==1)){
			pairarry[finish]=1;
			pairarry[i]=1;
			ret+=SetPair();
			pairarry[finish]=0;
			pairarry[i]=0;
		}
	}
	return ret;
}
