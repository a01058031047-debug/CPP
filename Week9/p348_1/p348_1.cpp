
// 초기화 리스트 사용
MyTime(int h=0, int m=0, int s=0, int ms=0)
    : hour(h), minute(m), second(s), millisecond(ms) {}

// 초기화 리스트 사용하지 않음
    MyTime(int h=0, int m=0, int s=0, int ms=0) {
    hour = h;
    minute = m;
    second = s;
    millisecond = ms;
}