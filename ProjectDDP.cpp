// Nama anggota
// 1. Daniel okto mahendra s
// 2. Khomarul hidayat
// 3. Sulthon aris setiawan

#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <time.h>
using namespace std;

void sleep(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

void pembuat() {
	system("cls");
	cout << "Loading";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    system("cls");
    cout << " -------------------------------- " << endl;
    cout << " |           Pembuat            | " << endl;
    cout << " -------------------------------- " << endl << endl;
    cout << " 1. Daniel Okto Mahendra S" << endl;
    cout << " 2. Khomarul Hidayat" << endl;
    cout << " 3. Sulthon Aris Setiawan" << endl << endl;
    cout << " Tekan tombol apa saja untuk kembali ke menu utama...";
    _getch();
    system("cls");
	cout << "Loading";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
}

int mulai() {
	system("cls");
	cout << "Loading";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    system("cls");
    srand(time(0));
    char mv;
    char repeat = 'y';

    while (repeat == 'y') {
        int skor = 0;
        bool wasit = true;
        int x = 9;
        int rintangan[3];
        int rintang[3];
        rintang[0] = 10;
        rintang[1] = 18;
        rintang[2] = 27;

        for (int i = 0; i < 3; i++) {
            rintangan[i] = (rand() - 1) % 12 + 2;
        }

        string map[20][30];

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 30; j++) {
                if (i == 0 || i == 19 || j == 29 || j == 0)
                    map[i][j] = "* ";
                else
                    map[i][j] = "  ";
            }
        }

        while (wasit == true) {
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j < 19; j++) {
                    map[j][rintang[i]] = "  ";
                }
            }

            for (int i = 0; i < 3; i++) {
                rintang[i]--;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 1; j < 19; j++) {
                    map[j][rintang[i]] = "* ";
                }
            }

            for (int i = 0; i < 3; i++) {
                map[rintangan[i]][rintang[i]] = "  ";
                map[rintangan[i] + 1][rintang[i]] = "  ";
                map[rintangan[i] + 2][rintang[i]] = "  ";
                map[rintangan[i] + 3][rintang[i]] = "  ";
                map[rintangan[i] + 4][rintang[i]] = "  ";
            }

            for (int i = 0; i < 3; i++) {
                if (rintang[i] == 1) {
                    rintang[i] = 28;
                    rintangan[i] = (rand() - 1) % 12 + 2;
                }
            }

            map[x][3] = "  ";

            if (kbhit()) {
                mv = getch();
                x = x - 3;
            }

            x++;

            if (x < 1)
                x = 1;

            for (int i = 0; i < 3; i++) {
                if (rintang[i] == 3) {
                    if (map[x][3] == "  ") {
                        skor = skor + 1;
                    }
                    if (map[x][3] == "* ") {
                        wasit = false;
                    }
                }
            }

            map[x][3] = "W ";

            for (int i = 1; i < 19; i++) {
                map[i][1] = "  ";
            }

            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 30; j++) {
                    cout << map[i][j];
                }
                cout << endl;
            }

            cout << "Skor = " << skor;
            Sleep(100);
            system("cls");
        }

        cout << "Skor kamu = " << skor << endl;

        cout << "Main lagi? (y/n) = ";
        cin >> repeat;
    }
    system("cls");
	cout << "Loading";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    return 0;
}

int main() {
    int menu;
    do {
        system("cls");
        cout << " -------------------------------- " << endl;
        cout << " |        Burung Terbang        | " << endl;
        cout << " -------------------------------- " << endl << endl;
        cout << " 1. Mulai" << endl;
        cout << " 2. Pembuat" << endl;
        cout << " 3. Keluar" << endl << endl;
        cout << " Pilih Opsi: ";
        cin >> menu;

        switch (menu) {
            case 1:
            	mulai();
                break;
            case 2:
                pembuat();
                break;
            case 3:
                break;
        }

    } while (menu != 3);

    return 0;
}
