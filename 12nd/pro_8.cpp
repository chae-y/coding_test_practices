using namespace std;

string solution(int a, int b) {
    string week[7]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month[13]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 0;
    for(int i=1; i<a; i++){
        day+=month[i];   
    }
    day+=b;
    int result = (day+4)%7;
    return week[result];
}