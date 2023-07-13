#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <cmath>

using namespace std;

///dH
void alkan_dH(int m[][5], int stop) ///������� ��������� ��������� �� ������������ �� ��������� ������ ��������� ������ � ���������� ������� ��� �������� � ������������ ������������ ����� � �������� ��� �������
{
    int num = 1;
    double c[5]={-42.19, -20.64, -7.95, 2.09, 3.35}; /// ����������� ����� 1 ���� ��������������
    cout << "��������� ����������� (dHf, ���/����)" << endl;  ///��������� ����� � ��������� �����������
    for(int i = 0; i<stop; ++i){
        double *sum = new double(0);  ///��������� ������ ��� ���������� - �������� (����� ����������� �� ������ �������� �������� �����)
        double *pc = new double[5];   ///��������� ������ ��� ������ ���� ����� ������� ����� ������� ���� �������������� (������ ����� ���������� �� ���� � ��������� ������ �� ������ �������� ������� �����)
        for(int j =0; j < 5; ++j){
            pc[j]=((m[i][j]) * (c[j]));
            *sum = *sum + pc[j];
        }
        cout << num << ". dHf = " << *sum << "���/����" << endl;
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
    cout << "�������� ����������� (dSf,��/����*�)= ";
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
    cout << sum << " " "��/����*�" <<endl;
    if(ext_corr==0){
        pre_simm_corr = int_corr;
        cout << endl << "�������� �� ��������� �������� (��/����*�):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "�������������� �������� (��/����*�):" << sum+simm_corr << endl;
    }
    else if(int_corr==0){
        pre_simm_corr = ext_corr;
        cout << endl << "�������� �� ��������� �������� (��/����*�):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "�������������� �������� (��/����*�):" << sum+simm_corr << endl;
    }
    else{
        cout << sum << "��/����*�" <<endl;
        pre_simm_corr = ext_corr*int_corr;
        cout << endl << "�������� �� ��������� �������� (��/����*�):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = (-R*(log(pre_simm_corr)));
        cout << endl << "�������������� �������� (��/����*�):" << sum+simm_corr << endl;
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
    cout << "�������� ����������� (dSf,��/����*�)= ";
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
    cout << sum << " " "��/����*�" <<endl;
    if(ext_corr==0){
        pre_simm_corr = int_corr;
        cout << endl << "�������� �� ��������� �������� (��/����*�):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "�������������� �������� (��/����*�):" << sum+simm_corr << endl;
    }
    else if(int_corr==0){
        pre_simm_corr = ext_corr;
        cout << endl << "�������� �� ��������� �������� (��/����*�):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = -R*(log(pre_simm_corr));
        cout << endl << "�������������� �������� (��/����*�):" << sum+simm_corr << endl;
    }
    else{
        pre_simm_corr = ext_corr*int_corr;
        cout << endl << "�������� �� ��������� �������� (��/����*�):" << -R*(log(pre_simm_corr)) << endl;
        simm_corr = (-R*(log(pre_simm_corr)));
        cout << endl << "�������������� �������� (��/����*�):" << sum+simm_corr << endl;
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
    cout << "\t" "(����������� ����� 1, 2, 3.. ��� ����������)" << endl << endl <<"�������� �����:" << endl;
    cout << "1. ������ ����������� ��������� ����������� (dHf, ���/����);" << endl << "2. ������ ����������� �������� ����������� (dSf, ��/����*�);" << endl << "3. ������ ������������ (C, Dj/K)" << endl;
    cin >> b;
    if(b == 1){
        int a = 0;
        cout << "�������� ����� ������������ ��������:" << endl;
        cout << "1. ������;" << endl << "2. ����������� (�����������);" << endl << "3. ������ (�����������)." << endl;
        cin >> a;
        if(a == 1){
            int stop = 0;
            cout << "���������� �������:" << endl;
            cin >> stop;
            int m[stop][5];
            for(int i = 0; i<stop; ++i){
                for(int j = 0; j<5;){
                    cout << "���������� ��������� ������ CH3-(C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "���������� ��������� ������ CH2-(2C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "���������� ��������� ������ CH-(3C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "���������� ������������ ������ C-(4C):" << endl;
                    cin >> m[i][j];
                    j++;
                    cout << "���������� '���' �������������� ������������:" << endl;
                    cin >> m[i][j];
                    j++;
                }
            }
            alkan_dH(m, stop);
        }
        else if(a == 2){
            unsigned c1[5];
            cout << "���������� ��������� ������ CH3-(C):" << endl;
            cin >> c1[0];
            cout << "���������� ��������� ������ CH2-(2C):" << endl;
            cin >> c1[1];
            cout << "���������� ��������� ������ CH-(3C):" << endl;
            cin >> c1[2];
            cout << "���������� '���' ��������������:" << endl;
            cin >> c1[3];
            cout << "���������� �������� (�����) ���������� �����:" << endl;
            cin >> c1[4];
            cyclo_dH(c1);
        }
        else if(a == 3){
            unsigned c1[7];
            cout << "���������� ��������� ������ CH2-(2C):" << endl;
            cin >> c1[0];
            cout << "���������� ��������� ������ CH-(3C):" << endl;
            cin >> c1[1];
            cout << "Number of =CH-(C):" << endl;
            cin >> c1[2];
            cout << "���������� �������� (�����) ���������� �����:" << endl;
            cin >> c1[3];
            cout << "���������� '���' ��������������:" << endl;
            cin >> c1[4];
            cout << "���������� �����-����� '���' ��������������:" << endl;
            cin >> c1[5];
            cout << "���������� �����-����� '���' ��������������:" << endl;
            cin >> c1[6];
            alken_dH(c1);
        }
    }
    else if(b == 2){
        int a = 0;
        int rol = 0;
        int rol2 = 0;
        cout << "�������� ����� ������������ ��������:" << endl;
        cout << "1. ������;" << endl << "2. ����������� (�����������);" << endl << "3. ������ (�����������)."<< endl;
        cin >> a;
        if(a == 1){
            unsigned c[5];
            cout << "���������� ��������� ������ CH3-(C):" << endl;
            cin >> c[0];
            cout << "���������� ��������� ������ CH2-(2C):" << endl;
            cin >> c[1];
            cout << "���������� ��������� ������ CH-(3C):" << endl;
            cin >> c[2];
            cout << "���������� ������������ ������ C-(4C):" << endl;
            cin >> c[3];
            cout << "������������ ������� �������� ��������?" << endl << "1. ��" << endl << "2. ���" << endl;
            cin >> rol;
            if(rol == 1){
                cout << "���������� ���� �������� (n)" << endl;
                cin >> n;
                cout << "���������� ���������� �������� ��� �������� ����� ��� (x)" << endl;
                cin >> x;
                ext_corr = pow(n, x);
            }
            else if(rol == 2){

            }
            else {
                cout << "Incorrect input, use only 1 and 2 for choise" << endl;
            }
            cout << "������������ ��������� �������� ��������?" << endl << "1. ��" << endl << "2. ���" << endl;
            cin >> rol2;
            if(rol2 == 1){
                cout << "���������� ���� �������� (n)" << endl;
                cin >> n1;
                cout << "���������� ���������� �������� ��� �������� ����� ��� (x)" << endl;
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

            cout << "���� ������� �������� ��������?" << endl << "1. ��" << endl << "2. ���" << endl;
            cin >> rol;
            if(rol == 1){
                cout << "���������� ���� �������� (n)" << endl;
                cin >> n;
                cout << "���������� ���������� �������� ��� �������� ����� ��� (x)" << endl;
                cin >> x;
                ext_corr = pow(n, x);
            }
            else if(rol == 2){

            }
            else {
                cout << "Incorrect input, use only 1 and 2 for choise" << endl;
            }
            cout << "���� ��������� �������� ��������?" << endl << "1. ��" << endl << "2. ���" << endl;
            cin >> rol2;
            if(rol2 == 1){
                cout << "���������� ���� �������� (n)" << endl;
                cin >> n1;
                cout << "���������� ���������� �������� ��� �������� ����� ��� (x)" << endl;
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
