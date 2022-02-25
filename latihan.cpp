#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void menu();
void login();
void header();

void header(){
	cout	<<"===================================\n"
			<<" selamat datang di aplikasi kantin \n"
			<<"          smk 3 banjarbaru         \n"
			<<"===================================\n\n";
}

void login (){
	system ("cls");
	header();
	string un,pw;
	cout<<"username :";
	cin>>un;
	cout<<"password :";
	cin>>pw;
	
	if (un == "admin" and pw == "admin")
		menu();
	else
		login();
}

void menu(){
	string makanan [10][3]={{"1","nasgor","100000"},
							{"2","mi goreng","17000"},
							{"3","lontong sate","20000"},
							{"4","nasi pecel","10000"},
							{"5","nasi remes","17000"},
							{"6","soto ayam","16000"},
							{"7","air putih","2000"},
							{"8","es teh","5000"},
							{"9","es jeruk","7000"},
							{"10","jus jeruk","8000"},
						};
	system ("cls");
	header();
	char pilihan;
	int ulang;
	cout<<" menu : \n"
		<<"a. mulai pesan :\n"
		<<"b. lihat daftar barang\n"
		<<"c. cari barang \n"
		<<"d. keluar"
		<<" masukkan pilihan :";
	cin>>pilihan;
	
	if (pilihan=='a' or pilihan=='A')
	{
		do{
			system("cls");
			header();
			for(int i=0; i<10; i++){
				for (int j=0; j<3; j++){
					cout<<makanan[i][j]<<"\t";
				}
				cout<<endl;
			}
			
			ofstream nota;
			nota.open("nota.txt");
			
			int nPesan;
			int pesanan;
			int jumlah;
			int total;
			int bayar=0;
			int harganya;
			cout<<"\n\n===============================\n"
				<<"berapa jenis makanan yang ingin anda pesan? : ";
			cin>>nPesan;
				
			for (int i =0; i<nPesan; i++){
				string struk [nPesan][4];
				
				cout<<"\nPesanan"<<i+1<<" :";
				cin>>pesanan;
				cout<<"Jumlah pesanan :";
				cin>>jumlah;
				
				if(pesanan == 1){
					harganya=stoi(makanan[0][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 2){
					harganya=stoi(makanan[1][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 3){
					harganya=stoi(makanan[2][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 4){
					harganya=stoi(makanan[3][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 5){
					harganya=stoi(makanan[4][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 6){
					harganya=stoi(makanan[5][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 7){
					harganya=stoi(makanan[6][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 8){
					harganya=stoi(makanan[7][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 9){
					harganya=stoi(makanan[8][2]);
					total=jumlah*harganya;
				}
				else if (pesanan == 10){
					harganya=stoi(makanan[9][2]);
					total=jumlah*harganya;
				} else 
				cout<<"menu tidak terdaftar";
					
				bayar=bayar+total;
				
				struk[i][0]= to_string(i+1);
				struk[i][1]= makanan[pesanan-1][1];
				struk[i][2]= to_string(jumlah);
				struk[i][3]= to_string(total);
				
				for (int j=0; j<4; j++){
					cout<<struk[i][j]<<" ";
					nota<<struk[i][j]<<" ";
				}
				cout<<endl;
				nota<<endl;
			}
			cout<<"\nTotal bayar : "<<bayar;
			nota<<"\nTotal bayar : "<<bayar;
			nota.close();
			
			cout<<"\n1. kembali ke menu utama"
				<<"\n2. Pesan lagi"
				<<"\n3. keluar";
			cout<<"\nmasukkan pilihan :";
			cin>>ulang;
			
			if(ulang ==1)
				menu();
			else if (ulang==3)
				login();
			}while(ulang ==2);
	}
	
	else if (pilihan=='b' or pilihan=='B'){
		int milih;
		system("cls");
		header();
		cout<<"  menu makanan: \n";
		for (int i=0; i<10; i++){
			for (int j=0; j<3; j++){
				cout<<makanan[i][j]<<"\t";
			}
			cout<<endl;
		}
		do{
			system ("cls");
			header();
			cout<<"\n pilihan :"
				<<"\n1. urutkan berdasarkan nama makanan\n"
				<<"2. urutkan berdasarkan harga";
			cout<<"\n\nMasukkan pilihan :";
			int milih;
			cin>>milih;
			
			if(milih ==1){
				for(int max = 9; max > 0; max--){
					for(int i=0; i<max; i++){
						if(makanan[i][1]>makanan[i+1][1]){
							swap(makanan[i], makanan[i+1]);
						}
					}
				}
				for (int i=0; i<10; i++){
					for (int j=0; j<3; j++){
						cout<<makanan[i][j]<<"\t";
					}
					cout<<endl;
				}
			}
				
				else if(milih ==2){
					for (int max = 9; max > 0; max--){
						for (int i=0; i<max; i++){
							if (stoi(makanan[i][2])>stoi(makanan[i+1][2])){
								swap(makanan[1], makanan[i+1]);
							}
						}
					}
					
					for (int i=0; i<10; i++){
						for (int j=0; j<3; j++){
							cout<<makanan[i][j]<<"\t";
						}
						cout<<endl;
					}
				}
				else //lanjut bagian 222 "else"
					cout<<"tidak tersedia";
					
					cout<<"\n1. kembali ke menu utama"
						<<"\n2. lihat daftar menu lagi"
						<<"\n3. keluar";
					cout<<"\nMasukkan pilihan";
					cin>>ulang;
					
					if(ulang==1)
						menu();
						else if (ulang==3)
						login();
				}while(ulang==2);
			}
			else if (pilihan == 'c' or pilihan == 'C'){
				do{
					string cari;
					system("cls");
					header();
					cout<<"masukkan kata kunci pencarian :";
					cin>> cari;
					cout<<"hasil pencarian :";
					for (int i=0; i<10; i++){
						for(int j=0; j<3; j++){
							if(makanan [i][j].find(cari,0) != string::npos){
								cout<<makanan[i][j]<<endl;
							}
						}
					}
					cout<<"\n1. kembali ke menu utama"
						<<"\n2. lihat daftar menu lagi"
						<<"\n3. keluar";
					cout<<"\nMasukkan pilihan";
					cin>>ulang;
					
					if(ulang==1)
						menu();
						else if (ulang==3)
						login();
				}while(ulang==2);
			}
			else {
				cout<<"salah input";
				menu();
			}
		}
		int main(){
			login();
			return 0;
		}