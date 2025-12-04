/* File : main.c */
/* Deskripsi : implementasi manajemen proses pada sistem operasi Linux menggunakan system call fork(),
 *  exec(), dan wait() untuk membuat, mengeksekusi, serta mengatur sinkronisasi antara proses parent dan child. */
/* NIM & Nama : 24060124140124/Aqiatilllah Rezi Zhafran*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    //Deklarasi	
    int pid, i, endvalue;
    //Set jumlah perulanganya sebanyak 10 kali
    endvalue = 10;
    //Melakukan proses fork
    printf("calling fork()\n");
    //Proses baru fork
    pid = fork();
    //Jika proses gagal dieksekusi
    if (pid < 0)
    {
	//jika gagal menapilkan pesan 
        printf("Fork failed\n");
	//Hentikan programnya jika eror dengan code erorrnya 1
        exit(1);
    }
    //Child process
    else if (pid == 0)
    {
        printf("\nChild Process\n");
        printf("PID Child  : %d\n", getpid());//PID chlidnya
        printf("PPID Child : %d\n\n", getppid());//PID perent dari child
	
        //untuk loopingnya sebanyak endvalue yaitu di set nya 10
        for (i = 0; i < endvalue; i++)
        {
	//menampilkan status child process sedang dijalankan
        printf("Child running %d\n", i + 1);
	//outputnya agar lansung muncul di tampilan 
        fflush(stdout);
        sleep(1);//diberikan jeda tiap loop sebanyak 1 detik
    }
        //jika proses child sudah selesai tampilkan
        printf("\nChild selesai dijalankan.\n");
        exit(0);//menghetikan proses child dengan status 0
    }	 
    //jika perent process
    else
    {
        printf("\nParent Process\n");
        printf("PID Parent : %d\n", getpid());//tempilkan PID Perentnya

        wait(NULL);//parent menunggu child selesai prosesnya agar tidak ada zombie process
        //looping sebanyak 10 kali juga untuk parent
        for (i = 0; i < endvalue; i++)
        {
            //menampilkan status perent process sedang dijalankan
	    printf("Parent running %d\n", i + 1);
	    //Output agar langsung muncul di tampilan
            fflush(stdout);
            sleep(1);//diberikan jeda tiap loop sebanyak 1 detik
        }
        //menampilkan bahwa proses clid sudah selesai semua
        printf("\nChild Complete\n");
        exit(0);//menghentikan proses perent
    }
}

        

