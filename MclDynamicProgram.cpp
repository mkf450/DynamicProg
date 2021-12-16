/*
Nama: Muhammad Keenan Fathurrahman
Nim: 24060119130052
Kelas: ASA Kelas A
Tanggal: 15 Desember 2021
Nama File: MclDynamicProgram.cpp
*/

#include <bits/stdc++.h>
using namespace std;
 
// Tipe data buatan pair (pasangan)
class Pair
{
    public:
    int a;
    int b;
};
 
// Fungsi maxChainLength bertujuan untuk menghitung jumlah maksimum pasangan yang terurut naik
int maxChainLength( Pair arr[], int n){
    int i, j, maks = 0;
    int *mcl = new int[sizeof( int ) * n ];
     
    /* Inisialisasi nilai setiap kolom dari array mcl (max chain length) */
    for ( i = 0; i < n; i++ )
        mcl[i] = 1;
     
    /* Perhitungan dan validasi nilai untuk mengubah nilai kolom mcl pada index ke-i */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1)
                mcl[i] = mcl[j] + 1;
     
    /* Mengambil nilai maksimal dari mcl pada setiap index i (setiap kolom)*/
    for ( i = 0; i < n; i++ )
        if ( maks < mcl[i] )
            maks = mcl[i];
     
    /* Mengembalikan nilai maksimal dari max chain length */
    return maks;
}
     
 
/* Fungsi main */
int main(){	
	// Input n dan arr
    Pair arr[] = {{5, 24}, {15, 28}, {27, 40}, {50, 90}};
    int n = sizeof(arr)/sizeof(arr[0]);
    
	// Pemanggilan fungsi maxChainLength untuk memulai program dinamis
	cout << "Length of maximum size chain is " << maxChainLength( arr, n );
    return 0;
}
