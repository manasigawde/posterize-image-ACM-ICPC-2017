#include <algorithm>
#include <cstring>
#include <iostream>
#include<unistd.h>
#include<stdio.h>
#include<iomanip>



using namespace std;

long long nv[256];
long long cumsum[257][257];

long long memo[256][256];
long long doit(int p, int k, int cur) {
  if (p == 256) return 0;
  if (k == 0) return 1e18;
  long long& ret = memo[p][k];
  if (ret != -1) return ret;
  ret = 1e18;
 


  for (int p2 = p+1; p2 <= 256; p2++) {
    while (cumsum[cur+1][p2] - cumsum[cur+1][p] <
           cumsum[cur][p2] - cumsum[cur][p]) {
      
      cur++;
      

    }
    
    
    ret = min(ret, cumsum[cur][p2] - cumsum[cur][p] + doit(p2, k-1, cur));
      
    
  }
  return ret;
}

int main() {
  int D, K, R, P,i,v,p=0;
  int t  , u;
	cout<<setw(40)<<"WELCOME TO ACM-ICPC 2017 PROBLEM"<<endl;
	cout<<setw(30)<<"PROBLEM STATEMENT :"<<setw(3)<<"POSTERIZE"<<endl;
	
    int count = 0;
    cout << "Will load in 3 Sec " << endl << "Loading ";
    for(count;count < 3; ++count){
        cout << ". " ;
        fflush(stdout);
        sleep(1);
    }
    cout << endl << "Done" <<endl;
  
        cout<<"Enter the No. of Red values"<<endl;
        cin>>D;

	     cout<<"Enter the No. of allowed Red values"<<endl;
       	cin>>K;
 if(K<=D)
{
	
  
  while (p<D-1) {
  memset(nv, 0, sizeof(nv));
    for ( i = 0; i < D; i++) {
       cout<<"Enter the "<<(i+1)<<" intensitY value:"<<endl;
       cin>>R;
       cout<<"Enter it's number of pixels "<<endl;
       cin>>P;

      nv[R] += P;
    }

    for ( v = 0; v <= 256; v++)
    for ( i = 0; i < 256; i++) {
      cumsum[v][i+1] = cumsum[v][i] + (v-i)*(v-i)*nv[i];
    }

    
  
   memset(memo, -1, sizeof(memo));
	cout<<setw(40)<<"The sum of squared erros is:"<<endl;
     count = 0;
    cout <<"Loading";
    for(count;count < 3; ++count){
        cout << ". " ;
        fflush(stdout);
        sleep(1);
    }
    
cout <<doit(0, K, 0) << endl;
    p++;
  }
}
else
  cout<<"the value of allowed pixels must be less than or equal to available !"<<endl;

  return 0;
}
