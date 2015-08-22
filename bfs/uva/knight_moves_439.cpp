#include <iostream>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

int main() {
	// your code goes here
	char a[2],b[2];
	while(cin>>a>>b){
		
		int crow=a[1]-'1',ccol=a[0]-'a',trow=b[1]-'1',tcol=b[0]-'a';
		queue< pair<int,int> > q;
		pair<int,int> tmp;
		int mindist[8][8];
		memset(mindist,9999,sizeof(mindist));
		mindist[crow][ccol]=0;
		tmp=make_pair(crow,ccol);
		q.push(tmp);
		while(!q.empty()){
			crow=q.front().first;
			ccol=q.front().second;q.pop();
			if(crow-1>=0 &&ccol-2>=0 && mindist[crow-1][ccol-2]>mindist[crow][ccol]+1){
				q.push(make_pair(crow-1,ccol-2));
				mindist[crow-1][ccol-2]=mindist[crow][ccol]+1;
				
			}
			if(crow-1>=0 &&ccol+2<=7 && mindist[crow-1][ccol+2]>mindist[crow][ccol]+1){
				q.push(make_pair(crow-1,ccol+2));
				mindist[crow-1][ccol+2]=mindist[crow][ccol]+1;
			}
			
			if(crow-2>=0 &&ccol-1>=0 && mindist[crow-2][ccol-1]>mindist[crow][ccol]+1){
				q.push(make_pair(crow-2,ccol-1));
				mindist[crow-2][ccol-1]=mindist[crow][ccol]+1;
			}
			
			if(crow-2>=0 &&ccol+1<=7 && mindist[crow-2][ccol+1]>mindist[crow][ccol]+1){
				q.push(make_pair(crow-2,ccol+1));
				mindist[crow-2][ccol+1]=mindist[crow][ccol]+1;
			}
			
			if(crow+1<=7 &&ccol-2>=0 && mindist[crow+1][ccol-2]>mindist[crow][ccol]+1){
				q.push(make_pair(crow+1,ccol-2));
				mindist[crow+1][ccol-2]=mindist[crow][ccol]+1;
			}
			if(crow+1<=7 &&ccol+2<=7 && mindist[crow+1][ccol+2]>mindist[crow][ccol]+1){
				q.push(make_pair(crow+1,ccol+2));
				mindist[crow+1][ccol+2]=mindist[crow][ccol]+1;
			}
			
			if(crow+2<=7 &&ccol-1>=0 && mindist[crow+2][ccol-1]>mindist[crow][ccol]+1){
				q.push(make_pair(crow+2,ccol-1));
				 mindist[crow+2][ccol-1]=mindist[crow][ccol]+1;
			}
			
			if(crow+2<=7 &&ccol+1<=7 && mindist[crow+2][ccol+1]>mindist[crow][ccol]+1){
				q.push(make_pair(crow+2,ccol+1));
				 mindist[crow+2][ccol+1]=mindist[crow][ccol]+1;
			}


		}
		cout<<"To get from "<<a[0]<<a[1]<<" to "<<b<<" takes "<<mindist[trow][tcol]<<" knight moves."<<endl;
		
	}
	return 0;
}
