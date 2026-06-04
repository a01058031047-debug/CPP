// s(10)처럼 사용
// (1)과 동일하게 참조자 반환

int& operator()(int index) {
    return list[index];
}