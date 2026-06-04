// s[10]처럼 사용
// 해당 항목을 참조자(reference) 로 반환

int& operator[](int index) {
    return list[index];
}