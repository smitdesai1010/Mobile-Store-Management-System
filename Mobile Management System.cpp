







// Compiler: Turbo C++










#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>

int p;
ofstream fi("bill.dat",ios::nocreate);

 class mobile
  {
   public:
   char nm[20];
   char ram[20];
   char cam[20];
   int st;
   long pr;


   void enter()
   {
   cout<<"\n Enter name of model:";gets(nm);
   cout<<"\n Enter ram size:";gets(ram);
   cout<<"\n Enter camera pixels:";gets(cam);
   cout<<"\n Enter price:";cin>>pr;
   cout<<"\n Enter storage:";cin>>st;
   }
    void show()
     {
	 cout<<"\n\n "<<nm<<"                 "<<ram<<"       "<<cam<<"        "<<st<<"      "<<pr;
     }

  };

  char nmct[20],add[100],no[11],nu[11];

 mobile oneplus,samsung,apple,m;

 int menu();
 void menu2();
 void one();
 void apple1();
 void samsung1();
 void bill();
 void onew();
 void samw();
 void appw();
 void insert();
 void admin();

 void main()
  {
   clrscr();
   int n,x;

   cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                ";
   cout<<" WELCOME TO EGG's Mobile Store ";
   getch();



   clrscr();
   cout<<"\n 1) Adminstrator ";
   cout<<"\n 2) Customer ";
   cout<<"\n 3) Exit     ";
   cout<<"\n\n\n Choose:";cin>>x;

   if(x==1)
    {

       char gh[10],ch[]="angel";
       cout<<"Enter employ password:";cin>>gh;

	if(strcmpi(gh,ch)==0)
	   admin();

	else
	 {
	   clrscr();
	    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                ";
	    cout<<"   You have entered wrong password!!";
	 }
    }



   else if(x==2)
   {
    clrscr();
    cout<<"\n Enter your name: ";gets(nmct);
    cout<<"\n Enter address: ";gets(add);
    cout<<"\n Enter number: ";gets(no);
    strcpy(nu,no);

    menu2();
   }

   else
   {
     clrscr();

     cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                ";
     cout<<"   You have wished to exit!! ";
     exit(0);
   }

   getch();
  }


 int menu()
  {
   clrscr();
   int n;


   cout<<"\n 1) Oneplus";
   cout<<"\n 2) Apple";
   cout<<"\n 3) Samsung";
   cout<<"\n 4) Bill";

   cout<<"\n 5) Exit";

   cout<<"\n\n\n Enter Choice: ";cin>>n;

   return n;
  }

  void menu2()
  {
   clrscr();
   int n=menu();

   if(n==1)
   one();

   if(n==2)
   apple1();

   if(n==3)
   samsung1();

   if(n==4)
   bill();

   if(n==5)
   exit(0);

  }


  void one()
   {
     clrscr();
     int a;

     ifstream f("ONEPLUS.dat",ios::in|ios::binary);
     cout<<"\n    Item                Ram     Camera   Storage   Price   ";
     cout<<"\n------------------------------------------------------------------";

     while(f.read((char*)&oneplus,sizeof(oneplus)))
      {
	oneplus.show();
      }


     cout<<"\n\n\n Number to Buy: ";cin>>a;
     f.close();

     f.open("ONEPLUS.dat",ios::in|ios::binary);

      f.seekg((a-1)*sizeof(oneplus),ios::beg);
      f.read((char*)&oneplus,sizeof(oneplus));

      ofstream fout("bill1.dat",ios::out|ios::binary|ios::app);
      fout.write((char*)&oneplus,sizeof(oneplus));
       fout.close();

       f.close();
       menu2();
    }

    void apple1()
   {
     clrscr();
     int a;

     ifstream f("APPLE.dat",ios::in|ios::binary);
     cout<<"\n    Item                Ram     Camera   Storage   Price ";
     cout<<"\n------------------------------------------------------------------";

     while(f.read((char*)&apple,sizeof(apple)))
      {
	apple.show();
      }


	cout<<"\n\n\n Number to Buy: ";cin>>a;

	 f.close();
	 f.open("APPLE.dat",ios::in|ios::binary);

      f.seekg((a-1)*sizeof(apple),ios::beg);
      f.read((char*)&apple,sizeof(apple));

      ofstream fout("bill1.dat",ios::out|ios::binary|ios::app);
       fout.write((char*)&apple,sizeof(apple));
       fout.close();


	 f.close();
	 menu2();

   }

   void samsung1()
   {
     clrscr();
     int a;

     ifstream f("SAMSUNG.dat",ios::in|ios::binary);
     cout<<"\n    Item                Ram     Camera   Storage   Price ";
     cout<<"\n------------------------------------------------------------------";

     while(f.read((char*)&samsung,sizeof(samsung)))
      {
	samsung.show();
      }


       cout<<"\n\n\n Number to Buy: ";cin>>a;

       f.close();
       f.open("SAMSUNG.dat",ios::in|ios::binary);

      f.seekg((a-1)*sizeof(samsung),ios::beg);
      f.read((char*)&samsung,sizeof(samsung));

      ofstream fout("bill1.dat",ios::out|ios::binary|ios::app);
      fout.write((char*)&samsung,sizeof(samsung));
      fout.close();

       f.close();
       menu2();
   }


  void bill()
    {
       clrscr();
       double tot;
      ifstream fin("bill1.dat",ios::in|ios::binary);

	  cout<<"\n Name: "<<nmct<<endl;
	  cout<<"\n Address: "<<add<<endl;
	  cout<<"\n Number: "<<nu<<endl;

	   cout<<"\n    Item                Ram     Camera   Storage   Price ";
	   cout<<"\n------------------------------------------------------------------";

	    while(fin.read((char*)&m,sizeof(m)))
	     {
	      m.show();
	      tot+=m.pr;
	     }
	   cout<<"\n------------------------------------------------------------------";
	   cout<<"\n Total:                                           "<<tot;

	   cout<<"\n\n\n Final amount to be paid inclusive of all taxes is: "<<(tot+(tot*0.18));
                      

	 getch();
     }


   void admin()
    {
      clrscr();
      int t;

	 cout<<"\n 1) Insert ";
	 cout<<"\n 2) Main Menu ";
	 cout<<"\n\n\n Enter your choice: ";cin>>t;

	  switch(t)
	   {
	     case 1:insert();
	     case 2:main();
	   }
    }


 void insert()
  {
   clrscr();



   int n;
   cout<<"\n Insert into: \n";
   cout<<"\n 1) Oneplus";
   cout<<"\n 2) Apple";
   cout<<"\n 3) Samsung";
   cout<<"\n 4) Back";

   cout<<"\n\n\n Enter Choice: ";cin>>n;

   if(n==1)
     { onew(); insert(); }

   if(n==2)
     { appw(); insert(); }

   if(n==3)
     { samw(); insert(); }

   if(n==4)
   admin();

 }

 void onew()
  {
   ofstream foo("ONEPLUS.dat",ios::app|ios::out);
   oneplus.enter();
   foo.write((char*)&oneplus,sizeof(oneplus));
   foo.close();

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                ";
    cout<<"            UPDATED CATALOGUE          " ;

    clrscr();
    ifstream f("ONEPLUS.dat",ios::in|ios::binary);
    while(f.read((char*)&oneplus,sizeof(oneplus)))
      {
	oneplus.show();
      }

    getch();
    f.close();
  }

 void samw()
  {
   ofstream fos("SAMSUNG.dat",ios::app|ios::out);
   samsung.enter();
   fos.write((char*)&samsung,sizeof(samsung));
   fos.close();



   cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                ";
    cout<<"            UPDATED CATALOGUE         " ;

    clrscr();
    ifstream f("SAMSUNG.dat",ios::in|ios::binary);
    while(f.read((char*)&samsung,sizeof(samsung)))
      {
	samsung.show();
      }

    getch();
    f.close();
  }

 void appw()
  {
   ofstream foa("APPLE.dat",ios::app|ios::out);
   apple.enter();
   foa.write((char*)&apple,sizeof(apple));
   foa.close();


   cout<<"\n\n\n\n\n\n\n\n\n\n\n\t                ";
    cout<<"            UPDATED CATALOGUE          " ;

    clrscr();
    ifstream f("APPLE.dat",ios::in|ios::binary);
    while(f.read((char*)&apple,sizeof(apple)))
      {
	apple.show();
      }

    getch();
    f.close();

  }


