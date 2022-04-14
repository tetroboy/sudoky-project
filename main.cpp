#include <iostream>
#include <vector>

using namespace std;
const int N = 9;
class A{
    private:
        vector<char> posible;
    public:
        void setVector(char c){
            posible.push_back(c);
        }
        vector<char> getVector(){
            return posible;
        }
        void ClearVector(){
            posible.clear();
        }
};

int main(){
    int row, column;
    char arr[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = ' ';
        }
    }
    char c = '1';
    char value;
    while(1){
        cout << "continue input press 1 to finish press another key ";
        cin >> c;
        if(c != '1') break;
        cout << "input row ";
        cin >> row;
        cout << "input column ";
        cin >> column;
        cout << "input value ";
        cin >> value;
        arr[row][column] = value;
    }
    int tre = 0;
    while(tre < 10){

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << '|' << arr[i][j] ;
        }
        cout << endl;
    }
    A Posibl[N][N];
    int flag;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(arr[i][j] == ' '){
                int rowindex = 0;
                int columnindex = 0;
                char value = '1';

                while(value <= '9'){
                while(rowindex < N){
                    if(arr[rowindex][j] == value){
                                flag = 0;
                                break;
                            }
                            else flag = 1;
                            rowindex++;
                        }
                if(flag == 1){
                    while(columnindex < N){

                            if(arr[i][columnindex] == value){
                                flag = 0;
                                break;
                            }
                            else flag = 1;
                            columnindex++;
                        }
                }


                rowindex = 0;
                columnindex = 0;
                if(flag == 1){
                while(rowindex < N){
                    while(columnindex < N){
                        if(i / 3 == rowindex / 3 && j / 3 == columnindex / 3){
                            if(arr[rowindex][columnindex] == value){
                                flag = 0;
                                break;
                            }
                            else flag = 1;
                        }
                        columnindex++;
                     }
                     columnindex = 0;
                     rowindex++;
                     if(flag == 0) break;
                     }}

                                 if( flag == 1 ){
                                    Posibl[i][j].setVector(value);
                                }
                      value++;
                }


            }
        }
    }
    //vector <int>::size_type sz;
    vector<char>::pointer c1_ptr;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(arr[i][j] == ' '){
                if(Posibl[i][j].getVector().size( ) == 1){
                    c1_ptr = Posibl[i][j].getVector().data( );
                    arr[i][j] = *c1_ptr;
                }
            }
        }
    }

      cout << endl;
      cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << '|' << arr[i][j];
        }
        cout << endl;
    }

    cout << endl << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(arr[i][j] == ' '){
                Posibl[i][j].ClearVector();
            }
        }
    }
    tre++;
    }

}
