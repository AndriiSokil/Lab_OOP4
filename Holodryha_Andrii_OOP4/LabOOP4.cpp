#include <iostream>
using namespace std;


class BOARDGAME {

protected:

    string name;

public:
    //�����������
    BOARDGAME() {
       /* cout << "��������� �������  ����������� ��� ���������..." << endl;
        name = "DEFAULT_NAME";*/

    }

    //����������� � ����������� 
    BOARDGAME(const string& name) : name(name) {
       /* cout << "��������� �������  ����������� � �����������..." << endl;*/
    }


    // ����������

    ~BOARDGAME() {
        //cout << "��������� �������  ����������..." << endl;
    }

    string GetName() const {
        return name;
    }

    void SetName(string names) {
        name = names;
    }

    void GetFullInfo() const {
        cout << "\n����� ������: " << GetName() << "\n";
    }
};


class Shaski : public BOARDGAME
{

private:

    double WeightShaski;
    double WeightBOARD;

public:
    //�����������
    Shaski() : BOARDGAME() {
        //cout << "��������� �������� ����������� ��� ���������..." << endl;
        WeightShaski = 1;
        WeightBOARD = 1;
    }
    //����������� � ����������� 
    Shaski(const string& names, const double& WeightShaski, const double& WeightBOARD) :BOARDGAME(names),
        WeightShaski(WeightShaski), WeightBOARD(WeightBOARD)
    {
        //cout << "��������� �������� ����������� � �����������..." << endl;
    }


    // ����������
    ~Shaski()
    {
        //cout << "��������� �������� ����������..." << endl;
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
        cout << "\n���� ����� � " << GetWeightShaski() << "g" <<
            "\n���� ����� � " << GetWeightBOARD() << "g" << "\n\n";

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

    Shaski Shaski1("�i������� �����", 2.35, 140);
    Shaski Shaski2("����������� �����", 3, 140);
    Shaski Shaski3("����� ��� �������", 2.4, 144.5);

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
        cout << "\n�" << i + 1 << " �� ����� ������: " << arrSha[i]->TotalWeight() << "g";
        sum += arrSha[i]->TotalWeight();
        arrSha[i]->GetFullInfo();
        arrSha[i]->GetFullInfoTV();
    }
    cout << "\t �������� ���� ��� ���������: " << sum << "g" << "\n\n";

    return 0;
}
/*�������� ������� ���� ���Ҳ���� ���(�������� �����).�������� �������� ���� �����(��������� ���� ����� � 24 ���������� �����,
���� ����� ��� ��� ������� 8x8).��� ������� �������� ����� ��������� ��������� ���� ����������� �� �� ��������� ����
� ��������� ������� ����.*/