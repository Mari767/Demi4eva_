#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
#define N 5
#define P 101

void Child(int arr[], int n, int i);
void heapSort(int arr[], int n);
class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration< double, ratio<1> >;

    chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int main() {
    
    double p;
    int n = N;
    int i;
    setlocale(LC_ALL, "RU");
    int arr[N];
    double time[P];

    for (int u = 0; u < P; u++) {

        //cout << "Упорядоченный массив: " << endl;
        for (i = 0; i < N; i++) {
            arr[i] = i + 1;
        }

        auto start = chrono::high_resolution_clock::now();
        heapSort(arr, n); //вызов функции сортировки
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;



        ////cout << "\nМассив, упорядоченный в обратном порядке: " << endl;
        //for (i = 0; i < N; i++) {//ввод массива
        //	arr[i] = N - i;
        //}
        //auto start = chrono::high_resolution_clock::now();
        //heapSort(arr, n); //вызов функции сортировки
        //auto end = chrono::high_resolution_clock::now(); 
        //chrono::duration<double> duration = end - start;



        ////cout << "\nНеотсортированный массив: " << endl;
        //for (i = 0; i < N; i++) {//ввод массива
        //	arr[i] = rand() % 100 - 30;
        //}
        //auto start = chrono::high_resolution_clock::now();
        //heapSort(arr, n); //вызов функции сортировки
        //auto end = chrono::high_resolution_clock::now();
        //chrono::duration<double> duration = end - start;

        time[u] = duration.count();;
        cout << u << "   " << time[u] << endl;
    }
    double sum = 0;
    double result;
    for (int u = 1; u < P; u++) {
        sum += time[u];
    }
    cout << "Sum" << sum << endl;
    result = sum / (P - 1);
    cout << "Result " << result << endl;

}

void Child(int arr[], int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Child(arr, n, largest);
    }
    return;
}

void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        Child(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        Child(arr, i, 0);
    }
    return;
}



