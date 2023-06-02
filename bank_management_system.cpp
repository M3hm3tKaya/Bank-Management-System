#include <iostream>
#include <string>
#include <clocale>
#include <fstream>
#include <conio.h>
#include <unistd.h>
using namespace std;
//cout << "\x1b[A"; imceli ust satira goturur;

string Esc = "\n\t\t\tGeri Donmek icin 'ESC'";
string b2 = "\n\t\t";
string b3 = "\n\t\t\t";


int kullaniciGiris();
int kullaniciKayit();
string getString(string mode);
string getData(string id,int veriNo);
string getID();
string mailDogrulama(string mail);
int kullaniciMenu();
int Update(string id,string yeniVeri);
string listele();


int main(){
    Baslangic:
    system("cls");


    cout<<b2<<"----------  HOSGELDINIZ  ----------"<<b3<<"1 - Kullanici Arayuzu"<<b3<<"2 - Yonetici Arayuzu (bakimda)"<<b2;
    char secim;
    secim = getch();


    if(secim=='1'){
        kullaniciAraYuzu:
        system("cls");
        cout<<Esc<<b3<<"1 - Giris Yap"<<b3<<"2 - Kayit Ol"<<b3;

        secim = getch();


        if(secim == '1'){
            if(kullaniciGiris()){
                kullaniciMenu();
                goto Baslangic;

            }
            else{
                goto kullaniciAraYuzu;
            }

        }
        else if(secim=='2'){
            kullaniciKayit();
            goto kullaniciAraYuzu;
        }
        else if(secim == 27){
            goto Baslangic;
        }
        else{
            goto kullaniciAraYuzu;

        }

    }
    else{
        //system("cls");
        //cout<<b2<<"Hatali Secim"<<b2<<system("pause");
        goto Baslangic;
    }

}


string getString(string mode){
    string var;
    char ch;
    char outCh;
    int sayac = 0;


    while(1){
        ch = getch();
        if(mode == "pass")
            outCh = '*';
        else if(mode == "invisible")
            outCh = '\b';
        else
            outCh = ch;

        if(ch == 27){  // esc
            return "e s c";
        }
        else if(ch == 13){ // enter
            if(var != "")
                break;
            else
                continue;
        }
        else if(ch == 8){  // backspace
            if(sayac > 0){
                var.pop_back();
                cout<<"\b \b";
                sayac--;
            }
        }
        else{
            var.push_back(ch);
            cout<<outCh;
            sayac++;
        }
    }
    return var;
}

string getID(){
    fstream dosya;
    string ID;
    dosya.open("idler.txt",ios_base::in);
    dosya>>ID;
    return ID;
}

int kullaniciGiris(){
    kullanici_giris:
    string id,sifre,id2,sifre2,ad2;
    char ch;

    system("cls");

    cout<<Esc<<b2<<"ID/Kullanici Adi\t: "<<b2<<"Sifre\t\t\t: ";
    cout << "\x1b[A";
    //cout<<"\t\t";
    id = getString(" ");
    if(id == "e s c")
        return 0;
    cout<<"\n\t\t\t\t\t\t\b\b\b\b\b\b";
    sifre = getString("pass");
    if(sifre == "e s c")
        return 0;

    id2 = getData(id,1);
    ad2 = getData(id,2);
    sifre2 = getData(id,4);

    if((id == id2 || id == ad2 )&& sifre == sifre2){

        fstream dosya;
        dosya.open("online.txt",ios_base::out);
        dosya<<id2;
        dosya.close();
        return 1;
    }
    else{

        cout<<b3<<"Kullanici Adi veya Sifre Yanlis !";
        cout<<b3<<system("Pause");
        goto kullanici_giris;
    }



}

int kullaniciKayit(){
    string ad,soyad,sifre,sifre2,mail,mail2,code;
    system("cls");
    cout<<Esc<<b2<<"Ad : "<<ad<<b2<<"Soyad : "<<soyad<<endl<<b2<<"Sifre : "<<b2<<"Sifre Tekrar : "<<endl;
    cout<<b2<<"Mail : "<<b2<<"Mail Tekrar : "<<b2;
    char ch;
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\x1b[A";
    cout << "\t";

    ad = getString(" ");
    if(ad == "e s c")
        return 0;
    cout<<b3;
    soyad = getString(" ");
    if(soyad == "e s c")
        return 0;
    cout<<endl<<endl<<"\t\t\t\t";

    sifreler:

    sifre = getString("pass");
    if(sifre == "e s c")
        return 0;
    cout<<endl<<"\t\t\t\t";
    sifre2 = getString("pass");
    if(sifre2 == "e s c")
        return 0;

    if(sifre != sifre2){
        cout<<b2<<"Sifreler Eslesmiyor !!!";
        cout << "\x1b[A";
        cout << "\x1b[A";
        cout << "\b\b\b\b\b\b\b";
        for(char ch1 : sifre){
            cout<<" ";
        }
        for(char ch1 : sifre){
            cout<<"\b";
        }

        cout<<endl<<"\t\t\t\t";

        for(char ch1 : sifre2){
            cout<<" ";
        }
        for(char ch1 : sifre2){
            cout<<"\b";
        }
        cout << "\x1b[A";



        goto sifreler;
    }
    else{
                    //Sifreler Eslesmiyor !!!
        cout<<b2<<"                         ";
    }

    cout<<endl<<"\t\t\t\t";
    mailler:
    mail = getString(" ");
    if(mail == "e s c")
        return 0;
    cout<<endl<<"\t\t\t\t";
    mail2 = getString(" ");
    if(mail2 == "e s c")
        return 0;

    if(mail != mail2){

        cout<<b2<<"Mailler Eslesmiyor !!!";
        cout << "\x1b[A";
        cout << "\x1b[A";
        cout << "\b\b\b\b\b\b";
        for(char ch1 : mail){
            cout<<" ";
        }
        for(char ch1 : mail){
            cout<<"\b";
        }

        cout<<endl<<"\t\t\t\t";

        for(char ch1 : mail2){
            cout<<" ";
        }
        for(char ch1 : mail2){
            cout<<"\b";
        }
        cout << "\x1b[A";



        goto mailler;
    }
    else{
        cout<<b2<<"                         ";
    }

    code = mailDogrulama(mail);
    if(code == "error"){
       cout<<b2<<"Hata Olustu Lutfe Bilgilerinizi Kontrol Edip Tekrar Deneyin !"<<b3<<system("pause");
       return 0;
    }
    if(code == "false"){
        cout<<b2<<"Yanlis Kod , Kayit Basarisiz !"<<b2<<system("pause");
        return 0;
    }
    if(code == "true"){
        fstream dosya;
        dosya.open("kullanicilar.txt",ios_base::app);
        dosya<<getID()<<"\\"<<ad<<"\\"<<soyad<<"\\"<<sifre<<"\\"<<mail<<"\\"<<0<<endl;
        dosya.close();
        cout<<endl<<endl<<b3<<"Kayit Basarili"<<b3<<"Kullanici ID : "<<getID()<<b3<<"Kullanici Adi : "<<ad<<endl;

        dosya.open("idler.txt",ios_base::in);
        int id;
        dosya>>id;
        id++;
        dosya.close();
        dosya.open("idler.txt",ios_base::out);
        dosya<<id;
        dosya.close();
        system("pause");

    }


}

string getData(string id,int veriNo){
    fstream dosya;
    string veri,controlID,controlAd;
    string veriler[6] = {};

    dosya.open("kullanicilar.txt",ios_base::in);

    for(int x = 0;x<stoi(getID())-1;x++){

        dosya>>veri;
        int sayac = 0;
        veriler[6] = {};

        int ctrlSayac = 0;
        controlID = "";
        controlAd = "";
        for(char ctrl : veri){
            if(ctrl == '\\'){
                ctrlSayac++;
                if(ctrlSayac >= 2)
                    break;
                else
                    continue;
            }
            else if(ctrlSayac == 0){
                controlID.push_back(ctrl);
            }
            else if(ctrlSayac == 1){
                controlAd.push_back(ctrl);
            }
        }

        if(controlAd != id && controlID != id){

            continue;
        }

        for(char ch : veri){

            if(ch == '\\'){
                sayac++;
                continue;
            }
            else{
                veriler[sayac].push_back(ch);
            }
        }
        break;

    }
    dosya.close();

    return veriler[veriNo-1];

}

string mailDogrulama(string mail){
    string sendMail = "SEND:"+mail;
    string code,code2;
    fstream dosya;
    string waitDizi[] = {
        "Lutfen Bekleyin .",
        "Lutfen Bekleyin . .",
        "Lutfen Bekleyin . . .",
        "Lutfen Bekleyin .",
        "Lutfen Bekleyin . . ",
        "Lutfen Bekleyin . . .",
    };

    dosya.open("sendmail.txt",ios_base::out);
    dosya<<sendMail;
    dosya.close();
    int sayac = 0;
    cout<<b3<<"Mail Gonderiliyor .";
    cout<<b3<<waitDizi[sayac];
    while(1){

        dosya.open("sendmail.txt",ios_base::in);
        dosya>>code;
        dosya.close();

        if(code != sendMail){
            break;
        }
        sleep(1);
        sayac++;
        cout << "\x1b[A";
        cout<<b3<<"                      ";
        cout << "\x1b[A";
        cout<<b3<<waitDizi[sayac];

        if(sayac > 5){
            code = "error";
            break;
        }
    }
    if(code != "error"){
        int hak = 3;
        kod:
        cout<<b3<<"Kod Gonderildi (Spam Klasorunu Kontrol Edin !)";
        cout<<b3<<"Kod :                     "<<b3<<"Kalan Deneme Hakki : "<<hak;
        cout << "\x1b[A";
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        code2 = getString(" ");

        if(code2 != code){
            if(hak <= 0){
                return "false";
            }
            hak--;

            cout << "\x1b[A";
            cout << "\x1b[A";
            goto kod;

        }
        else{
            return "true";
        }

    }
    else{
        return "error";
    }
}

int kullaniciMenu(){
    menu:
    system("cls");
    fstream dosya;
    string id,ad,soyad,sifre,mail,para;

    dosya.open("online.txt",ios_base::in);
    dosya>>id;
    dosya.close();

    ad = getData(id,2);
    soyad = getData(id,3);
    sifre = getData(id,4);
    mail = getData(id,5);
    para = getData(id,6);

    cout<<b2<<"------------------------------------"<<b3<<"     HOSGELDIN"<<b3<<"     "<<ad;
    cout<<b3<<"     "<<soyad<<b2<<"------------------------------------";
    cout<<b3<<"1 - Hesap Detaylari"<<b3<<"2 - Para Yatir"<<b3<<"3 - Para Gonder"<<b3<<"4 - Hesap Bilgilerini Duzenle"<<b3<<"5 - Hesap Sil";
    cout<<b3<<"------------------------------------"<<b3<<"6 - Tum Kullanicilari Listele"<<b3<<"7 - Kullanici Bilgilerini Goruntule";
    cout<<b3<<b3<<"0 - Cikis Yap";

    char secim;
    string secim1;
    secim = getch();
    if(secim == '0'){
        return 0;
    }
    else if(secim == '1'){
        hesap_detaylari:
        system("cls");
        cout<<Esc<<b3<<b3<<"Hesap Detaylari"<<b3<<"---------------";

        cout<<b3<<b3<<"AD \t\t: "<<ad<<b3<<"Soyad \t\t: "<<soyad<<b3<<"Para Miktari \t: "<<para<<b3<<"Mail \t\t: "<<mail<<endl;

        secim1 = getString("invisible");
        if(secim1 == "e s c")
            goto menu;
        else
            goto hesap_detaylari;
    }
    else if(secim == '2'){
        para_yatir:

        system("cls");
        string miktar;
        string yeniVeri;

        cout<<Esc<<b3<<b3<<"Guncel Hesap Bakiyesi : "<<para;
        cout<<b2<<b2<<"Yatirilicak Miktari Giriniz (0 - 9999): ";
        tekrar_deneme:
        miktar = getString(" ");

        if(miktar == "e s c")
            goto menu;
        else if(miktar.at(0) == '-' || miktar == "0"){

            cout<<b2<<"Lutfen 0 dan Buyuk Bir Deger Girin !!!";
            cout << "\x1b[A" <<"\t\t\b\b\b\b\b\b\b\b";
            for(char a : miktar){
                cout<<" ";
            }
            for(char a : miktar){
                cout<<"\b";
            }

            goto tekrar_deneme;
        }
        else if(miktar.length() > 4){
            cout<<b2<<"Lutfen 10 000 ' den Kucuk Bir Deger Girin !!!";
            cout << "\x1b[A" <<"\t\b\b\b\b\b\b\b\b";
            for(char a : miktar){
                cout<<" ";
            }
            for(char a : miktar){
                cout<<"\b";
            }

            goto tekrar_deneme;

        }

        para = to_string(stoi(para) + stoi(miktar));

        yeniVeri = id + "\\" + ad + "\\" + soyad + "\\" + sifre + "\\" + mail + "\\" + para;
        Update(id,yeniVeri);

        goto para_yatir;

    }
    else if(secim == '3'){
        para_gonder:
        system("cls");
        string id2,ad2,soyad2,sifre2,mail2,para2;
        string miktar,yeniveri,yeniveri2;


        cout<<Esc<<b3<<b3<<"Guncel Hesap Bakiyesi : "<<para;
        cout<<b3<<b3<<"ID Gir : ";
        para_gonder2:
        id2 = getString(" ");
        if(id2 == "e s c")
            goto menu;
        else if(id2 == id){
            cout<<b3<<"Kendine Para Gonderemessin !";
            cout<<"\x1b[A"<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            for(char a : id2){
                cout<<" ";
            }
            for(char a : id2){
                cout<<"\b";
            }
            goto para_gonder2;
        }
        ad2 = getData(id2,2);
        soyad2 = getData(id2,3);
        sifre2 = getData(id2,4);
        mail2 = getData(id2,5);
        para2 = getData(id2,6);
        if(ad2 != ""){
            cout<<b3<<"                                 ";
            cout<<b3<<"Alici Bilgileri"<<b3<<"--------------";
            cout<<b3<<"AD \t\t: "<<ad2<<b3<<"Soyad \t\t: "<<soyad2<<b3<<"Mail \t\t: "<<mail2<<endl;
            cout<<b3<<b3<<"Bilgilerin Dogrulugunu Onayliyor Musunuz ?"<<b3<<"1 - Evet\t\t2 - Hayir";
            secims:
            secim = getch();

            if(secim == '1'){
                cout<<b3;
                cout<<"Gonderilecek Miktar (Max Miktar = 9999): ";
                miktar_belirleme:
                miktar = getString(" ");
                if(miktar == "e s c")
                    goto menu;
                else if(miktar.at(0) == '-' || miktar == "0"){
                    cout<<b3<<"Lutfen 0 ' dan Buyuk Bir Deger Giriniz !!!      ";
                    cout << "\x1b[A"<<"\b\b\b\b\b\b\b";
                    for(char a : miktar){
                        cout<<" ";
                    }
                    for(char a : miktar){
                        cout<<"\b";
                    }
                    goto miktar_belirleme;
                }
                else if(miktar.length() > 4){
                    cout<<b3<<"Lutfen 10 000 ' den Kucuk Bir Deger Girin !!!";
                    cout << "\x1b[A" <<"\t\b\b\b\b\b\b\b";
                    for(char a : miktar){
                        cout<<" ";
                    }
                    for(char a : miktar){
                        cout<<"\b";
                    }
                    goto miktar_belirleme;
                }
                else if(stoi(para) - stoi(miktar) < 0){
                    cout<<b3<<"Yeterli Bakiyeniz yok !                        ";
                    cout << "\x1b[A"<<"\b\b\b\b\b\b";
                    for(char a : miktar){
                        cout<<" ";
                    }
                    for(char a : miktar){
                        cout<<"\b";
                    }
                    goto miktar_belirleme;

                }
                else{
                    system("cls");
                    cout<<b3<<"Guncel Hesap Bakiyesi : "<<para;
                    cout<<b3<<b3<<ad2<<" "<<soyad2<<" Kullanicisina "<<miktar<<" Birim Para Gonderilecek ";
                    cout<<b3<<"Onayliyor Musun ? "<<b3<<"1 - Evet\t\t2 - Hayir               ";
                    secims2:
                    secim = getch();
                    if(secim == '1'){
                        string geciciPara = para;
                        para = to_string(stoi(para) - stoi(miktar));
                        para2 = to_string(stoi(para2) + stoi(miktar));
                        yeniveri = id + "\\" + ad + "\\" + soyad + "\\" + sifre + "\\" + mail + "\\" + para;
                        yeniveri2 = id2 + "\\" + ad2 + "\\" + soyad2 + "\\" + sifre2 + "\\" + mail2 + "\\" + para2;
                        Update(id,yeniveri);
                        Update(id2,yeniveri2);
                        cout<<b3<<b3<<"Islem Basariyla Gerceklesti ";
                        cout<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\b\b\b\b";
                        for(char a : geciciPara){
                            cout<<" ";
                        }
                        for(char a : geciciPara){
                            cout<<"\b";
                        }
                        cout<<para<<"\n\n\n\n\n\n\n"<<b3<<system("pause");
                        goto menu;

                    }
                    else if(secim == '2'){
                        goto menu;
                    }
                    else{
                        goto secims2;
                    }
                }


            }
            else if(secim == '2'){
                goto para_gonder;
            }
            else{
                goto secims;
            }
        }
        else{
            cout<<b3<<"Kullanici Bulunamadi!         ";
            cout << "\x1b[A" <<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            for(char a : id2){
                cout<<" ";
            }
            for(char a : id2){
                cout<<"\b";
            }
            goto para_gonder2;

        }
    }
    else if(secim == '4'){
        string yeniAd,yeniSoyad,yeniMail,yeniSifre,yeniVeri;
        duzenle:
        system("cls");
        cout<<b3<<"Hesap Bilgisini Duzenle"<<b3<<"-----------------------";
        cout<<b3<<b3<<"1 - Ad"<<b3<<"2 - Soyad"<<b3<<"3 - Mail"<<b3<<"4 - Sifre";
        secim = getch();
        if(secim == '1'){

            system("cls");
            cout<<b3<<"Hesap Bilgisini Duzenle"<<b3<<"-----------------------";
            cout<<b3<<b3<<"Yeni Ad \t: ";
            yeniAd = getString(" ");
            if(yeniAd == "e s c")
                goto duzenle;
            cout<<b3<<b3<<"Adiniz ( "<<ad<<" ) , "<<yeniAd<<" Olarak Degistirilecektir."<<b3<<"Onayliyor musunuz ?";
            cout<<b3<<"1 - Evet\t2 - Hayir";
            secimAd:
            secim = getch();
            if(secim == '1'){
                yeniVeri = id + "\\" + yeniAd + "\\" + soyad + "\\" + sifre + "\\" + mail + "\\" + para;
                Update(id,yeniVeri);
                cout<<b3<<b3<<"Islem Basarili."<<b3<<system("pause");
                goto menu;

            }
            else if(secim == '2'){
               goto duzenle;
            }
            else{
                goto secimAd;
            }


        }
        else if(secim == '2'){
            system("cls");
            cout<<b3<<"Hesap Bilgisini Duzenle"<<b3<<"-----------------------";
            cout<<b3<<b3<<"Yeni Soyad \t: ";
            yeniSoyad = getString(" ");
            if(yeniSoyad == "e s c")
                goto duzenle;
            cout<<b3<<b3<<"Soyadiniz ( "<<soyad<<" ) , "<<yeniSoyad<<" Olarak Degistirilecektir."<<b3<<"Onayliyor musunuz ?";
            cout<<b3<<"1 - Evet\t2 - Hayir";
            secimSoyad:
            secim = getch();
            if(secim == '1'){
                yeniVeri = id + "\\" + ad + "\\" + yeniSoyad + "\\" + sifre + "\\" + mail + "\\" + para;
                Update(id,yeniVeri);
                cout<<b3<<b3<<"Islem Basarili."<<b3<<system("pause");
                goto menu;

            }
            else if(secim == '2'){
               goto duzenle;
            }
            else{
                goto secimSoyad;
            }
        }
        else if(secim == '3'){
            system("cls");
            cout<<b3<<"Hesap Bilgisini Duzenle"<<b3<<"-----------------------";
            cout<<b3<<b3<<"Yeni Mail \t: ";
            yeniMail = getString(" ");
            if(yeniMail == "e s c")
                goto duzenle;
            cout<<b3<<b3<<"Mailiniz ( "<<mail<<" ) , "<<yeniMail<<" Olarak Degistirilecektir."<<b3<<"Onayliyor musunuz ?";
            cout<<b3<<"1 - Evet\t2 - Hayir";
            secimMail:
            secim = getch();
            if(secim == '1'){
                string mailDurum = mailDogrulama(yeniMail);

                if(mailDurum == "true"){
                    yeniVeri = id + "\\" + ad + "\\" + soyad + "\\" + sifre + "\\" + yeniMail + "\\" + para;
                    Update(id,yeniVeri);
                    cout<<b3<<b3<<"Islem Basarili."<<b3<<system("pause");
                    goto menu;
                }
                else if(mailDurum == "error"){
                    cout<<b3<<b3<<"Hata Olustu ! Lutfen Bilgilerinizi Kontrol Edip Tekrar Deneyin";
                    cout<<b3<<system("pause");
                    goto menu;
                }
                else if(mailDurum == "false"){
                    cout<<b3<<b3<<"Yanlis Kod ! Islem Basarisiz";
                    cout<<b3<<system("pause");
                    goto menu;
                }




            }
            else if(secim == '2'){
               goto duzenle;
            }
            else{
                goto secimMail;
            }
        }
        else if(secim == '4'){

            string eskiSifre,yeniSifre2;
            system("cls");
            cout<<b3<<"Hesap Bilgisini Duzenle"<<b3<<"-----------------------";
            cout<<b3<<"Eski Sifre \t\t: ";
            cout<<b3<<"Yeni Sifre \t\t: ";
            cout<<b3<<"Yeni Sifre Tekrar\t: ";
            cout<<"\x1b[A"<<"\x1b[A";
            sifre_yenile:
            eskiSifre = getString("pass");
            if(eskiSifre == "e s c")
                goto menu;
            cout<<b3<<"\t\t\t\t\b\b\b\b\b\b";
            yeniSifre = getString("pass");
            if(yeniSifre == "e s c")
                goto menu;
            cout<<b3<<"\t\t\t\t\b\b\b\b\b\b";
            yeniSifre2 = getString("pass");
            if(yeniSifre2 == "e s c")
                goto menu;

            if(sifre != eskiSifre){

                cout<<b3<<"Eski Sifreniz Yanlis !                ";
                cout<<"\x1b[A"<<"\b\b\b\b\b\b\b\b\b\b\b\b";
                for(char a : yeniSifre2){
                    cout<<" ";
                }
                for(char a : yeniSifre2){
                    cout<<"\b";
                }

                cout<<"\x1b[A"<<"";
                for(char a : yeniSifre){
                    cout<<" ";
                }
                for(char a : yeniSifre){
                    cout<<"\b";
                }

                cout<<"\x1b[A"<<"";
                for(char a : eskiSifre){
                    cout<<" ";
                }
                for(char a : eskiSifre){
                    cout<<"\b";
                }

                goto sifre_yenile;
            }

            else if(yeniSifre != yeniSifre2){
                cout<<b3<<"Yeni Sifreleriniz Eslesmiyor !        ";
                cout<<"\x1b[A"<<"\b\b\b\b\b\b\b\b\b\b\b\b";
                for(char a : yeniSifre2){
                    cout<<" ";
                }
                for(char a : yeniSifre2){
                    cout<<"\b";
                }

                cout<<"\x1b[A"<<"";
                for(char a : yeniSifre){
                    cout<<" ";
                }
                for(char a : yeniSifre){
                    cout<<"\b";
                }

                cout<<"\x1b[A"<<"";
                for(char a : eskiSifre){
                    cout<<" ";
                }
                for(char a : eskiSifre){
                    cout<<"\b";
                }

                goto sifre_yenile;

            }
            else if(sifre == yeniSifre){
                cout<<b3<<"Yeni Sifre Eski Sifreyle Ayni Olamaz !";
                cout<<"\x1b[A"<<"\b\b\b\b\b\b\b\b\b\b\b\b";
                for(char a : yeniSifre2){
                    cout<<" ";
                }
                for(char a : yeniSifre2){
                    cout<<"\b";
                }

                cout<<"\x1b[A"<<"";
                for(char a : yeniSifre){
                    cout<<" ";
                }
                for(char a : yeniSifre){
                    cout<<"\b";
                }

                cout<<"\x1b[A"<<"";
                for(char a : eskiSifre){
                    cout<<" ";
                }
                for(char a : eskiSifre){
                    cout<<"\b";
                }

                goto sifre_yenile;

            }
            else{
                yeniVeri = id + "\\" + ad + "\\" + soyad + "\\" + yeniSifre + "\\" + mail + "\\" + para;
                Update(id,yeniVeri);
                cout<<b3<<"Sifreniz Basariyla Degisti        "<<b3<<system("pause");
                goto menu;
            }


        }
        else if(secim == 27)
            goto menu;
        else{
            goto duzenle;
        }
    }
    else if(secim == '5'){


        silme:
        system("cls");
        cout<<b3<<"Hesabinizi Silmek Istediginize Emin Misiniz ?";
        cout<<b3<<"1 - Evet\t2 - Hayir"<<b3;
        secim = getch();
        if(secim == '1'){
            system("cls");
            cout<<b3<<"Hesabiniz Kalici Olarak Silinecek Onayliyor Musunuz ?";
            cout<<b3<<"1 - Evet\t2 - Hayir"<<b3;
            silme2:
            secim = getch();
            if(secim == '1'){
                Update(id,"DELETED_USER");
                cout<<b3<<"Hesap Basariyla Silindi."<<b3<<system("pause");
                return 0;
            }
            else if(secim == '2'){
                goto menu;
            }
            else{
                goto silme2;
            }
        }
        else if(secim == '2'){
            goto menu;
        }
        else{
            goto silme;
        }

    }
    else if(secim == '6'){
        system("cls");
        listele();
        cout<<b3<<system("pause");
        goto menu;
    }
    else if(secim == '7'){
        system("cls");
        sorgu:
        string idSorgu,adS,soyadS,mailS,paraS;
        cout<<Esc<<b3<<"Kullanici Bilgilerini Goruntule";
        cout<<b3<<"-------------------------------";
        cout<<b3<<b3<<"ID\t: ";
        sorgu2:
        idSorgu = getString(" ");
        adS = getData(idSorgu,1);
        if(idSorgu == "e s c")
            goto menu;
        else if(adS == ""){
            cout<<b3<<"Kullanici Bulunamadi !";
            cout<<"\x1b[A"<<"\b\b\b\b\b\b\b\b\b\b\b\b";
            for(char a : idSorgu){
                cout<<" ";
            }
            for(char a : idSorgu){
                cout<<"\b";
            }
            goto sorgu2;
        }
        else{
            cout<<b3<<"Basarili                       ";
            cout<<b3<<b3<<"Kullanici Bilgileri";
            cout<<b3<<"-------------------";
            cout<<b3<<"ID\t: "<<getData(idSorgu,1)<<"                      ";
            cout<<b3<<"Ad\t: "<<getData(idSorgu,2)<<"                      ";
            cout<<b3<<"Soyad\t: "<<getData(idSorgu,3)<<"                      ";
            cout<<b3<<"Mail\t: "<<getData(idSorgu,5)<<"                      ";
            cout<<b3<<"Para\t: "<<getData(idSorgu,6)<<"                      ";
            cout<<b3<<"-------------------";
            cout<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A"<<"\x1b[A";
            cout<<"\b\b\b\b\b\b\b\b\b";
            for(char a : idSorgu){
                cout<<" ";
            }
            for(char a : idSorgu){
                cout<<"\b";
            }
            goto sorgu2;
        }



    }
    else{
        goto menu;
    }

}


int Update(string id,string yeniVeri){
    fstream dosya;
    string bigVeri = "";
    string satirVeri;
    string controlID;

    dosya.open("kullanicilar.txt",ios_base::in);

    for(int x = 0;x<stoi(getID())-1;x++){

        dosya>>satirVeri;
        controlID = "";

        for(char ctrl : satirVeri){
            if(ctrl == '\\'){
                    break;
            }
            else{
                controlID.push_back(ctrl);
            }
        }

        if(controlID != id){
            bigVeri += satirVeri + "\n";
            continue;
        }
        else{
            bigVeri += yeniVeri + "\n";
        }
    }
    dosya.close();

    dosya.open("kullanicilar.txt",ios_base::out);
    dosya<<bigVeri;

}

string listele(){
    fstream dosya;
    string veri;


    dosya.open("kullanicilar.txt",ios_base::in);

    for(int x = 0;x<stoi(getID())-1;x++){

        dosya>>veri;
        if(veri == "DELETED_USER")
            continue;
        int sayac = 0;
        string veriler[6] = {};
        cout<<b3<<"-------------------";
        for(char ch : veri){

            if(ch == '\\'){
                sayac++;
                continue;
            }
            else{
                veriler[sayac].push_back(ch);
            }
        }
        cout<<b3<<"ID\t: "<<veriler[0];
        cout<<b3<<"Ad\t: "<<veriler[1];
        cout<<b3<<"Soyad\t: "<<veriler[2];
        cout<<b3<<"Mail\t: "<<veriler[4];
        cout<<b3<<"Para\t: "<<veriler[5];
        cout<<b3<<"-------------------";

    }
    dosya.close();
    return "";
}


