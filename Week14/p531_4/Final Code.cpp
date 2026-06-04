class SampleList{
    int list[100];

public:
    SampleList() {
        for(int x = 0; x < 100; x++){
            list[x] = rand() % 1000;
        }
    }

    // (1)
    int& operator[](int index) {
        return list[index];
    }

    // (2)
    int& operator()(int index) {
        return list[index];
    }

    // (3)
    int& operator()(int a, int b) {
        return list[a * b];
    }
};