#include <Windows.h>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class REPO_Game {
public:
    map<string, string> vocabulary
    {
        {"Peeper", "Глаз"}, {"Shadow Child", "Дылда ребёнок"}, {"4x Gnomes", "Гномы"}, {"Apex Predator", "Утка"}, {"Spewer", "Блевулька"}, {"Rugrat", "Младенец"}, {"Animal", "Собака"}, {"Chef", "Лягушка"}, {"Upscream", "Голова на ножках"}, {"Bowtie", "Зефирка"}, {"Mentalist", "Мегамозг"}, {"4x Bangers", "Шахиды"}, {"Hidden", "Невидимка"}, {"Headman", "Летающая голова"}, {"Robe", "Монашка"}, {"Huntsman", "Дед"}, {"Reaper", "Селяночка"}, {"Clown", "Клоун"}, {"Trudge", "Красная пикмэ"}
    };

    vector<string> translating_for_RUS(vector<string> mobs) {
        vector<string> mobs_RUS;

        for (string mob : mobs) {
            if (vocabulary.count(mob) == 1) {
                mobs_RUS.push_back(vocabulary[mob]);
            }
        }
        return mobs_RUS;
    }

    void main_function(int lvl) 
    {
        srand(time(NULL));
    
        int const SIZE_1 = 5;
        int const SIZE_2 = 8;
        int const SIZE_3 = 6;

        //Мобы 1 класса = 10 очкам
        string mobs_1class[SIZE_1]{"Peeper", "Shadow Child", "4x Gnomes", "Apex Predator", "Spewer"};
        //Мобы 2 класса = 25 очкам
        string mobs_2class[SIZE_2]{"Rugrat", "Animal", "Chef", "Upscream", "Bowtie", "Mentalist", "4x Bangers", "Hidden"};
        //Мобы 3 класса = 40 очкам
        string mobs_3class[SIZE_3]{"Headman", "Robe", "Huntsman", "Reaper", "Clown", "Trudge"};

        vector<string> mobs;

        int lvl_points = 35 + 15 * lvl;

        while (lvl_points > 10) {

            int lst_mob_choice = rand() % 2;
            int mob_idx;

            switch (lst_mob_choice)
            {
            case 0:
                mob_idx = rand() % 5;
                mobs.push_back(mobs_1class[mob_idx]);
                lvl_points -= 10;
            case 1:
                if (lvl_points >= 25) {
                    mob_idx = rand() % 8;
                    mobs.push_back(mobs_2class[mob_idx]);
                    lvl_points -= 25;
                }
            case 2:
                if (lvl_points >= 40) {
                    mob_idx = rand() % 6;
                    mobs.push_back(mobs_3class[mob_idx]);
                    lvl_points -= 40;
                }
            default:
                break;
            }   
        }
        string answer;
        cout << "Хотите перевести мобов на русский язык? (Да/Нет)\n";
        cin >> answer;
        cout << "Мобы, которые сейчас находятся на вашем уровне: \n";

        if (answer == "Да") {
            vector<string> mobs_Rus = translating_for_RUS(mobs);
            sort(mobs_Rus.begin(), mobs_Rus.end());
            for (string elem : mobs_Rus) {
                cout << elem << ", ";
            }
        }
        else if (answer == "Нет") {
            sort(mobs.begin(), mobs.end());
            for (string elem : mobs) {
                cout << elem << ", ";
            }
        }
        cout << "будь осторожней!";
    }
};
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    REPO_Game choose;

    int lvl;
    cout << "На каком вы сейчас уровне?\n";
    cin >> lvl;

    choose.main_function(lvl);

    return 0;
}
