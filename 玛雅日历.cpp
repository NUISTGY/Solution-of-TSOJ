#include <iostream>
#include <string>
using namespace std;

void fun(int *nCases){
    char month1[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    char month2[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    int i,m;
    for(i=0;i<*nCases;i++){
        int day,year,dates;
        char month[10];
		cin >> day >> month >> year;
        for(m=0;m<19;m++)
            if(!strcmp(month1[m], month))break;
        dates=year*365+m*20+day;
        printf("%d %s %d\n",1+dates%13,month2[dates%20],dates/260);
    }
}

int main(){
    int nCases;
    cin>>nCases;
    fun(&nCases);
    return 0;
}

