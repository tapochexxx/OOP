/*Среди столбцов заданной матрицы,
содержащих только такие элементы, которые по модулю не больше заданного натурального n,
найти столбец с минимальным произведением элементов*/

#include <iostream> 
#include <vector> 
#include <limits.h>

using namespace std;

void showMatrix(vector<vector<int>> matrix) // ôóíêöèÿ âûâîäà ìàòðèöû íà ýêðàí 

{
    for (int i = 0; i < matrix.size(); i++)
    {                    
        for (int j = 0; j < matrix[i].size(); j++) 
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

void randMatrix(vector<vector<int>>& matrix, int columns, int n) // ôóíêöèÿ èíèöèàëèçàöèè ìàòðèöû ñëó÷àéíûìè ÷èñëàìè 
{
    for (int i = 0; i < matrix.size(); i++) {                   
        for (int j = 0; j < matrix[i].size(); j++) { 
            matrix[i][j] = rand() % columns;
            if (matrix[i][j] > n||matrix[i][j]==0) matrix[i][j] = 1;
        }
    }
}

int findMinColumn(vector<vector<int>>& matrix) { // ôóíêöèÿ íàõîäÿùàÿ ñòîëáåö ñ ìèíèìàëüíûì ïðîèçâåäåíèåì ýëåìåíòîâ
    int minMultiple = INT_MAX, counter = 0;
    for (int i = 0; i < matrix.size(); i++) { 
        int multiple = 1;
        for (int j = 0; j < matrix[i].size(); j++)  multiple *= matrix[j][i];  
            
        if (multiple < minMultiple) {
            minMultiple = multiple;
            counter = i;
        }
        
    }

    return counter;
}

int main()
{
    int rows, columns, n;

    cout << "Give rows = "; cin >> rows;
    cout << "Give columns = "; cin >> columns;
    cout << "Give n = "; cin >> n;

    vector<vector<int>> matrix(rows, vector <int>(columns)); // Îáúÿâëåíèå ìàòðèöû íà n ñòðîê ïî m ýëåìåíòîâ
    randMatrix(matrix, columns, n);  // èíèöèàëèçàöèÿ 
    showMatrix(matrix);  // âûâîä ìàòðèöû 
    cout << "Column with lowest multiple - " << findMinColumn(matrix)+1;
        
    return 0;
}
