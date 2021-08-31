#include <iostream>
#include <string>
using namespace std;

int dx[8]={0,0,-1,-1,-1,1,1,1}; // 8방향을 탐색하기 위한 배열
int dy[8]={1,-1,1,0,-1,1,0,-1};
char arry[5][5]={0,}; // 5x5형태의 기본 배열

bool hasWord(int, int, string); 
bool startarea(string);

int main () {
	int c,n; // testcase와 찾을 단어의 수
	string word; // 배열에서 찾을 단어
	cin >> c;
	for(int k=0;k<c;k++) {
		for(int i=0;i<5;i++) {
                	cin>>arry[i];
	        }
		cin >> n;
		for(int i=0;i<n;i++) {
			cin >> word;
       	        	bool result;
			result=startarea(word);
			if(result == true) cout << word << " " << "YES\n";
			else cout << word << " " << "NO\n";
		}
	}
        return 0;
}

bool hasWord(int y, int x, string word){ // 재귀 이용
        int nextX, nextY; // 다음 함수의 x,y값
        if(y<0 || x<0) return false; // 배열 범위 밖일때
        if (word.front()!=arry[y][x]) return false; // 첫 글자가 다를때
        if(word.size()==1) return true; // 찾는 단어가 1글자일때
        for(int i=0;i<8;i++) { // 인접한 8칸 탐색
                nextY=y+dy[i];
                nextX=x+dx[i];
                if(hasWord(nextY, nextX, word.substr(1))==true) return true;
        }
        return false;
}

bool startarea(string word){
	for(int i=0;i<5;i++) { // 시작을 0,0부터 4,4까지 조정
		for (int j=0;j<5;j++){
        		if(hasWord(i,j,word) == true) return true;
		}
	}
	return false;
}
