Sample2* arr[4];


// 상속관계:
Sample1
 ├─ Sample2
 ├─ Sample3
 └─ Sample4

Sample2* p = new Sample3(); // 불가능
Sample2* p = new Sample4(); // 불가능


//또한
arr[0] = a;   // Sample1* → Sample2*



따라서 컴파일 오류