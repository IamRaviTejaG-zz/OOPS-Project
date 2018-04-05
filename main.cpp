#include<bits/stdc++.h>
#include"login.cpp"
#include"medicine .cpp"
#include"hospital.cpp"

#define print_dash(l) for(int i=0; i<l; i++) cout<<'-'
#define print_hash(l) for(int i=0; i<l; i++) cout<<'#'

using namespace std;

void menu()
{
  system("cls");
  print_dash(170);
  cout<<"\n\n\t\t\t\t\t\t\t|||   MEDICINE DISTRIBUTION & MANAGEMENT SERVICE   |||\n\n";
  print_dash(170);
  cout<<"\n\n\n\t\t\t\t\t\t\t\t\t||| MAIN MENU |||\n";
  cout<<"\n\t\t\t\t\t\t\t\t\t1. Admin Login";
  cout<<"\n\t\t\t\t\t\t\t\t\t2. Employee Login";
  cout<<"\n\t\t\t\t\t\t\t\t\t3. Guest User Login";
  cout<<"\n\t\t\t\t\t\t\t\t\t4. Exit";
  cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Choice: ";
  int choice;
  cin>>choice;
  cout<<'\n';
  print_hash(170);
  if (choice == 1)
    login(1);
  else if (choice == 2)
    login(2);
  else if (choice == 3)
    login(3);
  else if (choice == 4)
    exit(0);
  else
  {
    cout<<"Invalid Choice!";
    wait
    menu();
  }
}

int main()
{
  system("mode 170,300");
  menu();
  return 0;
}
