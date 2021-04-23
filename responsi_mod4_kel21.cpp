#include <iostream> 
#include <string.h>

using namespace std;

void enkripsi(){
    string huruf_biasa, sandi;
    int i, k;
    char c;
    
    cout << "Masukkan Huruf/Kalimat : ";
    cin.ignore(); 
    getline (cin, huruf_biasa);
    cout << "Kelompok ke- ? : "; 
    cin >> k;
    sandi = " ";
    
    for (i = 0; i < huruf_biasa.length(); i++){
        c = huruf_biasa[i];
        if (isalpha(c)){
            c = toupper(c); 
            c = c - 65; 
            c = (c + k) % 26; 
            c = c + 65;
        }
        sandi = sandi + c; 
    }

    cout << "hasil enkripsi : " << sandi << endl; 
}

class Kelompok21{
public:
    void dekripsi(){
        string huruf_biasa, sandi;
        int i, k;
        char c;
        
        cout << "Masukkan Huruf/Kalimat : ";
        cin.ignore(); 
        getline (cin, sandi);
        cout << "Kelompok ke- ? : "; 
        cin >> k;
        huruf_biasa = "";  
        
        for (i = 0; i < sandi.length(); i++){
            c = sandi[i];
            if (isalpha(c)){
                c = toupper(c); 
                c = c - 65; 
                if (c - k < 0) 
                    c = 26 + (c - k);
                else
                    c = (c - k) % 26;
                    c = c + 65; 
                    c = tolower(c); 
            }
            huruf_biasa = huruf_biasa + c; 
        }
        cout << "hasil dekripsi : " << huruf_biasa << endl; 
    }
};

int main (){
    Kelompok21 Myobj; 
    int pil;
    bool stop;
    stop = false;
    char lanjut;
    
    while (!stop){
        system("cls");
        cout << "MENU ENKRIPSI/DEKRIPSI KElOMPOK 21 : " << endl;
        cout << "1. Enkripisi " << endl;
        cout << "2. Dekripsi " << endl;
        cout << "3. Exit " << endl;
        cout <<"Pilih Menu : "; 
        cin >> pil;
        if(pil == 1){
            enkripsi();
            cout << "Lanjutkan (y/n)?: ";
            cin >> lanjut;
            if(lanjut == 'y' || lanjut == 'Y'){
                continue;
            }
            else if(lanjut == 'n' || lanjut == 'N'){
                break;
            }
        }
        else if(pil == 2){
            Myobj.dekripsi();
            cout << "Lanjutkan (y/n)?: ";
            cin >> lanjut;
            if(lanjut == 'y' || lanjut == 'Y'){
                continue;
            }
            else if(lanjut == 'n' || lanjut == 'N'){
                break;
            }
        }
        else if(pil == 3){
            stop = true;
            break;
        }
    }
}
