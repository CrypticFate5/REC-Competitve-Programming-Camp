#include <stdio.h>

void seiveHelp(int*seive,int n,int tempn,int*primes,int*primesCount){
    for(int i=2;i<n;i++){
        if(seive[i]){
            if(i<=tempn) {primes[*primesCount]=i;
            *primesCount=*primesCount+1;}
            for(int j=i*i;j<n;j++) seive[j]=0;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int seive[(n+1)*100],primes[100],primesCount=0;
    memset(seive,1,sizeof(seive));
    seiveHelp(seive,(n+1)*100,int tempn,primes,&primesCount);
    
}