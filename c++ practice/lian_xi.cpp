#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<sstream>
#include<map>
using namespace std;
bool is_leap(int year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int date(int year , int month , int day){
    int days[13] ={0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
    if(is_leap(year)){
        days[2] =29;
    }
    int sum = 0;
    for(int i = 1 ; i < month ; i++){
        sum += days[i];
    }
    for(int i = 0 ; i< year ; i++){
        sum += 365 + is_leap(i);
    }
    return sum + day;
}
bool is_valid(int year, int month ,int day){
    if(year > 99 || month < 1 || month > 12 || day < 1 || day > 31){
        return false;
    }
    return true;
}
int main(){
    int a,b,c;
    char d ,e;

    while(cin >> a >> d >> b >> e >> c){
    if(a == 0 && b == 0 && c == 0){
        break;
    }
    string months[13] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
    bool valid1 = is_valid(c,a,b);
    bool valid2 = is_valid(a,b,c);
    if(valid1 && !valid2){
        cout<<months[a]<<" "<<b<<", "<<c+2000<<endl;

    }
    else if(!valid1 && valid2){
        cout<<months[b]<<" "<<c<<", "<<a+2000<<endl;
    } 
    else{
        int date1 = date(c,a,b);
        int date2 = date(a,b,c);
        cout<<abs(date1 - date2)<<endl;
    }
    }
}