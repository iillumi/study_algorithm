#include <iostream>
#include <string>
using namespace std;

int dx[8]={0,0,-1,-1,-1,1,1,1}; // 8방향을 탐색하기 위한 배열
int dy[8]={1,-1,1,0,-1,1,0,-1};
char arry[5][5]={'u','r','l','p','m','x','p','r','e','t','g','i','a','e','t','x','t','n','z','y','x','o','q','r','s'}; // 5x5형태의 기본 배열

bool hasWord(int, int, string); 

int main () {
        string word="pretty"; // 배열에서 찾을 단어
        bool result;
        for(int i=0;i<5;i++) { // 시작을 0,0부터 4,4까지 조정
                for (int j=0;j<5;j++){
                        result=hasWord(i,j,word);
                        if(result==true) {
                                cout << "exist\n";
                                return 0;
                        }
                }
        }
	cout << "not exist\n";
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
