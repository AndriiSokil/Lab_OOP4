#include <iostream>
using namespace std;


class BOARDGAME {

protected:

    string name;

public:
    //конструктор
    BOARDGAME() {
       /* cout << "Викликаємо базовий  конструктор без параметрів..." << endl;
        name = "DEFAULT_NAME";*/

    }

    //конструктор з параметрами 
    BOARDGAME(const string& name) : name(name) {
       /* cout << "Викликаємо базовий  конструктор з параметрами..." << endl;*/
    }


    // деструктор

    ~BOARDGAME() {
        //cout << "Викликаємо базовий  деструктор..." << endl;
    }

    string GetName() const {
        return name;
    }

    void SetName(string names) {
        name = names;
    }

    void GetFullInfo() const {
        cout << "\nНазва набору: " << GetName() << "\n";
    }
};


class Shaski : public BOARDGAME
{

private:

    double WeightShaski;
    double WeightBOARD;

public:
    //конструктор
    Shaski() : BOARDGAME() {
        //cout << "Викликаємо похідний конструктор без параметрів..." << endl;
        WeightShaski = 1;
        WeightBOARD = 1;
    }
    //конструктор з параметрами 
    Shaski(const string& names, const double& WeightShaski, const double& WeightBOARD) :BOARDGAME(names),
        WeightShaski(WeightShaski), WeightBOARD(WeightBOARD)
    {
        //cout << "Викликаємо похідний конструктор з параметрами..." << endl;
    }


    // деструктор
    ~Shaski()
    {
        //cout << "Викликаємо похідний деструктор..." << endl;
    }



    double GetWeightShaski() const {
        return WeightShaski;
    }

    double GetWeightBOARD() const {
        return WeightBOARD;
    }

    void SetWeightShaski(double WeightS) {
        WeightShaski = WeightS;
    }

    void SetWeightBOARD(double WeightB) {
        WeightBOARD = WeightB;
    }

    double TotalWeightShask() const {
        return WeightShaski * 24;
    }

    double TotalWeight() const {
        return WeightBOARD + WeightShaski * 24;
    }
    void GetFullInfoTV() const {
        cout << "\nВага шашки — " << GetWeightShaski() << "g" <<
            "\nВага дошки — " << GetWeightBOARD() << "g" << "\n\n";

    }

};


bool operator > (const Shaski& adv1, const Shaski& adv2) {
    return adv1.TotalWeight() > adv2.TotalWeight();
}

bool operator < (const Shaski& adv1, const Shaski& adv2) {
    return adv1.TotalWeight() < adv2.TotalWeight();
}


int main() {

    system("chcp 1251");

    Shaski Shaski1("Мiжнародні шашки", 2.35, 140);
    Shaski Shaski2("Американські шашки", 3, 140);
    Shaski Shaski3("Шашки для басейну", 2.4, 144.5);

    Shaski* arrSha[] = { &Shaski1, &Shaski2, &Shaski3 };
    Shaski* arrShaTemp;

    int k1, k2, kst, i;
    double sum = 0;
    kst = sizeof(arrSha) / sizeof(*arrSha);

   
    for (k1 = 1; k1 < kst; k1++) {
        arrShaTemp = *(arrSha + k1);
        k2 = k1 - 1;
        while (k2 >= 0 and (*arrShaTemp > *arrSha[k2])) {
            (arrSha[k2 + 1]) = arrSha[k2];
            k2--;
        }
        arrSha[k2 + 1] = arrShaTemp;
    }

    for (i = 0; i < kst; i++) {
        cout << "\n№" << i + 1 << " за вагою набору: " << arrSha[i]->TotalWeight() << "g";
        sum += arrSha[i]->TotalWeight();
        arrSha[i]->GetFullInfo();
        arrSha[i]->GetFullInfoTV();
    }
    cout << "\t Загальна вага всіх комплектів: " << sum << "g" << "\n\n";

    return 0;
}
/*Створити базовий клас НАСТІЛЬНА ГРА(задається назва).Створити похідний клас ШАШКИ(задаються вага кожної з 24 однотипних фігур,
вага дошки для гри розміром 8x8).Для заданих прикладів різних комплектів настільних ігор відсортувати їх за спаданням ваги
і обчислити сумарну вагу.*/