#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

struct WordPair
{
    string eng;
    string kor;
};

// (2) MyDic 클래스
class MyDic
{
    WordPair words[MAXWORDS];
    int nWords;

public:
    
    MyDic() 
    {
        nWords = 0;
    }

    void add(string eng, string kor)
    {
        if (nWords >= MAXWORDS)
        {
            cout << "단어장이 가득 찼습니다.\n";
            return;
        }
        words[nWords].eng = eng;
        words[nWords].kor = kor;
        nWords++;
    }

    void load(string filename)
    {
        ifstream fin(filename);
        if (!fin)
        {
            cout << "파일을 열 수 없습니다.\n";
            return;
        }

        nWords = 0;
        string eng, kor;

        while (fin >> eng >> kor) {
            add(eng, kor);
        }

        fin.close();
    }

    void store(string filename)
    {
        ofstream fout(filename);
        if (!fout)
        {
            cout << "파일을 생성할 수 없습니다.\n";
            return;
        }

        for (int i = 0; i < nWords; i++)
        {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    void print()
    {
        for (int i = 0; i < nWords; i++)
        {
            cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
        }
    }

    string getEng(int id)
    {
        if (id < 0 || id >= nWords) return "";
        return words[id].eng;
    }

    string getKor(int id)
    {
        if (id < 0 || id >= nWords) return "";
        return words[id].kor;
    }
};

// (3) main 함수 (테스트)
int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("grape", "포도");

    cout << "현재 단어장:\n";
    dic.print();

    dic.store("dic.txt");

    MyDic dic2;
    dic2.load("dic.txt");

    cout << "\n파일에서 읽은 단어장:\n";
    dic2.print();

    cout << "\n0번째 영어: " << dic2.getEng(0) << endl;
    cout << "0번째 뜻: " << dic2.getKor(0) << endl;

    return 0;
}