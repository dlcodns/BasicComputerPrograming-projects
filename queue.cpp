//template으로 만든 큐

#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

template <typename T>
class queue
{
    T* arr;         // Queue 요소를 저장할 어레이.
    int count;      // Queue의 현재 크기

public:
    queue(int size = SIZE);    

    T newMember();          //새로운 자료를 입력하는 유틸리티함수
    void deletequeue();     //앞 값을 삭제하는 유틸리티함수
    void addqueue(T x);     //새로운 자료를 저장하는 유틸리티함수
    int size();             //현재 size를 알려주는 유틸리티함수
    bool isEmpty();         //큐가 비어있는지 확인하는 유틸리티함수
    bool isFull();          //큐가 가득 찼는지 확인하는 유틸리티함수
    bool isover();          //큐가 넘쳤는지 확인하는 유틸리티함수
};

// Queue를 초기화하는 생성자
template <typename T>
queue<T>::queue(int size)
{
    arr = new T[size];
    count = 0;      //채워진 배열의 크기 카운트
}

template <typename T>
T queue<T>::newMember()                 //새로운 자료를 입력하는 유틸리티함수
{       
    T mem;

    cout << "Queue에 넣을 자료를 입력하세요. >> ";
    cin >> mem;

    if (mem.compare("delete") == 0)     //mem이 delete일 때 맨 앞 값 삭제
        this->deletequeue();

    return mem;
}

template <typename T>
void queue<T>::deletequeue()            //앞 값을 삭제하는 유틸리티함수
{
    if (isEmpty())                      //언더플로일 때 종료
    {
        cout << "\nUnderflow\n";
        exit(EXIT_FAILURE);
    }
    else {                              //arr[0] 제거
        cout << "   " << arr[0] << " 제거    ";

        for (int i = 0; i < 10; i++) {
            arr[i] = arr[i + 1];        //뒷 배열 앞으로 보내기
        }
        count--;                        //배열 개수 -1 

        cout << "|";
        for (int i = 0; i < 10; i++) {
            cout << arr[i] << "|";
        }
        cout << endl << endl;
    }
}

template <typename T>
void queue<T>::addqueue(T item)         //새로운 자료를 저장하는 유틸리티함수
{
    arr[count] = item;                  //자료를 큐에 추가
    count++;                            //큐 크기 증가
    cout << "   " << item << " 추가    ";

    cout << "|";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "|";
    }
    cout << endl << endl;

}

template <typename T>
int queue<T>::size()                    //현재 size를 알려주는 유틸리티함수
{                  
    return count;
}

template <typename T>                   //큐가 비어있는지 확인하는 유틸리티함수
bool queue<T>::isEmpty()
{
    return (size() == 0);               
}

template <class T>                      //큐가 가득 찼는지 확인하는 유틸리티함수
bool queue<T>::isFull() 
{               
    return (size() == 10);
}

template <class T>                      //큐가 넘쳤는지 확인하는 유틸리티함수
bool queue<T>::isover() 
{
    return (size() == 11);
}

int main()
{
    // 용량이 11인 Queue 생성 (11인덱스 값을 10으로 보내기 위해서)
    queue<string> q(11);

    cout << "맨 앞 Queue를 빼고 싶으면 delete를 쓰세요.\n\n";

    while (!q.isover()) {                   //큐가 넘치지 않았을 때 반복
        string mem = q.newMember();
        if (mem.compare("delete") != 0)     //mem이 delete가 아닐 때 추가함수 호출
            q.addqueue(mem);
        if (q.isEmpty()) {                  
            cout << "   Queue가 비어있습니다.\n\n";
        }
        if (q.isFull())
        {
            cout << "   Queue가 전부 채워져 있습니다.\n\n";
        }
    }
    if (q.isover())                     //큐가 넘치면 오버플로우 종료
    {
        cout << "   Overflow\n";
        exit(EXIT_FAILURE);
    }
    return 0;
}
