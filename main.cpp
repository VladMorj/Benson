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
