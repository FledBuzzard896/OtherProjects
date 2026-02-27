#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

int i = 0;
int copy_i = 0;
int end_i = 1;
int copy_end_i = 1;

class play {
public:

    vector <string> main_veg_lst;
    vector <string> second_veg_lst;
    vector <string> main_question_massive;
    vector <string> second_question_massive;

    string singer, question;
    string ans;

    int COPY_i = 0;
    int COPY_i_QUE = 0;

    string tmp_per = "";
    string name, new_name, q, new_q;

    vector<string> switch_with_sort(vector<string> out_lst, vector<string> in_lst, char criteriy) {

        for (string elem : out_lst) {

            for (i = COPY_i; i != end_i; i++) {

                if (elem[i] == criteriy) {
                    in_lst.push_back(elem);
                }
            }
        }
        COPY_i = i;
        end_i += 2;
        return in_lst;
    }
    vector<string> switch_with_sort_QUESTIONS(vector<string> out_lst, vector<string> in_lst, char criteriy) {

        for (string elem : out_lst) {

            for (copy_i = COPY_i_QUE; copy_i != copy_end_i; copy_i++) {

                if (elem[copy_i] == criteriy) {
                    in_lst.push_back(elem);
                }
            }
        }
        COPY_i_QUE = copy_i;
        copy_end_i += 2;
        return in_lst;
    }

    string enumeration(vector<string> persons_lst, vector<string> questions) {

        string que = "";
        string pevichcka = "";
        string answer;

        int j = 0;

        for (string elem : questions) {

            for (i = COPY_i; i != elem.length(); i++) {

                if (elem[i] != '_' and elem[i] != '1' and elem[i] != '0') {
                    que += elem[i];
                }
            }
            cout << que << "(Да/Нет)" << endl;
            cin >> answer;

            if (answer == "Да") {

                string elem2 = persons_lst[j];

                for (i = COPY_i; i != elem2.length(); i++) {

                    if (elem2[i] != '_' and elem2[i] != '1' and elem2[i] != '0') {
                        pevichcka += elem2[i];
                    }
                }
                return pevichcka;
                break;
            }
            else if (answer == "Нет") {
                que = "";
                j++;
            }
        }
        return "...";
    }
    void addition(string name, string question) {

        cout << "Походу вашей певицы нет в моей базе даных, введи её имя и фамилию в одну строчку, чтобы я понял кого вы загадали.\n";
        getline(cin, name);
        name = tmp_per + name;

        cout << "Напишите мне вопрос, по которому вы бы догадались, что я говорю про вашего персонажа!(В одну строчку)\n";
        getline(cin, question);
        question = tmp_per + question;

        ofstream persons;
        persons.open("data/pevichcki.txt", ios::app);
        persons << name << endl;
        persons.close();

        ofstream questions;
        questions.open("data/questions_for_pevichckes.txt", ios::app);
        questions << question;
        questions.close();
    }

    void mini_Akinator() {

        //Создание списка с певицами
        ifstream file;
        file.open("data/pevichcki.txt");

        if (file.is_open()) {

            while (getline(file, singer)) {
                main_veg_lst.push_back(singer);
            }
        }
        file.close();

        //Создание списка с вопросами для певиц
        ifstream newfile;
        file.open("data/questions_for_pevichckes.txt");

        if (file.is_open()) {

            while (getline(file, question)) {
                main_question_massive.push_back(question);
            }
        }
        file.close();

        cout << "Это игра: Акинатор.\nЗагадал певицу?\nЯ её отгадаю.\n";
        cout << "Ваш певец мужчина? (Да/Нет)\n";
        cin >> ans;

        if (ans == "Нет") {

            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
            main_veg_lst.clear();
            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
            main_question_massive.clear();
            tmp_per += "1_";

            cout << "Ваша певица старше 50 лет?(Да/Нет)\n";
            cin >> ans;
            if (ans == "Да") {

                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                second_veg_lst.clear();
                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                second_question_massive.clear();

                tmp_per += "1_";
                cout << "У вашей певицы светлые волосы?(Да/Нет)\n";
                cin >> ans;
                if (ans == "Да") {

                    second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                    main_veg_lst.clear();
                    second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                    main_question_massive.clear();
                    tmp_per += "0_";

                    cout << "У вашей певицы закончилась карьера?(Да/Нет)\n";
                    cin >> ans;
                    if (ans == "Да") {

                        main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                        second_veg_lst.clear();
                        main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                        second_question_massive.clear();
                        tmp_per += "1_";

                        //Выборка
                        name = enumeration(main_veg_lst, main_question_massive);
                        cout << "Ваша певица:" << name << endl;
                        /*if (name == "...") {
                            addition(name, q)
                        }*/
                    }
                    else if (ans == "Нет") {

                        main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                        second_veg_lst.clear();
                        main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                        second_question_massive.clear();
                        tmp_per += "0_";

                        cout << "Есть ли у певицы возложенные на неё санкции?(Да/Нет)\n";
                        cin >> ans;
                        if (ans == "Да") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                            main_question_massive.clear();
                            tmp_per += "1_";
                            //Выборка
                            cout << "Ваша певица:" << enumeration(second_veg_lst, second_question_massive) << endl;

                        }
                        else if (ans == "Нет") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                            main_question_massive.clear();
                            tmp_per += "0_";
                            //Выборка
                            cout << "Ваша певица:" << enumeration(second_veg_lst, second_question_massive) << endl;
                        }
                        else {
                            cout << "Я не понимаю что вы ввели\n";
                        }
                    }
                    else {
                        cout << "Я не понимаю что вы ввели\n";
                    }
                }
                else if (ans == "Нет") {

                    second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                    main_veg_lst.clear();
                    second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                    main_question_massive.clear();
                    tmp_per += "1_";
                    //Выборка
                    cout << "Ваша певица:" << enumeration(second_veg_lst, second_question_massive) << endl;

                }
                else {
                    cout << "Я не понимаю что вы ввели\n";
                }
            }
            else if (ans == "Нет") {

                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                second_veg_lst.clear();
                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                second_question_massive.clear();
                tmp_per += "0_";

                cout << "У вашей певицы светлые волосы?(Да/Нет)\n";
                cin >> ans;
                if (ans == "Да") {

                    second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                    main_veg_lst.clear();
                    second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                    main_question_massive.clear();
                    tmp_per += "0_";

                    cout << "У вашей певицы пик популярности был до 2010 года?(Да/Нет)\n";
                    cin >> ans;
                    if (ans == "Да") {

                        main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                        second_veg_lst.clear();
                        main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                        second_question_massive.clear();
                        tmp_per += "1_";

                        cout << "Снималась/озвучивала ли певица в кино или на ТВ?(Да/Нет)\n";
                        cin >> ans;
                        if (ans == "Да") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                            main_question_massive.clear();
                            tmp_per += "1_";
                            //Выборка
                            cout << "Ваша певица:" << enumeration(second_veg_lst, second_question_massive) << endl;
                        }
                        else if (ans == "Нет") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                            main_question_massive.clear();
                            tmp_per += "0_";
                            //Выборка
                            cout << "Ваша певица:" << enumeration(second_veg_lst, second_question_massive) << endl;
                        }
                        else {
                            cout << "Я не понимаю, что вы ввели\n";
                        }
                    }
                    else if (ans == "Нет") {

                        main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                        second_veg_lst.clear();
                        main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                        second_question_massive.clear();
                        tmp_per += "0_";

                        cout << "У вашей певицы есть награда Золотой Грамофон?(Да/Нет)\n";
                        cin >> ans;
                        if (ans == "Да") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                            main_question_massive.clear();
                            tmp_per += "1_";

                            cout << "Ваша певица учавствовала в съемке озвучке кино сериалов?(Да/Нет)\n";
                            cin >> ans;
                            if (ans == "Да") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                                second_question_massive.clear();
                                tmp_per += "1_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else if (ans == "Нет") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                                second_question_massive.clear();
                                tmp_per += "0_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else {
                                cout << "Я не понимаю что вы ввели\n";
                            }
                        }
                        else if (ans == "Нет") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                            main_question_massive.clear();
                            tmp_per += "0_";

                            cout << "Ваша певица учавствовала в съемке озвучке кино сериалов?(Да/Нет)\n";
                            cin >> ans;
                            if (ans == "Да") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                                second_question_massive.clear();
                                tmp_per += "0_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else if (ans == "Нет") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                                second_question_massive.clear();
                                tmp_per += "1_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else {
                                cout << "Я не понимаю что вы ввели\n";
                            }
                        }
                        else {
                            cout << "Я не понимаю что вы ввели\n";
                        }
                    }
                    else {
                        cout << "Я не понимаю что вы ввели\n";
                    }
                }
                else if (ans == "Нет") {

                    second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                    main_veg_lst.clear();
                    second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                    main_question_massive.clear();
                    tmp_per += "1_";

                    cout << "У вашей певицы пик популярности был до 2010 года?(Да/Нет)\n";
                    cin >> ans;
                    if (ans == "Да") {

                        main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                        second_veg_lst.clear();
                        main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                        second_question_massive.clear();
                        tmp_per += "1_";

                        cout << "У вашей певицы есть премия Золотой Грамофон?(Да/Нет)\n";
                        cin >> ans;
                        if (ans == "Да") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                            main_question_massive.clear();
                            tmp_per += "1_";

                            cout << "Певица была ли телеведущим/соведущим?(Да/Нет)\n";
                            cin >> ans;
                            if (ans == "Да") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                                second_question_massive.clear();
                                tmp_per += "1_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else if (ans == "Нет") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                                second_question_massive.clear();
                                tmp_per += "0_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else {
                                cout << "Я не понимаю что вы ввели\n";
                            }
                        }
                        else if (ans == "Нет") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                            main_question_massive.clear();
                            tmp_per += "0_";
                            //Выборка
                            cout << "Ваша певица:" << enumeration(second_veg_lst, second_question_massive) << endl;
                        }
                        else {
                            cout << "Я не понимаю что вы ввели\n";
                        }
                    }
                    else if (ans == "Нет") {

                        main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                        second_veg_lst.clear();
                        main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                        second_question_massive.clear();
                        tmp_per += "0_";

                        cout << "У вашей певицы есть премия Золотой Грамофон?(Да/Нет)\n";
                        cin >> ans;
                        if (ans == "Да") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '1');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '1');
                            main_question_massive.clear();
                            tmp_per += "1_";

                            cout << "Ваша певица учавствовала в съемке озвучке кино сериалов?(Да/Нет)\n";
                            cin >> ans;
                            if (ans == "Да") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                                second_question_massive.clear();
                                tmp_per += "1_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else if (ans == "Нет") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                                second_question_massive.clear();
                                tmp_per += "0_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else {
                                cout << "Я не понимаю что вы ввели\n";
                            }
                        }
                        else if (ans == "Нет") {

                            second_veg_lst = switch_with_sort(main_veg_lst, second_veg_lst, '0');
                            main_veg_lst.clear();
                            second_question_massive = switch_with_sort_QUESTIONS(main_question_massive, second_question_massive, '0');
                            main_question_massive.clear();
                            tmp_per += "0_";

                            cout << "Ваша певица учавствовала в съемке озвучке кино сериалов?(Да/Нет)\n";
                            cin >> ans;
                            if (ans == "Да") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '1');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '1');
                                second_question_massive.clear();
                                tmp_per += "1_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else if (ans == "Нет") {

                                main_veg_lst = switch_with_sort(second_veg_lst, main_veg_lst, '0');
                                second_veg_lst.clear();
                                main_question_massive = switch_with_sort_QUESTIONS(second_question_massive, main_question_massive, '0');
                                second_question_massive.clear();
                                tmp_per += "0_";
                                //Выборка
                                cout << "Ваша певица:" << enumeration(main_veg_lst, main_question_massive) << endl;
                            }
                            else {
                                cout << "Я не понимаю что вы ввели\n";
                            }
                        }
                        else {
                            cout << "Я не понимаю что вы ввели\n";
                        }
                    }
                    else {
                        cout << "Я не понимаю что вы ввели\n";
                    }
                }
                else {
                    cout << "Я не понимаю что вы ввели\n";
                }
            }
            else {
                cout << "Я не понимаю что вы ввели\n";
            }

        }
        else if (ans == "Да") {
            cout << "Мы скоро добавим мужчин-певцов, по типу Баскова, или Дмитрия Билайна, или Филипа Бедросовича Киркорова, или Джигана, или там Панки Хоя (Юра Хой)... Короче всех! Извините :(\n";
        }
        else {
            cout << "Я не понимаю что ты ввёл...\n";
        }
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    play start;
    start.mini_Akinator();
    //checking.work_with_file();
}