#include <iostream>
#include <string>
using namespace std;

int dx[8]={0,0,-1,-1,-1,1,1,1};
int dy[8]={1,-1,1,0,-1,1,0,-1};
char arry[5][5]={'u','r','l','p','m','x','p','r','e','t','g','i','a','e','t','x','t','n','z','y','x','o','q','r','s'};

bool hasWord(int, int, string);

int main () {
        string word="pretty";
        bool result;
        for(int i=0;i<5;i++) {
                for (int j=0;j<5;j++){
                        result=hasWord(i,j,word);
                        if(result==true) {
                                printf("exist\n");
                                return 0;
                        }
                }
        }
        printf("not exist\n");
        return 0;
}

bool hasWord(int y, int x, string word){
        int nextX, nextY;
        if(y<0 || x<0) return false;
        if (word.front()!=arry[y][x]) return false;
        if(word.size()==1) return true;
        for(int i=0;i<8;i++) {
                nextY=y+dy[i];
                nextX=x+dx[i];
                if(hasWord(nextY, nextX, word.substr(1))==true) return true;
        }
        return false;
}

