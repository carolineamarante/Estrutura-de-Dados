#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

// Funções de ordenação
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void quicksort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (v[j] <= pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[i + 1], v[high]);
        int partitionIndex = i + 1;

        quicksort(v, low, partitionIndex - 1);
        quicksort(v, partitionIndex + 1, high);
    }
}

void mergesort(vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(v, left, mid);
        mergesort(v, mid + 1, right);

        // Mesclando os dois vetores
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> leftArray(n1), rightArray(n2);

        for (int i = 0; i < n1; i++) {
            leftArray[i] = v[left + i];
        }

        for (int j = 0; j < n2; j++) {
            rightArray[j] = v[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                v[k] = leftArray[i];
                i++;
            } else {
                v[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            v[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2) {
            v[k] = rightArray[j];
            j++;
            k++;
        }
    }
}

int main() {
    // Inicializa o gerador de números aleatórios
    default_random_engine rng(static_cast<unsigned>(time(nullptr)));
    uniform_int_distribution<int> dist(0, 100); // Valores entre 0 e 100

    // Cria o vetor de tamanhos
    vector<int> tamanhos;
    tamanhos.push_back(100);
    tamanhos.push_back(1000);
    tamanhos.push_back(10000);
    tamanhos.push_back(100000);

    // Loop para cada tamanho de vetor
    for (size_t i = 0; i < tamanhos.size(); i++) {
        int tamanho = tamanhos[i];

        // Gerar um vetor com valores aleatórios
        vector<int> vOriginal(tamanho);
        for (int i = 0; i < tamanho; i++) {
            vOriginal[i] = dist(rng);
        }

        cout << "Tamanho do vetor: " << tamanho << endl;

        // Copiar o vetor original para ser ordenado por cada algoritmo
        vector<int> v;

        // Bubble Sort
        v = vOriginal;
        clock_t inicio = clock();
        bubbleSort(v);
        clock_t fim = clock();
        double tempoBubbleSort = double(fim - inicio) / CLOCKS_PER_SEC;
        cout << "Tempo de Bubble Sort: " << tempoBubbleSort << " segundos" << endl;

        // Selection Sort
        v = vOriginal;
        inicio = clock();
        selectionSort(v);
        fim = clock();
        double tempoSelectionSort = double(fim - inicio) / CLOCKS_PER_SEC;
        cout << "Tempo de Selection Sort: " << tempoSelectionSort << " segundos" << endl;

        // Insertion Sort
        v = vOriginal;
        inicio = clock();
        insertionSort(v);
        fim = clock();
        double tempoInsertionSort = double(fim - inicio) / CLOCKS_PER_SEC;
        cout << "Tempo de Insertion Sort: " << tempoInsertionSort << " segundos" << endl;

        // Quick Sort
        v = vOriginal;
        inicio = clock();
        quicksort(v, 0, tamanho - 1);
        fim = clock();
        double tempoQuickSort = double(fim - inicio) / CLOCKS_PER_SEC;
        cout << "Tempo de Quick Sort: " << tempoQuickSort << " segundos" << endl;

        // Merge Sort
        v = vOriginal;
        inicio = clock();
        mergesort(v, 0, tamanho - 1);
        fim = clock();
        double tempoMergeSort = double(fim - inicio) / CLOCKS_PER_SEC;
        cout << "Tempo de Merge Sort: " << tempoMergeSort << " segundos" << endl;

        cout << endl; // Separador entre tamanhos
    }

    return 0;
}
