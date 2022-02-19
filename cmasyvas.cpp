#include <iostream>
#include <string>
#include <iomanip>


using std::cout;
using std::cin;
using std::string;

struct data {
    string vardas = "", pavarde = ""; //vardas ir pavarde
    int paz[10] = {0}, egz = 0; //suvesti pazymiai
    double vid=0; //skaicuojamas pazymiu vidurkis
    int sud=0; //sudedami pazymiai
    double galutinis=0; // apskaiciuojamas galutinis
};

void ivestis(data& temp);
void isved(data& temp, int pasirinkimas);

int main(){
    
    
    int pasirinkimas;
    cout << "jeigu norite skaiciuoti vidurki, iveskite 1, jeigu norite skaiciuoti mediana, iveskite 0: ";
    cin >> pasirinkimas;
    while(pasirinkimas>1)
    {
        cout<<"pasirinkote neteisingai.rinkites dar karta:";
        cin >> pasirinkimas;
    }
    

    
    data* mas = new data[2]; //pereina per visus mokinius
    for(data* a = mas; a < mas + 2; a++)
    {
        ivestis(*a);
    }
    for(data* a = mas; a < mas + 2; a++)
    {
        isved(*a,pasirinkimas);
    }
    delete[] mas;
    
   
}

void ivestis(data& temp)
{
    cout << "veskite varda: "; cin>>temp.vardas;
    cout << "veskite pavarde: "; cin>>temp.pavarde;
  
    for(int i=0;i<10;i++)
    {
        cout << "Iveskite " << i+1 << "-a pazymi."; cin >> temp.paz[i];
        temp.sud+=temp.paz[i];
        
    }
    cout << "iveskite egzamino iverti: "; cin >> temp.egz;
   
    
}

void isved(data& temp, int pasirinkimas)
{
    cout<<std::setw(15)<<"Vardas"<<std::setw(15)<<"Pavarde";
    if(pasirinkimas==1)
    {
        temp.vid = temp.sud/10;
        cout<<std::setw(20)<<"Galutinis (vid.)"<<std::endl;
    }
    else if(pasirinkimas==0)
    {
        temp.vid = (temp.paz[5]+temp.paz[6])/2;
        cout<<std::setw(20)<<"Galutinis (med.)"<<std::endl;

    }

    temp.galutinis = (0.4*temp.vid) + (0.6*(double)temp.egz);

    cout<<std::setw(15)<<temp.vardas<<std::setw(15)<<temp.pavarde<<std::setw(20)<<std::setprecision(2)<<temp.galutinis<<std::endl;
    
}
