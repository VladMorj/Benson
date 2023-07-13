#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <cmath>

using namespace std;

///dH
void alkan_dH(int m[][5], int stop) ///функция принимает указатель на составленный по введенным данным двумерный массив и количество молекул для рассчета и рассчитывает энтальпийный вклад в свойства для алканов
{
    int num = 1;
    double c[5]={-42.19, -20.64, -7.95, 2.09, 3.35}; /// Парциальный вклад 1 вида взаимодействия
    cout << "Энтальпия образования (dHf, кДж/моль)" << endl;  ///Суммарный вклад в энтальпия образования
    for(int i = 0; i<stop; ++i){
        double *sum = new double(0);  ///выделение памяти для переменной - счетчика (будет освобождена на каждой итерации внешнего цикла)
        double *pc = new double[5];   ///выделение памяти под массив куда будет записан вклад каждого вида взаимодействий (массив будет освобожден из кучи и определен заново на каждой итерации внешнго цикла)
        for(int j =0; j < 5; ++j){
            pc[j]=((m[i][j]) * (c[j]));
            *sum = *sum + pc[j];
        }
        cout << num << ". dHf = " << *sum << "кДж/моль" << endl;
        num++;
        delete[]pc;
        delete sum;
    }
}

///dH
void cyclo_dH(unsigned *m)
{
    double sum = 0;
    double c[5]={-42.19, -20.64, -7.95, 3.35, 67.48};
    double pc[5];
    cout << "Enthalpy of formation (dHf,kDj/mol)= ";
    for(int i = 0; i<5; ++i){
        pc[i]=((m[i])*(c[i]));
        sum = sum + pc[i];
        if(i == 4){
            cout <<pc[i] << " = ";
        }
        else{
            cout <<pc[i] << " + ";
        }
    }
    cout << sum << endl;
}

///dH
void alken_dH(unsigned *m)
{
    double sum = 0;
    double c[7]={-20.64, -7.95, 35.96, 67.48, 4.184, 3.35, 2.09};
    double pc[7];
    cout << "Enthalpy of formation (dHf,kDj/mol)= ";
    for(int i = 0; i<7; ++i){
        pc[i]=((m[i])*(c[i]));
        sum = sum + pc[i];
        if(i == 6){
            cout <<pc[i] << " = ";
        }
        else{
            cout <<pc[i] << " + ";
        }
    }
    cout << sum << endl;
}

///dS
void alkan_dS(unsigned *m, double ext_corr, double int_corr)
{
    double pre_simm_corr = 0;
    double simm_corr = 0;
    double sum = 0;
    double R = 8.314;
    double c1[4]={127.24, 39.41, -50.50, -146.86};
    double pc[4];
    cout << "Энтропия образования (dSf,Дж/моль*К)= ";
    for(int i = 0; i<4; ++i){
        pc[i]=((m[i]) * (c1[i]));
        sum = sum + pc[i];
        if(i == 3){
            cout <<pc[i] << " = ";
        }
        else{
            cout << pc[i] << " + ";
        }
    }
    cout << sum << " " "Дж/моль*К" <<endl;
    if(ext_corr==0){
        pre_simm_corr = int_corr;
        cout << endl << "Поправка на симметрию молекулы (Дж/моль*К):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "Результирующая энтропия (Дж/моль*К):" << sum+simm_corr << endl;
    }
    else if(int_corr==0){
        pre_simm_corr = ext_corr;
        cout << endl << "Поправка на симметрию молекулы (Дж/моль*К):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "Результирующая энтропия (Дж/моль*К):" << sum+simm_corr << endl;
    }
    else{
        cout << sum << "Дж/моль*К" <<endl;
        pre_simm_corr = ext_corr*int_corr;
        cout << endl << "Поправка на симметрию молекулы (Дж/моль*К):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = (-R*(log(pre_simm_corr)));
        cout << endl << "Результирующая энтропия (Дж/моль*К):" << sum+simm_corr << endl;
    }
}
///dS
void cyclo_dS(unsigned *m, double ext_corr, double int_corr)
{
    double pre_simm_corr = 0;
    double simm_corr = 0;
    double sum = 0;
    double R = 8.314;
    double c1[3]={127.24, 39.41, -50.50};
    double pc[4];
    cout << "Энтропия образования (dSf,Дж/моль*К)= ";
    for(int i = 0; i<3; ++i){
        pc[i]=((m[i]) * (c1[i]));
        sum = sum + pc[i];
        if(i == 2){
            cout <<pc[i] << " = ";
        }
        else{
            cout << pc[i] << " + ";
        }
    }
    cout << sum << " " "Дж/моль*К" <<endl;
    if(ext_corr==0){
        pre_simm_corr = int_corr;
        cout << endl << "Поправка на симметрию молекулы (Дж/моль*К):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "Результирующая энтропия (Дж/моль*К):" << sum+simm_corr << endl;
    }
    else if(int_corr==0){
        pre_simm_corr = ext_corr;
        cout << endl << "Поправка на симметрию молекулы (Дж/моль*К):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "Результирующая энтропия (Дж/моль*К):" << sum+simm_corr << endl;
    }
    else{
        pre_simm_corr = ext_corr*int_corr;
        cout << endl << "Поправка на симметрию молекулы (Дж/моль*К):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = (-R*(log(pre_simm_corr)));
        cout << endl << "Результирующая энтропия (Дж/моль*К):" << sum+simm_corr << endl;
    }
}


int main()
{
    setlocale(0, "Russian");

    int b = 0;
    double x = 0;
    double n = 0;
    double x1 = 0;
    double n1 = 0;
    double ext_corr = 0;
    double int_corr = 0;
    cout << "\t" "(используйте цифры 1, 2, 3.. для управления)" << endl << endl <<"Выберите опцию:" << endl;
    cout << "1. Расчет стандартной энтальпии образования (dHf, кДж/моль);" << endl << "2. Расчет стандартной энтропии образования (dSf, Дж/моль*К);" << endl << "3. Расчет теплоемкости (C, Dj/K)" << endl;
    cin >> b;
    if(b == 1){
        int a = 0;
        cout << "Выберете класс органической молекулы:" << endl;
        cout << "1. Алканы;" << endl << "2. Циклоалканы (тестируется);" << endl << "3. Алкены (тестируется)." << endl;
        cin >> a;
        if(a == 1){
            int stop = 0;
            cout << "Количество молекул:" << endl;
            cin >> stop;
            int m[stop][5];
            for(int i = 0; i<stop; ++i){
                for(int j = 0; j<5;){
                    cout << "Количество первичных атомов CH3-(C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "Количество вторичных атомов CH2-(2C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "Количество третичных атомов CH-(3C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "Количество четвертичных атомов C-(4C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "Количество 'гош' взаимодействий заместителей:" << endl;
                    cin >> m[i][j];
                    j++;
                }
            }
            alkan_dH(m, stop);
        }
        else if(a == 2){
            unsigned c1[5];
            cout << "Количество первичных атомов CH3-(C):" << endl;
            cin >> c1[0];
            cout << "Количество вторичных атомов CH2-(2C):" << endl;
            cin >> c1[1];
            cout << "Количество третичных атомов CH-(3C):" << endl;
            cin >> c1[2];
            cout << "Количество 'Гош' взаимодействий:" << endl;
            cin >> c1[3];
            cout << "Количество моментов (точек) напряжений цикла:" << endl;
            cin >> c1[4];
            cyclo_dH(c1);
        }
        else if(a == 3){
            unsigned c1[7];
            cout << "Количество вторичных атомов CH2-(2C):" << endl;
            cin >> c1[0];
            cout << "Количество третичных атомов CH-(3C):" << endl;
            cin >> c1[1];
            cout << "Number of =CH-(C):" << endl;
            cin >> c1[2];
            cout << "Количество моментов (точек) напряжений цикла:" << endl;
            cin >> c1[3];
            cout << "Количество 'цис' взаимодействий:" << endl;
            cin >> c1[4];
            cout << "Количество алкан-алкан 'Гош' взаимодействий:" << endl;
            cin >> c1[5];
            cout << "Количество алкен-алкен 'Гош' взаимодействий:" << endl;
            cin >> c1[6];
            alken_dH(c1);
        }
    }
    else if(b == 2){
        int a = 0;
        int rol = 0;
        int rol2 = 0;
        cout << "Выберете класс органической молекулы:" << endl;
        cout << "1. Алканы;" << endl << "2. Циклоалканы (Тестируется);" << endl << "3. Алкены (Тестируется)."<< endl;
        cin >> a;
        if(a == 1){
            unsigned c[5];
            cout << "Количество первичных атомов CH3-(C):" << endl;
            cin >> c[0];
            cout << "Количество вторичных атомов CH2-(2C):" << endl;
            cin >> c[1];
            cout << "Количество третичных атомов CH-(3C):" << endl;
            cin >> c[2];
            cout << "Количество четвертичных атомов C-(4C):" << endl;
            cin >> c[3];
            cout << "Присутствует внешнее вращение молекулы?" << endl << "1. Да" << endl << "2. Нет" << endl;
            cin >> rol;
            if(rol == 1){
                cout << "Количество осей вращения (n)" << endl;
                cin >> n;
                cout << "Количество повторений молекулы при вращении вдоль оси (x)" << endl;
                cin >> x;
                ext_corr = pow(n, x);
            }
            else if(rol == 2){

            }
            else {
                cout << "Incorrect input, use only 1 and 2 for choise" << endl;
            }
            cout << "Присутствует внутренее вращение молекулы?" << endl << "1. Да" << endl << "2. Нет" << endl;
            cin >> rol2;
            if(rol2 == 1){
                cout << "Количество осей вращения (n)" << endl;
                cin >> n1;
                cout << "Количество повторений молекулы при вращении вдоль оси (x)" << endl;
                cin >> x1;
                int_corr = pow(n1, x1);
            }
            else if(rol2 == 2){

            }
            else{
                cout << "Incorrect input, use only 1 and 2 for choise" << endl;
            }
            alkan_dS(c, ext_corr, int_corr);///
        }/////
        else if(a == 2){
            unsigned c[3];
            cout << "Number of CH3-(C):" << endl;
            cin >> c[0];
            cout << "Number of CH2-(2C):" << endl;
            cin >> c[1];
            cout << "Number of CH-(3C):" << endl;
            cin >> c[2];

            cout << "Есть внешнее вращение молекулы?" << endl << "1. Да" << endl << "2. Нет" << endl;
            cin >> rol;
            if(rol == 1){
                cout << "Количество осей вращения (n)" << endl;
                cin >> n;
                cout << "Количество повторений молекулы при вращении вдоль оси (x)" << endl;
                cin >> x;
                ext_corr = pow(n, x);
            }
            else if(rol == 2){

            }
            else {
                cout << "Incorrect input, use only 1 and 2 for choise" << endl;
            }
            cout << "Есть внутренее вращение молекулы?" << endl << "1. Да" << endl << "2. Нет" << endl;
            cin >> rol2;
            if(rol2 == 1){
                cout << "Количество осей вращения (n)" << endl;
                cin >> n1;
                cout << "Количество повторений молекулы при вращении вдоль оси (x)" << endl;
                cin >> x1;
                int_corr = pow(n1, x1);
            }
            else if(rol2 == 2){

            }
            else{
                cout << "Incorrect input, use only 1 and 2 for choise" << endl;
            }
            cyclo_dS(c, ext_corr, int_corr);
        }
        else if(a == 3){
            unsigned c1[5];
            cout << "Number of CH2-(2C):" << endl;
            cin >> c1[0];
            cout << "Number of CH-(3C):" << endl;
            cin >> c1[2];
            cout << "Number of 'gauche' interactions:" << endl;
            cin >> c1[3];
            cout << "Cycle stress corr:" << endl;
            cin >> c1[4];

        }
    }
    return 0;
}
