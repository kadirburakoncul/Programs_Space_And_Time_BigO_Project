#include <stdio.h>
#include <stdlib.h>
void Dongu_Degisken_Kontrol(char Alinan_Satir[1000],char Toplam_Zaman_Karmasikligi_Char[1000],char Char_Kalinan_Yer1[1],char Kontrol_Char[1000],int Kontrol_Char_Kalinan_Yer[1],int Icice_Dongu[1],int Suslu_Sayisi[1],char Dongu_bagli_Degisken[1000],int Dongu_bagli_int[1],char Hangisi_Var[1],char Yer_Tutucu[100],int Yer_Tutucu_Int[1])
{
    char *dizi=(char*)malloc(sizeof(char)*100);
    int Kac_Tane_Kontrol_Elemani_Var=0;
    for(int k=0; k<Dongu_bagli_int[0]; k++)
    {
        int a=0;
        while(Dongu_bagli_Degisken[k]!='.')
        {
            dizi[a]=Dongu_bagli_Degisken[k];
            a++;
            k++;
        }
        int e=0;
        while(Alinan_Satir[e]!='\0')
        {
            int kontrol=0;
            int kontrol1=0;
            for(int y=0; y<a; y++)
            {
                if(dizi[y]==Alinan_Satir[e])
                {
                    kontrol++;
                    e++;
                    if(kontrol==a)
                    {
                        if(Alinan_Satir[e-kontrol-1]=='-' && Alinan_Satir[e-kontrol-2]=='-' && Alinan_Satir[e-kontrol-3]!='=')
                        {
                            Hangisi_Var[0]='-';
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            Yer_Tutucu_Int[0]=0;
                        }
                        if(Alinan_Satir[e-kontrol-1]=='+' && Alinan_Satir[e-kontrol-2]=='+' && Alinan_Satir[e-kontrol-3]!='=')
                        {
                            Hangisi_Var[0]='+';
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            Yer_Tutucu_Int[0]=0;
                        }
                        if(Alinan_Satir[e]=='+' && Alinan_Satir[e+1]=='+' && Alinan_Satir[e+2]==';')
                        {
                            Hangisi_Var[0]='+';
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            Yer_Tutucu_Int[0]=0;
                        }
                        else if(Alinan_Satir[e]=='-' && Alinan_Satir[e+1]=='-' && Alinan_Satir[e+2]==';')
                        {
                            Hangisi_Var[0]='-';
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            Yer_Tutucu_Int[0]=0;
                        }
                        else if(Alinan_Satir[e]=='=')
                        {
                            e++;
                            for(int y=0; y<a; y++)
                            {
                                if(dizi[y]==Alinan_Satir[e])
                                {
                                    kontrol1++;
                                    e++;
                                    if(kontrol1==a)
                                    {
                                        if(Alinan_Satir[e]=='*')
                                        {
                                            while(Alinan_Satir[e]!=';' && Alinan_Satir[e]!=')' && Alinan_Satir[e]!='\0')
                                            {
                                                if(Alinan_Satir[e]>=48 && Alinan_Satir[e]<=57)
                                                {
                                                    Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[e];
                                                    Yer_Tutucu_Int[0]++;
                                                }
                                                e++;
                                            }
                                            Hangisi_Var[0]='*';
                                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                            Yer_Tutucu_Int[0]=0;
                                        }
                                        else if(Alinan_Satir[e]=='/')
                                        {
                                            while(Alinan_Satir[e]!=';' && Alinan_Satir[e]!=')' && Alinan_Satir[e]!='\0')
                                            {
                                                if(Alinan_Satir[e]>=48 && Alinan_Satir[e]<=57)
                                                {
                                                    Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[e];
                                                    Yer_Tutucu_Int[0]++;
                                                }
                                                e++;
                                            }
                                            Hangisi_Var[0]='/';
                                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                            Yer_Tutucu_Int[0]=0;
                                        }
                                        else if(Alinan_Satir[e]=='+')
                                        {
                                            Hangisi_Var[0]='+';
                                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                            Yer_Tutucu_Int[0]=0;
                                        }
                                        else if(Alinan_Satir[e]=='-')
                                        {
                                            while(Alinan_Satir[e]!=';' && Alinan_Satir[e]!=')' && Alinan_Satir[e]!='\0')
                                            {
                                                if(Alinan_Satir[e]>=48 && Alinan_Satir[e]<=57)
                                                {
                                                    Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[e];
                                                    Yer_Tutucu_Int[0]++;
                                                }
                                                e++;
                                            }
                                            Hangisi_Var[0]='-';
                                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                            Yer_Tutucu_Int[0]=0;
                                        }
                                        else if(Alinan_Satir[e]==';')
                                        {
                                            int y=e-kontrol-1;
                                            if(Alinan_Satir[y]=='+' || Alinan_Satir[y]=='-' || Alinan_Satir[y]=='*' || Alinan_Satir[y]=='/')
                                            {
                                                if(Alinan_Satir[y]=='+')
                                                {
                                                    Hangisi_Var[0]='+';
                                                }
                                                else if(Alinan_Satir[y]=='-')
                                                {
                                                    Hangisi_Var[0]='-';
                                                }
                                                else if(Alinan_Satir[y]=='*')
                                                {
                                                    Hangisi_Var[0]='*';
                                                }
                                                else if(Alinan_Satir[y]=='/')
                                                {
                                                    Hangisi_Var[0]='/';
                                                }
                                                y--;
                                                int kont=0;
                                                while(Alinan_Satir[y]>=48 && Alinan_Satir[y]<=57)
                                                {
                                                    kont++;
                                                    y--;
                                                }
                                                int kont1=y+1;
                                                while(kont!=0)
                                                {
                                                    Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[kont1];
                                                    Yer_Tutucu_Int[0]++;
                                                    kont--;
                                                    kont1++;
                                                }
                                                if(Alinan_Satir[y]=='=' || y==0 || Alinan_Satir[y]==' ')
                                                {
                                                    For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                                    Yer_Tutucu_Int[0]=0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            //
                            while(Alinan_Satir[e]>=48 && Alinan_Satir[e]<=57)
                            {
                                Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[e];
                                Yer_Tutucu_Int[0]++;
                                e++;
                            }
                            if(Alinan_Satir[e]=='*')
                            {
                                Hangisi_Var[0]='*';
                                For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                Yer_Tutucu_Int[0]=0;
                            }
                            if(Alinan_Satir[e]=='/')
                            {
                                Hangisi_Var[0]='/';
                                For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                Yer_Tutucu_Int[0]=0;
                            }
                            if(Alinan_Satir[e]=='+')
                            {
                                Hangisi_Var[0]='+';
                                For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                Yer_Tutucu_Int[0]=0;
                            }
                            if(Alinan_Satir[e]=='-')
                            {
                                Hangisi_Var[0]='-';
                                For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                                Yer_Tutucu_Int[0]=0;
                            }
                            //
                            //
                        }
                        else if(Alinan_Satir[e]=='=')
                        {
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            e++;
        }
    }
    return 0;
}
void Dongu_Degiskenlerini_Tut(char Alinan_Satir[1000],char Toplam_Zaman_Karmasikligi_Char[1000],char Char_Kalinan_Yer1[1],char Kontrol_Char[1000],int Kontrol_Char_Kalinan_Yer[1],int Icice_Dongu[1],int Suslu_Sayisi[1],char Dongu_bagli_Degisken[1000],int Dongu_bagli_int[1],int k)
{
    int y=k-1;
    while(Alinan_Satir[y]!=';' && Alinan_Satir[y]!='=' && Alinan_Satir[y]!=' ')
    {
        y--;
    }
    y++;
    while(Alinan_Satir[y]!='+' && Alinan_Satir[y]!='-' && Alinan_Satir[y]!='/' && Alinan_Satir[y]!='*')
    {
        Dongu_bagli_Degisken[Dongu_bagli_int[0]]=Alinan_Satir[y];
        Dongu_bagli_int[0]++;
        y++;
    }
    Dongu_bagli_Degisken[Dongu_bagli_int[0]]='.';
    Dongu_bagli_int[0]++;
}
void Dongu_Degiskenlerini_Tut1(char Alinan_Satir[1000],char Toplam_Zaman_Karmasikligi_Char[1000],char Char_Kalinan_Yer1[1],char Kontrol_Char[1000],int Kontrol_Char_Kalinan_Yer[1],int Icice_Dongu[1],int Suslu_Sayisi[1],char Dongu_bagli_Degisken[1000],int Dongu_bagli_int[1],int k,char kontrol)
{
    int y=k;
    if(kontrol=='<')
    {
        while(Alinan_Satir[y]!='(' && Alinan_Satir[y]!='=' && Alinan_Satir[y]!=' ')
        {
            y--;
        }
        y++;
        while(Alinan_Satir[y]!='<')
        {
            Dongu_bagli_Degisken[Dongu_bagli_int[0]]=Alinan_Satir[y];
            Dongu_bagli_int[0]++;
            y++;
        }
        Dongu_bagli_Degisken[Dongu_bagli_int[0]]='.';
        Dongu_bagli_int[0]++;
        return 0;
    }
    else if(kontrol=='>')
    {
        if(Alinan_Satir[y+1]!='=')
        {
            y++;
            while(Alinan_Satir[y]!=')' && Alinan_Satir[y]!=' ')
            {
                Dongu_bagli_Degisken[Dongu_bagli_int[0]]=Alinan_Satir[y];
                Dongu_bagli_int[0]++;
                y++;
            }
            Dongu_bagli_Degisken[Dongu_bagli_int[0]]='.';
            Dongu_bagli_int[0]++;
            return 0;
        }
        else
        {
            while(Alinan_Satir[y]!=')' && Alinan_Satir[y]!=' ')
            {
                Dongu_bagli_Degisken[Dongu_bagli_int[0]]=Alinan_Satir[y];
                Dongu_bagli_int[0]++;
                y++;
            }
            Dongu_bagli_Degisken[Dongu_bagli_int[0]]='.';
            Dongu_bagli_int[0]++;
            return 0;
        }
    }
    return 0;
}
void For_Ici_Kontrol(char Toplam_Zaman_Karmasikligi_Char[1000],char Char_Kalinan_Yer1[1],char Yer_Tutucu[100],char Hangisi_Var[1],int Yer_Tutucu_Int[1],int Icice_Dongu[1])
{
    if(Hangisi_Var[0]=='+' || Hangisi_Var[0]=='-')
    {
        if(Icice_Dongu[0]==0)
        {
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='N';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
        }
        else
        {
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='*';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='N';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
        }
        return 0;
    }
    if(Hangisi_Var[0]=='/')
    {
        if(Icice_Dongu[0]==0)
        {
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='l';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='o';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='g';
            Char_Kalinan_Yer1[0]++;
            if(Yer_Tutucu_Int[0]==0)
            {
                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='2';
                Char_Kalinan_Yer1[0]++;
            }
            else
            {
                for(int k=0; k<Yer_Tutucu_Int[0]; k++)
                {
                    Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=Yer_Tutucu[k];
                    Char_Kalinan_Yer1[0]++;
                }
            }
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='N';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            return 0;
        }
        else
        {
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='*';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='l';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='o';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='g';
            Char_Kalinan_Yer1[0]++;
            if(Yer_Tutucu_Int[0]==0)
            {
                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='2';
                Char_Kalinan_Yer1[0]++;
            }
            else
            {
                for(int k=0; k<Yer_Tutucu_Int[0]; k++)
                {
                    Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=Yer_Tutucu[k];
                    Char_Kalinan_Yer1[0]++;
                }
            }
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='N';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            return 0;
        }
    }
    else if(Hangisi_Var[0]=='*')
    {
        if(Icice_Dongu[0]==0)
        {
            if(Yer_Tutucu_Int[0]==0)
            {
                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='2';
                Char_Kalinan_Yer1[0]++;
            }
            else
            {
                for(int k=0; k<Yer_Tutucu_Int[0]; k++)
                {
                    Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=Yer_Tutucu[k];
                    Char_Kalinan_Yer1[0]++;
                }
            }
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='^';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='N';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            return 0;
        }
        else
        {
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='*';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            if(Yer_Tutucu_Int[0]==0)
            {
                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='2';
                Char_Kalinan_Yer1[0]++;
            }
            else
            {
                for(int k=0; k<Yer_Tutucu_Int[0]; k++)
                {
                    Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=Yer_Tutucu[k];
                    Char_Kalinan_Yer1[0]++;
                }
            }
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='^';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='N';
            Char_Kalinan_Yer1[0]++;
            Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
            Char_Kalinan_Yer1[0]++;
            return 0;
        }
    }
    return 0;
}
void Suslu_Hesaplayici(char Alinan_Satir[1000],char Toplam_Zaman_Karmasikligi_Char[1000],char Char_Kalinan_Yer1[1],char Kontrol_Char[1000],int Kontrol_Char_Kalinan_Yer[1],int Icice_Dongu[1],int Suslu_Sayisi[1])
{
    int k=0;
    while(Alinan_Satir[k]!='\0')
    {
        if(Alinan_Satir[k]=='{')
        {
            Suslu_Sayisi[0]=Suslu_Sayisi[0]+1;
        }
        else if(Alinan_Satir[k]=='}')
        {
            Suslu_Sayisi[0]=Suslu_Sayisi[0]-1;
        }
        k++;
    }
}
void Zaman_Karmasikligi_Hesaplayici(char Alinan_Satir[1000],char Toplam_Zaman_Karmasikligi_Char[1000],char Char_Kalinan_Yer1[1],char Kontrol_Char[1000],int Kontrol_Char_Kalinan_Yer[1],int Icice_Dongu[1],int Suslu_Sayisi[1],char Dongu_bagli_Degisken[1000],int Dongu_bagli_int[1],int Kacinic_Satir[1])
{
    char *Hangisi_Var=(char*)malloc(sizeof(char)*1);
    char *Yer_Tutucu=(char*)malloc(sizeof(char)*100);
    int *Yer_Tutucu_Int=(int*)malloc(sizeof(int)*1);
    Yer_Tutucu_Int[0]=0;
    int k=0;
    int Noktali_Virgul_Sayimi=0;
    if(Icice_Dongu!=0)
    {
        Dongu_Degisken_Kontrol(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,Hangisi_Var,Yer_Tutucu,Yer_Tutucu_Int);
        Yer_Tutucu_Int[0]=0;
    }
    Yer_Tutucu_Int[0]=0;
    while(Alinan_Satir[k]!='\0')
    {
        if(Alinan_Satir[k]=='f' && Alinan_Satir[k+1]=='o' && Alinan_Satir[k+2]=='r')
        {
            if(Alinan_Satir[k+3]=='(' || Alinan_Satir[k+3]==' ')
            {
                k=k+2;
                while(Alinan_Satir[k]!=')')
                {
                    if(Noktali_Virgul_Sayimi==2)
                    {
                        k++;
                        while(Alinan_Satir[k]!=')')
                        {
                            if(Alinan_Satir[k]=='+' && Alinan_Satir[k+1]=='+')
                            {
                                Dongu_Degiskenlerini_Tut(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,k);
                                Hangisi_Var[0]='+';
                            }
                            else if(Alinan_Satir[k]=='-' && Alinan_Satir[k+1]=='-')
                            {
                                Dongu_Degiskenlerini_Tut(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,k);
                                Hangisi_Var[0]='-';
                            }
                            if(Alinan_Satir[k]>=48 && Alinan_Satir[k]<=57)
                            {
                                Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[k];
                                Yer_Tutucu_Int[0]++;
                            }
                            else if(Alinan_Satir[k]=='/')
                            {
                                Dongu_Degiskenlerini_Tut(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,k);
                                Hangisi_Var[0]='/';
                            }
                            else if(Alinan_Satir[k]=='*')
                            {
                                Dongu_Degiskenlerini_Tut(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,k);
                                Hangisi_Var[0]='*';
                            }
                            k++;
                        }
                        For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                        Icice_Dongu[0]=Icice_Dongu[0]+1;
                        return 0;
                    }
                    else if(Alinan_Satir[k]==';')
                    {
                        Noktali_Virgul_Sayimi++;
                    }
                    k++;
                }
            }
        }
        else if(Alinan_Satir[k]=='w' && Alinan_Satir[k+1]=='h' && Alinan_Satir[k+2]=='i'  && Alinan_Satir[k+3]=='l' && Alinan_Satir[k+4]=='e')
        {
            if(Alinan_Satir[k+5]=='(' || Alinan_Satir[k+5]==' ')
            {
                int Do_Mu_Kontrol_Et=0;
                int y=k+4;
                while(Alinan_Satir[y]!='\0' && Alinan_Satir[y+1]!='\0')
                {
                    if(Alinan_Satir[y]==')' && Alinan_Satir[y+1]==';')
                    {
                        Do_Mu_Kontrol_Et=1;
                        break;
                    }
                    y++;
                }
                if(Do_Mu_Kontrol_Et==0)
                {
                    k=k+4;
                    while(Alinan_Satir[k]!=')')
                    {
                        k++;
                        while(Alinan_Satir[k]!=')')
                        {
                            if(Alinan_Satir[k]=='<')
                            {
                                Dongu_Degiskenlerini_Tut1(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,k,'<');
                            }
                            else if(Alinan_Satir[k]=='>')
                            {
                                Dongu_Degiskenlerini_Tut1(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,k,'>');
                            }
                            k++;
                        }
                        Icice_Dongu[0]=Icice_Dongu[0]+1;
                        return 0;
                        k++;
                    }
                }
            }
        }
        else if(Alinan_Satir[k]=='d' && Alinan_Satir[k+1]=='o')
        {
            if(Alinan_Satir[k+2]=='\0' || Alinan_Satir[k+2]=='{')
            {
                Icice_Dongu[0]=Icice_Dongu[0]+1;
            }
            k=k+1;
            char Kontrol_Alinan_Satir[1000];
            int f=0;
            int Do_While_Bulundu=0;
            int Kacinci_Satir_Int=0;
            FILE *dosya1;
            dosya1=fopen("input.txt","r");
            while(!feof(dosya1))
            {
                f=0;
                fgets(Kontrol_Alinan_Satir, 1000, dosya1);
                if(Kacinic_Satir[0]<Kacinci_Satir_Int)
                {
                    //
                    while(Kontrol_Alinan_Satir[f]!='\0' && Kontrol_Alinan_Satir[f+5]!='\0')
                    {
                        if(Kontrol_Alinan_Satir[f]=='w' && Kontrol_Alinan_Satir[f+1]=='h' && Kontrol_Alinan_Satir[f+2]=='i'  && Kontrol_Alinan_Satir[f+3]=='l' && Kontrol_Alinan_Satir[f+4]=='e')
                        {
                            int m=f;
                            while(Kontrol_Alinan_Satir[m]!='\0')
                            {
                                if(Kontrol_Alinan_Satir[m]==')' && Kontrol_Alinan_Satir[m+1]==';')
                                {
                                    Do_While_Bulundu=1;
                                    break;
                                }
                                m++;
                            }
                            if(Do_While_Bulundu==1)
                            {
                                f=f+4;
                                while(Kontrol_Alinan_Satir[f]!=')')
                                {
                                    f++;
                                    while(Kontrol_Alinan_Satir[f]!=')')
                                    {
                                        if(Kontrol_Alinan_Satir[f]=='<')
                                        {
                                            //Icice_Dongu[0]=Icice_Dongu[0]+1;
                                            Dongu_Degiskenlerini_Tut1(Kontrol_Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,f,'<');
                                        }
                                        else if(Kontrol_Alinan_Satir[f]=='>')
                                        {
                                            //Icice_Dongu[0]=Icice_Dongu[0]+1;
                                            Dongu_Degiskenlerini_Tut1(Kontrol_Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,f,'>');
                                        }
                                        f++;
                                    }
                                    fclose(dosya1);
                                    Kacinic_Satir[0]=0;
                                    Do_While_Bulundu=0;
                                    return 0;
                                    f++;
                                }
                            }
                        }
                        f++;
                    }
                    Kacinci_Satir_Int++;
                }
                else
                {
                    Kacinci_Satir_Int++;
                }
            }
            fclose(dosya1);
            Kacinic_Satir[0]=0;
        }
        else if(Alinan_Satir[k]=='r' && Alinan_Satir[k+1]=='e' && Alinan_Satir[k+2]=='t' && Alinan_Satir[k+3]=='u'&& Alinan_Satir[k+4]=='r' && Alinan_Satir[k+5]=='n' && Alinan_Satir[k+6]==' ')
        {
            int er=k+7;
            while(Alinan_Satir[er]!='\0')
            {
                if(Alinan_Satir[er]=='(')
                {
                    while(Alinan_Satir[er]!='\0')
                    {
                        if(Alinan_Satir[er]=='+')
                        {
                            Hangisi_Var[0]='+';
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            if(Suslu_Sayisi[0]==0)
                            {
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='+';
                                Char_Kalinan_Yer1[0]++;
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
                                Char_Kalinan_Yer1[0]++;
                            }
                        }
                        else if(Alinan_Satir[er]=='-')
                        {
                            Hangisi_Var[0]='-';
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            if(Suslu_Sayisi[0]==0)
                            {
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='+';
                                Char_Kalinan_Yer1[0]++;
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
                                Char_Kalinan_Yer1[0]++;
                            }
                        }
                        else if(Alinan_Satir[er]=='*')
                        {
                            er++;
                            Hangisi_Var[0]='*';
                            while(Alinan_Satir[er]>=48 && Alinan_Satir[er]<=57)
                            {
                                Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[er];
                                Yer_Tutucu_Int[0]++;
                                er++;
                            }
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            if(Suslu_Sayisi[0]==0)
                            {
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='+';
                                Char_Kalinan_Yer1[0]++;
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
                                Char_Kalinan_Yer1[0]++;
                            }
                        }
                        else if(Alinan_Satir[er]=='/')
                        {
                            er++;
                            Hangisi_Var[0]='/';
                            while(Alinan_Satir[er]>=48 && Alinan_Satir[er]<=57)
                            {
                                Yer_Tutucu[Yer_Tutucu_Int[0]]=Alinan_Satir[er];
                                Yer_Tutucu_Int[0]++;
                                er++;
                            }
                            For_Ici_Kontrol(Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Yer_Tutucu,Hangisi_Var,Yer_Tutucu_Int,Icice_Dongu);
                            if(Suslu_Sayisi[0]==0)
                            {
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='+';
                                Char_Kalinan_Yer1[0]++;
                                Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
                                Char_Kalinan_Yer1[0]++;
                            }
                        }
                        er++;
                    }
                }
                er++;
            }
        }
        k++;
    }
}
void Yazi_Yazdirma(int Dizi_Elemani)
{
    if(Dizi_Elemani==0)
    {
        printf("\n\t --> Buradaki bool Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==1)
    {
        printf("\n\t --> Buradaki char Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==2)
    {
        printf("\n\t --> Buradaki unsigned char Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==3)
    {
        printf("\n\t --> Buradaki __int8 Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==4)
    {
        printf("\n\t --> Buradaki __int16 Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==5)
    {
        printf("\n\t --> Buradaki short Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==6)
    {
        printf("\n\t --> Buradaki unsigned short Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==7)
    {
        printf("\n\t --> Buradaki float Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==8)
    {
        printf("\n\t --> Buradaki int Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==9)
    {
        printf("\n\t --> Buradaki long Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==10)
    {
        printf("\n\t --> Buradaki unsigned int Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==11)
    {
        printf("\n\t --> Buradaki __int32 Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==12)
    {
        printf("\n\t --> Buradaki double Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==13)
    {
        printf("\n\t --> Buradaki __int64 Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==14)
    {
        printf("\n\t --> Buradaki long double Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==15)
    {
        printf("\n\t --> Buradaki long long Hafiza Karmasikligi ");
    }
    else if(Dizi_Elemani==15)
    {
        printf("\n\t --> Buradaki return Hafiza Karmasikligi ");
    }
    return 0;
}
void Hesaplayici2(char Alinan_Satir[1000],int Toplam_Deger_Tutucu[16],int Toplam_Dizi_Deger_Tutucu[16],int Toplam_Hafiza_Karmasikligi[1],char Toplam_Hafiza_Karmasikligi_Char[1000],int Char_Kalinan_Yer[1],int Dizi_Elemani,int a,int fonk_icinde)
{
    int kontrol2=0;
    int kontrol=0;
    int k=a;
    int Kaclik_Alan_Tutuyor=0;
    int sayi=0;
    int sayi2=1;
    if(Dizi_Elemani>=0 && Dizi_Elemani<=3)
    {
        Kaclik_Alan_Tutuyor=1;
    }
    else if(Dizi_Elemani>=4 && Dizi_Elemani<=6)
    {
        Kaclik_Alan_Tutuyor=2;
    }
    else if(Dizi_Elemani>=7 && Dizi_Elemani<=11)
    {
        Kaclik_Alan_Tutuyor=4;
    }
    else if(Dizi_Elemani>=12 && Dizi_Elemani<=15)
    {
        Kaclik_Alan_Tutuyor=8;
    }
    else if(Dizi_Elemani==16)
    {
        Kaclik_Alan_Tutuyor=1;
    }
    while(Alinan_Satir[a]!='\0')
    {
        kontrol2=0;
        kontrol=Char_Kalinan_Yer[0];
        sayi=0;
        if(Dizi_Elemani==16)
        {
            Yazi_Yazdirma(Dizi_Elemani);
            printf("Degisken Oldugu Icin %d Kadar Alan Kaplar.",Kaclik_Alan_Tutuyor);
            Toplam_Hafiza_Karmasikligi[0]=Toplam_Hafiza_Karmasikligi[0]+(Kaclik_Alan_Tutuyor);
            printf("\t Toplam Hafiza Karmasikligi = %d \n",Toplam_Hafiza_Karmasikligi[0]);
            Toplam_Deger_Tutucu[Dizi_Elemani]++;
            Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,0);
            return 0;
        }
        if(Alinan_Satir[a]=='(')
        {
            Yazi_Yazdirma(Dizi_Elemani);
            printf("Fonksiyon Oldugu Icin Sayilmaz.\n");
            Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,1);
            return 0;
        }
        if(Alinan_Satir[a]=='[')
        {
            Yazi_Yazdirma(Dizi_Elemani);
            printf("Dizi Oldugu Icin ");
            a++;
            while(Alinan_Satir[a]!='\0')
            {
                if(Alinan_Satir[a]==']' && Alinan_Satir[a+1]=='[')
                {
                    Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]='N';////////
                    Char_Kalinan_Yer[0]++;///////////
                    kontrol2=1;///////////
                    if(kontrol2==1)
                    {
                        Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]='*';
                        Char_Kalinan_Yer[0]++;
                    }
                    sayi2=sayi2*sayi;
                    sayi=0;
                    a=a+2;
                }
                else if(Alinan_Satir[a]==']')
                {
                    Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]='N';/////////////////
                    Char_Kalinan_Yer[0]++;///////////////
                    kontrol2=1;/////////////////
                    if(Alinan_Satir[a+1]==')' || Alinan_Satir[a+1]==','|| Alinan_Satir[a+1]==';')
                    {
                        if(kontrol2==1)
                        {
                            Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]='*';
                            Char_Kalinan_Yer[0]++;
                            Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]=Kaclik_Alan_Tutuyor+48;
                            Char_Kalinan_Yer[0]++;
                            Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]=' ';
                            Char_Kalinan_Yer[0]++;
                            Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]='+';
                            Char_Kalinan_Yer[0]++;
                            Toplam_Hafiza_Karmasikligi_Char[Char_Kalinan_Yer[0]]=' ';
                            Char_Kalinan_Yer[0]++;
                        }
                        if(sayi2!=1)
                        {
                            sayi2=sayi2*sayi;
                            sayi=0;
                        }
                        break;
                    }
                }
                a++;
            }
            if(kontrol!=Char_Kalinan_Yer[0])
            {
                printf("Dizi Boyutu Yani ");
                for(int w=kontrol; w<Char_Kalinan_Yer[0]; w++)
                {
                    printf("%c",Toplam_Hafiza_Karmasikligi_Char[w]);
                }
                printf(" Kadar Alan Kaplar.");
            }
            else if(sayi2==1)
            {
                printf("Dizi Boyutu Yani %d * %d = %d Kadar Alan Kaplar.",sayi,Kaclik_Alan_Tutuyor,sayi*Kaclik_Alan_Tutuyor);
                Toplam_Hafiza_Karmasikligi[0]=Toplam_Hafiza_Karmasikligi[0]+(sayi*Kaclik_Alan_Tutuyor);
            }
            else
            {
                printf("Dizi Boyutu Yani %d * %d = %d Kadar Alan Kaplar.",sayi2,Kaclik_Alan_Tutuyor,sayi2*Kaclik_Alan_Tutuyor);
                Toplam_Hafiza_Karmasikligi[0]=Toplam_Hafiza_Karmasikligi[0]+(sayi2*Kaclik_Alan_Tutuyor);
                if(Alinan_Satir[a+1]==',')
                {
                    sayi2=1;
                }
            }
            printf("\t Toplam Hafiza Karmasikligi = %d \n",Toplam_Hafiza_Karmasikligi[0]);
            if(Alinan_Satir[a]==']' && Alinan_Satir[a+1]==',')
            {
                Toplam_Dizi_Deger_Tutucu[Dizi_Elemani]++;
                if(fonk_icinde==1)
                {
                    Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,fonk_icinde);
                    return 0;
                }
                a=a+2;
            }
            if(Alinan_Satir[a]==']' && Alinan_Satir[a+1]==';')
            {
                Toplam_Dizi_Deger_Tutucu[Dizi_Elemani]++;
                Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,0);
                return 0;
            }
            if(Alinan_Satir[a]==']' && Alinan_Satir[a+1]==')')
            {
                Toplam_Dizi_Deger_Tutucu[Dizi_Elemani]++;
                Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,0);
                return 0;
            }
        }
        if(Alinan_Satir[a]==',')
        {
            Yazi_Yazdirma(Dizi_Elemani);
            printf("Degisken Oldugu Icin %d Kadar Alan Kaplar.",Kaclik_Alan_Tutuyor);
            Toplam_Hafiza_Karmasikligi[0]=Toplam_Hafiza_Karmasikligi[0]+(Kaclik_Alan_Tutuyor);
            printf("\t Toplam Hafiza Karmasikligi = %d \n",Toplam_Hafiza_Karmasikligi[0]);
            Toplam_Deger_Tutucu[Dizi_Elemani]++;
            if(fonk_icinde==1)
            {
                Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,fonk_icinde);
                return 0;
            }
        }
        if(Alinan_Satir[a]==';')
        {
            Yazi_Yazdirma(Dizi_Elemani);
            printf("Degisken Oldugu Icin %d Kadar Alan Kaplar.",Kaclik_Alan_Tutuyor);
            Toplam_Hafiza_Karmasikligi[0]=Toplam_Hafiza_Karmasikligi[0]+(Kaclik_Alan_Tutuyor);
            printf("\t Toplam Hafiza Karmasikligi = %d \n",Toplam_Hafiza_Karmasikligi[0]);
            Toplam_Deger_Tutucu[Dizi_Elemani]++;
            Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,0);
            return 0;
        }
        if(Alinan_Satir[a]==')')
        {
            Yazi_Yazdirma(Dizi_Elemani);
            printf("Degisken Oldugu Icin %d Kadar Alan Kaplar.",Kaclik_Alan_Tutuyor);
            Toplam_Hafiza_Karmasikligi[0]=Toplam_Hafiza_Karmasikligi[0]+(Kaclik_Alan_Tutuyor);
            printf("\t Toplam Hafiza Karmasikligi = %d \n\n",Toplam_Hafiza_Karmasikligi[0]);
            Toplam_Deger_Tutucu[Dizi_Elemani]++;
            Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,a+1,0);
            return 0;
        }
        a++;
    }
}
void Hesaplayici(char Alinan_Satir[1000],int Toplam_Deger_Tutucu[16],int Toplam_Dizi_Deger_Tutucu[16],int Toplam_Hafiza_Karmasikligi[1],char Toplam_Hafiza_Karmasikligi_Char[1000],int Char_Kalinan_Yer[1],int k,int fonk_icinde)
{
    while(Alinan_Satir[k]!='\0')
    {
        if(Alinan_Satir[k]=='(')
        {
            fonk_icinde=1;
        }
        if(Alinan_Satir[k]==')')
        {
            fonk_icinde=0;
        }
        //boll Kontrol=0
        if(Alinan_Satir[k]=='b' && Alinan_Satir[k+1]=='o' && Alinan_Satir[k+2]=='o' && Alinan_Satir[k+3]=='l' && Alinan_Satir[k+4]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,0,k,fonk_icinde);
            return 0;
        }//char Kontrol=1
        if(Alinan_Satir[k]=='c' && Alinan_Satir[k+1]=='h' && Alinan_Satir[k+2]=='a' && Alinan_Satir[k+3]=='r' && Alinan_Satir[k+4]==' ')
        {
            if(k>=9)
            {
                if(Alinan_Satir[k-1]==' ' && Alinan_Satir[k-9]=='u' && Alinan_Satir[k-6]=='i' && Alinan_Satir[k-4]=='n' && Alinan_Satir[k-2]=='d')
                {
                    break;
                }
            }
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,1,k,fonk_icinde);
            return 0;
        }//long long Kontrol=15
        if(Alinan_Satir[k]=='l' && Alinan_Satir[k+1]=='o' && Alinan_Satir[k+2]=='n' && Alinan_Satir[k+3]=='g' && Alinan_Satir[k+4]==' ')
        {
            if(Alinan_Satir[k+5]=='l' && Alinan_Satir[k+6]=='o' && Alinan_Satir[k+7]=='n' && Alinan_Satir[k+8]=='g' && Alinan_Satir[k+9]==' ')
            {
                Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,15,k,fonk_icinde);
                return 0;
            }
        }//long double Kontrol=14
        if(Alinan_Satir[k]=='l' && Alinan_Satir[k+1]=='o' && Alinan_Satir[k+2]=='n' && Alinan_Satir[k+3]=='g' && Alinan_Satir[k+4]==' ')
        {
            if(Alinan_Satir[k+5]=='d' && Alinan_Satir[k+6]=='o' && Alinan_Satir[k+7]=='u' && Alinan_Satir[k+8]=='b' && Alinan_Satir[k+9]=='l' && Alinan_Satir[k+10]=='e' && Alinan_Satir[k+11]==' ')
            {
                Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,14,k,fonk_icinde);
                return 0;
            }
        }//long Kontrolu=9
        if(Alinan_Satir[k]=='l' && Alinan_Satir[k+1]=='o' && Alinan_Satir[k+2]=='n' && Alinan_Satir[k+3]=='g' && Alinan_Satir[k+4]==' ')
        {
            if(Alinan_Satir[k+5]=='l' && Alinan_Satir[k+6]=='o' && Alinan_Satir[k+7]=='n' && Alinan_Satir[k+8]=='g' && Alinan_Satir[k+9]==' ')
            {
                break;
            }
            else if(Alinan_Satir[k+5]=='d' && Alinan_Satir[k+6]=='o' && Alinan_Satir[k+7]=='u' && Alinan_Satir[k+8]=='b' && Alinan_Satir[k+9]=='l' && Alinan_Satir[k+10]=='e' && Alinan_Satir[k+11]==' ')
            {
                break;
            }
            else
            {
                Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,9,k,fonk_icinde);
                return 0;
            }
        }//float kontrolu=7
        if(Alinan_Satir[k]=='f' && Alinan_Satir[k+1]=='l' && Alinan_Satir[k+2]=='o' && Alinan_Satir[k+3]=='a' && Alinan_Satir[k+4]=='t' && Alinan_Satir[k+5]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,7,k,fonk_icinde);
            return 0;
        }//double Kontrol=12
        if(Alinan_Satir[k]=='d' && Alinan_Satir[k+1]=='o' && Alinan_Satir[k+2]=='u' && Alinan_Satir[k+3]=='b' && Alinan_Satir[k+4]=='l' && Alinan_Satir[k+5]=='e' && Alinan_Satir[k+6]==' ')
        {
            if(k>=5)
            {
                if(Alinan_Satir[k-1]==' ' && Alinan_Satir[k-5]=='l' && Alinan_Satir[k-4]=='o' && Alinan_Satir[k-3]=='n' && Alinan_Satir[k-2]=='g' )
                {
                    break;
                }
            }
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,12,k,fonk_icinde);
            return 0;
        }//short Kontrol=5
        if(Alinan_Satir[k]=='s' && Alinan_Satir[k+1]=='h' && Alinan_Satir[k+2]=='o' && Alinan_Satir[k+3]=='r' && Alinan_Satir[k+4]=='t' && Alinan_Satir[k+5]==' ')
        {
            if(k>=9)
            {
                if(Alinan_Satir[k-1]==' ' && Alinan_Satir[k-9]=='u' && Alinan_Satir[k-6]=='i' && Alinan_Satir[k-4]=='n' && Alinan_Satir[k-2]=='d' )
                {
                    break;
                }
            }
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,5,k,fonk_icinde);
            return 0;
        }//unsigned Kontrolleri
        if(Alinan_Satir[k]=='u' && Alinan_Satir[k+1]=='n' && Alinan_Satir[k+2]=='s' && Alinan_Satir[k+3]=='i' && Alinan_Satir[k+4]=='g' && Alinan_Satir[k+5]=='n' && Alinan_Satir[k+6]=='e' && Alinan_Satir[k+7]=='d' && Alinan_Satir[k+8]==' ')
        {
            if(Alinan_Satir[k+9]=='s' && Alinan_Satir[k+10]=='h' && Alinan_Satir[k+11]=='o'  && Alinan_Satir[k+12]=='r'  && Alinan_Satir[k+13]=='t'  && Alinan_Satir[k+14]==' ')
            {
                //unsigned short Kontrol=6
                Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,6,k,fonk_icinde);
                return 0;
            }
            if(Alinan_Satir[k+9]=='i' && Alinan_Satir[k+10]=='n' && Alinan_Satir[k+11]=='t' && Alinan_Satir[k+12]==' ')
            {
                //unsigned int Kontrol=10
                Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,10,k,fonk_icinde);
                return 0;
            }
            if(Alinan_Satir[k+9]=='c' && Alinan_Satir[k+10]=='h' && Alinan_Satir[k+11]=='a'  && Alinan_Satir[k+12]=='r'  && Alinan_Satir[k+13]==' ')
            {
                //unsigned char Kontrol=2
                Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,2,k,fonk_icinde);
                return 0;
            }
        }// int Kontrolu=8
        if(Alinan_Satir[k]=='i' && Alinan_Satir[k+1]=='n' && Alinan_Satir[k+2]=='t' && Alinan_Satir[k+3]==' ')
        {
            if(Alinan_Satir[k+4]=='m' && Alinan_Satir[k+5]=='a' && Alinan_Satir[k+6]=='i' && Alinan_Satir[k+7]=='n')
            {
                if(Alinan_Satir[k+8]==' ' || Alinan_Satir[k+8]=='(')
                {
                    Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,k+8,1);
                    return 0;
                }
            }
            if(k>=9)
            {
                if(Alinan_Satir[k-1]==' ' && Alinan_Satir[k-9]=='u' && Alinan_Satir[k-6]=='i' && Alinan_Satir[k-4]=='n' && Alinan_Satir[k-2]=='d' )
                {
                    break;
                }
            }
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,8,k,fonk_icinde);
            return 0;
        }//__int8 Kontrolu=3
        if(Alinan_Satir[k]=='_' && Alinan_Satir[k+1]=='_' && Alinan_Satir[k+2]=='i' && Alinan_Satir[k+3]=='n' && Alinan_Satir[k+4]=='t' && Alinan_Satir[k+5]=='8' && Alinan_Satir[k+6]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,3,k,fonk_icinde);
            return 0;
        }//__int16 Kontrolu=4
        if(Alinan_Satir[k]=='_' && Alinan_Satir[k+1]=='_' && Alinan_Satir[k+2]=='i' && Alinan_Satir[k+3]=='n' && Alinan_Satir[k+4]=='t' && Alinan_Satir[k+5]=='1' && Alinan_Satir[k+6]=='6' && Alinan_Satir[k+7]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,4,k,fonk_icinde);
            return 0;
        }//__int32 Kontrolu=11
        if(Alinan_Satir[k]=='_' && Alinan_Satir[k+1]=='_' && Alinan_Satir[k+2]=='i' && Alinan_Satir[k+3]=='n' && Alinan_Satir[k+4]=='t' && Alinan_Satir[k+5]=='3' && Alinan_Satir[k+6]=='2' && Alinan_Satir[k+7]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,11,k,fonk_icinde);
            return 0;
        }//__int64 Kontrolu=13
        if(Alinan_Satir[k]=='_' && Alinan_Satir[k+1]=='_' && Alinan_Satir[k+2]=='i' && Alinan_Satir[k+3]=='n' && Alinan_Satir[k+4]=='t' && Alinan_Satir[k+5]=='6' && Alinan_Satir[k+6]=='4' && Alinan_Satir[k+7]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,13,k,fonk_icinde);
            return 0;
        }// return Kontrol=16
        if(Alinan_Satir[k]=='r' && Alinan_Satir[k+1]=='e' && Alinan_Satir[k+2]=='t' && Alinan_Satir[k+3]=='u' && Alinan_Satir[k+4]=='r' && Alinan_Satir[k+5]=='n' && Alinan_Satir[k+6]==' ')
        {
            Hesaplayici2(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,16,k,fonk_icinde);
            return 0;
        }
        k++;
    }
}
int main()
{
    FILE *dosya;
    int k=0;
    int Dosya_Dolumu=0;
    char Alinan_Satir[1000];
    char Son_Sira_Kontrol[1000];
    int *Toplam_Deger_Tutucu=(int*)malloc(sizeof(int)*16);
    int *Toplam_Dizi_Deger_Tutucu=(int*)malloc(sizeof(int)*16);
    int *Toplam_Hafiza_Karmasikligi=(int*)malloc(sizeof(int)*1);
    Toplam_Hafiza_Karmasikligi[0]=0;
    char *Toplam_Hafiza_Karmasikligi_Char=(char*)malloc(sizeof(char)*1000);
    int *Char_Kalinan_Yer=(int*)malloc(sizeof(int)*1);
    Char_Kalinan_Yer[0]=0;
    int Dosya_Dolumu_kontrol=0;
    //bool,char,unsigned_char,__int8,__int16,short,unsigned_short,float,int,long,unsigned_int,__int32
    //  0 , 1  ,     2       ,   3  ,   4   ,  5  ,      6       ,  7  , 8 , 9 ,    10      ,  11
    //double,__int64,long_double,long_long
    //  12  ,   13  ,     14    ,    15
    for(int k=0; k<=16; k++)
    {
        Toplam_Deger_Tutucu[k]=0;
        Toplam_Dizi_Deger_Tutucu[k]=0;
    }
    if(dosya=fopen("input.txt","r"))
    {
        while(!feof(dosya))
        {
            fgets(Alinan_Satir, 1000, dosya);
            k=0;
            Dosya_Dolumu_kontrol=0;
            if(Dosya_Dolumu==0)
            {
                while(Alinan_Satir[Dosya_Dolumu_kontrol]!='\0')
                {
                    if(Alinan_Satir[Dosya_Dolumu_kontrol]=='i' && Alinan_Satir[Dosya_Dolumu_kontrol+1]=='n' && Alinan_Satir[Dosya_Dolumu_kontrol+2]=='t' && Alinan_Satir[Dosya_Dolumu_kontrol+3]==' ')
                    {
                        if(Alinan_Satir[Dosya_Dolumu_kontrol+4]=='m' && Alinan_Satir[Dosya_Dolumu_kontrol+5]=='a' && Alinan_Satir[Dosya_Dolumu_kontrol+6]=='i' && Alinan_Satir[Dosya_Dolumu_kontrol+7]=='n')
                        {
                            Dosya_Dolumu=1;
                            break;
                        }
                    }
                    Dosya_Dolumu_kontrol++;
                }
            }
        }
        fclose(dosya);
        if(Dosya_Dolumu==1)
        {
            dosya=fopen("input.txt","r");
            while(!feof(dosya))
            {
                fgets(Alinan_Satir, 1000, dosya);
                printf("%s",Alinan_Satir);
                k=0;
                Hesaplayici(Alinan_Satir,Toplam_Deger_Tutucu,Toplam_Dizi_Deger_Tutucu,Toplam_Hafiza_Karmasikligi,Toplam_Hafiza_Karmasikligi_Char,Char_Kalinan_Yer,k,0);
            }
            fclose(dosya);
            printf("\n---------------------------------------------------------------------------------------------------------\n");
            printf("\n  Toplam bool : %d                 ve           Toplam bool Dizi : %d \n",Toplam_Deger_Tutucu[0],Toplam_Dizi_Deger_Tutucu[0]);
            printf("\n  Toplam char : %d                 ve           Toplam char Dizi : %d \n",Toplam_Deger_Tutucu[1],Toplam_Dizi_Deger_Tutucu[1]);
            printf("\n  Toplam unsigned char : %d        ve           Toplam unsigned char Dizi : %d \n",Toplam_Deger_Tutucu[2],Toplam_Dizi_Deger_Tutucu[2]);
            printf("\n  Toplam __int8 : %d               ve           Toplam __int8 Dizi : %d \n",Toplam_Deger_Tutucu[3],Toplam_Dizi_Deger_Tutucu[3]);
            printf("\n  Toplam __int16 : %d              ve           Toplam __int16 Dizi : %d \n",Toplam_Deger_Tutucu[4],Toplam_Dizi_Deger_Tutucu[4]);
            printf("\n  Toplam short : %d                ve           Toplam short Dizi : %d \n",Toplam_Deger_Tutucu[5],Toplam_Dizi_Deger_Tutucu[5]);
            printf("\n  Toplam unsigned short : %d       ve           Toplam unsigned short Dizi : %d \n",Toplam_Deger_Tutucu[6],Toplam_Dizi_Deger_Tutucu[6]);
            printf("\n  Toplam  float : %d               ve           Toplam float Dizi : %d \n",Toplam_Deger_Tutucu[7],Toplam_Dizi_Deger_Tutucu[7]);
            printf("\n  Toplam  int : %d                 ve           Toplam int Dizi : %d \n",Toplam_Deger_Tutucu[8],Toplam_Dizi_Deger_Tutucu[8]);
            printf("\n  Toplam  long : %d                ve           Toplam long Dizi : %d \n",Toplam_Deger_Tutucu[9],Toplam_Dizi_Deger_Tutucu[9]);
            printf("\n  Toplam  unsigned int : %d        ve           Toplam unsigned int Dizi : %d \n",Toplam_Deger_Tutucu[10],Toplam_Dizi_Deger_Tutucu[10]);
            printf("\n  Toplam  __int32 : %d             ve           Toplam __int32 Dizi : %d \n",Toplam_Deger_Tutucu[11],Toplam_Dizi_Deger_Tutucu[11]);
            printf("\n  Toplam double : %d               ve           Toplam double Dizi : %d \n",Toplam_Deger_Tutucu[12],Toplam_Dizi_Deger_Tutucu[12]);
            printf("\n  Toplam __int64 : %d              ve           Toplam __int64 Dizi : %d \n",Toplam_Deger_Tutucu[13],Toplam_Dizi_Deger_Tutucu[13]);
            printf("\n  Toplam long double : %d          ve           Toplam long double Dizi : %d \n",Toplam_Deger_Tutucu[14],Toplam_Dizi_Deger_Tutucu[14]);
            printf("\n  Toplam long long : %d            ve           Toplam long long Dizi : %d \n",Toplam_Deger_Tutucu[15],Toplam_Dizi_Deger_Tutucu[15]);
            printf("\n  Toplam return : %d \n",Toplam_Deger_Tutucu[16]);
            printf("\n---------------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t  Toplam Hafiza Karmasikligi : %d + ",Toplam_Hafiza_Karmasikligi[0]);
            for(int k=0; k<Char_Kalinan_Yer[0]; k++)
            {
                printf("%c",Toplam_Hafiza_Karmasikligi_Char[k]);
            }
            int N_Sayisi_Hesapla=0;
            int Yazilan_N_Boyutu=0;
            int Boyut_Hesapla=0;
            int Yazilan_N=0;
            int k=0;
            while(k<=Char_Kalinan_Yer[0])
            {
                if(Toplam_Hafiza_Karmasikligi_Char[k]=='*')
                {
                    N_Sayisi_Hesapla++;
                    if(Toplam_Hafiza_Karmasikligi_Char[k+1]>=48 && Toplam_Hafiza_Karmasikligi_Char[k+1]<=57)
                    {
                        k++;
                        Boyut_Hesapla=(Boyut_Hesapla*10)+Toplam_Hafiza_Karmasikligi_Char[k]-48;
                        if(Toplam_Hafiza_Karmasikligi_Char[k+1]>=48 && Toplam_Hafiza_Karmasikligi_Char[k+1]<=57)
                        {
                            k++;
                            Boyut_Hesapla=(Boyut_Hesapla*10)+Toplam_Hafiza_Karmasikligi_Char[k]-48;
                        }
                    }
                }
                if(Toplam_Hafiza_Karmasikligi_Char[k]=='+')
                {
                    if(Yazilan_N<N_Sayisi_Hesapla)
                    {
                        Yazilan_N=N_Sayisi_Hesapla;
                        Yazilan_N_Boyutu=Boyut_Hesapla;
                    }
                    else if(Yazilan_N==N_Sayisi_Hesapla && Yazilan_N_Boyutu<Boyut_Hesapla)
                    {
                        Yazilan_N_Boyutu=Boyut_Hesapla;
                    }
                    Boyut_Hesapla=0;
                    N_Sayisi_Hesapla=0;
                }
                k++;
            }
            if(Yazilan_N>0)
            {
                printf("\n\t\t  Toplam Hafiza Karmasikligi : O(N^%d)",Yazilan_N);
            }
            else
            {
                printf("\n\t\t  Toplam Hafiza Karmasikligi : O(1)");
            }
            printf("\n\n---------------------------------------------------------------------------------------------------------\n");
            // Zaman Karmasikligi
            int *Suslu_Sayisi=(int*)malloc(sizeof(int)*1);
            Suslu_Sayisi[0]=0;
            int *Icice_Dongu=(int*)malloc(sizeof(int)*1);
            Icice_Dongu[0]=0;
            char *Toplam_Zaman_Karmasikligi_Char=(char*)malloc(sizeof(char)*1000);
            int *Char_Kalinan_Yer1=(int*)malloc(sizeof(int)*1);
            char Son_Zaman_Karmasikligi_Char[2000];
            int Son_Zaman_Karmasikligi_Yer=0;
            Char_Kalinan_Yer1[0]=0;
            char *Kontrol_Char=(char*)malloc(sizeof(char)*1000);
            int *Kontrol_Char_Kalinan_Yer=(int*)malloc(sizeof(int)*1);
            Kontrol_Char_Kalinan_Yer[0]=0;
            int giris=0;
            char *Dongu_bagli_Degisken=(char*)malloc(sizeof(char)*1000);
            int *Dongu_bagli_int=(int*)malloc(sizeof(int)*1);
            Dongu_bagli_int[0]=0;
            int *Kacinic_Satir=(int*)malloc(sizeof(int)*1);
            Kacinic_Satir[0]=0;
            dosya=fopen("input.txt","r");
            while(!feof(dosya))
            {
                fgets(Alinan_Satir, 1000, dosya);
                // k=0;
                Kacinic_Satir[0]++;
                Zaman_Karmasikligi_Hesaplayici(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi,Dongu_bagli_Degisken,Dongu_bagli_int,Kacinic_Satir);
                if(Icice_Dongu[0]!=0)
                {
                    Suslu_Hesaplayici(Alinan_Satir,Toplam_Zaman_Karmasikligi_Char,Char_Kalinan_Yer1,Kontrol_Char,Kontrol_Char_Kalinan_Yer,Icice_Dongu,Suslu_Sayisi);
                    giris++;
                }
                if(Suslu_Sayisi[0]==0 && Icice_Dongu[0]!=0 && giris>=2)
                {
                    Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]='+';
                    Char_Kalinan_Yer1[0]++;
                    Toplam_Zaman_Karmasikligi_Char[Char_Kalinan_Yer1[0]]=' ';
                    Char_Kalinan_Yer1[0]++;
                    Icice_Dongu[0]=0;
                    Suslu_Sayisi[0]=0;
                    giris=0;
                    Dongu_bagli_int[0]=0;
                }
                for(int k=0; k<Char_Kalinan_Yer1[0]; k++)
                {
                    Son_Zaman_Karmasikligi_Char[Son_Zaman_Karmasikligi_Yer]=Toplam_Zaman_Karmasikligi_Char[k];
                    Son_Zaman_Karmasikligi_Yer++;
                }
                Char_Kalinan_Yer1[0]=0;

            }
            fclose(dosya);
            // Duzeltme 1
            if(Son_Zaman_Karmasikligi_Char[0]=='*' && Son_Zaman_Karmasikligi_Char[1]==' ')
            {
                for(int a=0; a<Son_Zaman_Karmasikligi_Yer-2; a++)
                {
                    Son_Zaman_Karmasikligi_Char[a]=Son_Zaman_Karmasikligi_Char[a+2];
                }
                Son_Zaman_Karmasikligi_Yer=Son_Zaman_Karmasikligi_Yer-2;
            }
            // Duzeltme 2
            for(int k=0; k<Son_Zaman_Karmasikligi_Yer; k++)
            {
                if(Son_Zaman_Karmasikligi_Char[k]=='+' && Son_Zaman_Karmasikligi_Char[k+2]=='*')
                {
                    for(int a=k+1; a<Son_Zaman_Karmasikligi_Yer-2; a++)
                    {
                        Son_Zaman_Karmasikligi_Char[a]=Son_Zaman_Karmasikligi_Char[a+2];
                    }
                    Son_Zaman_Karmasikligi_Yer=Son_Zaman_Karmasikligi_Yer-2;
                }
            }
            for(int y=0; y<10; y++)
            {
                for(int k=0; k<Son_Zaman_Karmasikligi_Yer; k++)
                {
                    if(Son_Zaman_Karmasikligi_Char[k]=='+' && Son_Zaman_Karmasikligi_Char[k+2]=='+')
                    {
                        for(int a=k; a<Son_Zaman_Karmasikligi_Yer-2; a++)
                        {
                            Son_Zaman_Karmasikligi_Char[a]=Son_Zaman_Karmasikligi_Char[a+2];
                        }
                        Son_Zaman_Karmasikligi_Yer=Son_Zaman_Karmasikligi_Yer-2;
                    }
                }
            }
            printf("\n\t\t  Toplam Zaman Karmasikligi : ");
            for(int k=0; k<Son_Zaman_Karmasikligi_Yer; k++)
            {
                printf("%c",Son_Zaman_Karmasikligi_Char[k]);
            }
            printf("\n\n---------------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\n\n--> Bu Isimle Alinan Dosyada Int Main Fonksiyonu Yok !!!\n\n");
        }
    }
    else
    {
        printf("\n\n--> Bu Isimle Kayitli Dosya Bulunamadi !!!\n\n");
    }
    return 0;
}
