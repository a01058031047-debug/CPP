// 함수 호출 연산자 () 중복
// 두 정수 입력
// 두 수의 곱을 인덱스로 사용
// (1)과 동일하게 참조자 반환

int& operator()(int a, int b) {
    return list[a * b];
}