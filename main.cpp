// MEDICINE DISTRIBUTION AND MANAGEMENT SYSTEM
// Author: Ravi Teja Gannavarapu
// Last Update: 13 April, 2018

#include<bits/stdc++.h>

#define print_dash(l) for(int i=0; i<l; i++) cout<<'-'
#define print_hash(l) for(int i=0; i<l; i++) cout<<'#'

using namespace std;

// Function declarations
int login(int choice);
int hospital_access();
int medicine_access();
void admin_menu();
void emp_menu();
void menu();

class Hospital
{
  protected:
    string address, district, hospital_code, hospital_name;
  public:
    void add()
    {
      fstream hos("hospital.csv", ios::out|ios::app);
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t\t|||   ADD HOSPITAL DATA   |||\n\n";
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t\tHospital Code: ";
      cin>>hospital_code;
      cout<<"\n\t\t\t\t\t\t\t\t\tHospital Name: ";
      getline(cin, hospital_name);
      cout<<"\n\t\t\t\t\t\t\t\t\tDistrict: ";
      cin>>district;
      cout<<"\n\t\t\t\t\t\t\t\t\tAddress: ";
      cin>>address;
      hos<<hospital_code<<','<<hospital_name<<','<<district<<','<<address<<','<<endl;
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tADDED SUCCESSFULLY!"<<endl;
      hos.close();
    }

    void display()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t\t|||   DISPLAYING HOSPITAL DATA   |||\n\n";
      print_dash(170);
      cout<<"HOSPITAL CODE\t\tHOSPITAL NAME\t\tDISTRICT\t\t\tADDRESS\n\n";
      string line;
      int i=0;
      fstream hos("hospital.csv");
      while (!hos.eof())
      {
        while(getline(hos, line, ','))
          cout<<line<<"\t\t\t";
        cout<<'\n';
      }
      hos.close();
    }

    void edit()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t|||   EDIT HOSPITAL DATA   |||\n\n";
      print_dash(170);
      string line, entry;
      cout<<"\n\t\t\t\t\t\t\t\t1. Edit by Hospital Code";
      cout<<"\n\t\t\t\t\t\t\t\t2. Edit by Hospital Name";
      cout<<"\n\t\t\t\t\t\t\t\tEnter choice: ";
      int ch;
      cin>>ch;
      fstream input("hospital.csv", ios::in|ios::binary);
      fstream output("temp.csv", ios::out|ios::binary);
      while (ch<1 && ch>2)
      {
        cout<<"Invalid choice, re-enter: ";
        cin>>ch;
      }
      if (ch == 1)
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Code: ";
        cin>>entry;
      }
      else
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Name: ";
        cin>>entry;
      }
      while (!input.eof())
      {
        while(getline(input, line))
        {
          stringstream lines;
          lines << line;
          string s1;
          int flag = 0;
          while (getline(lines, s1, ','))
          {
            if (s1 == entry)
            {
              flag = 1;
              cout<<"\n\n\t\t\t\t\t\t\t\tEDITING DETAILS FOR HOSPITAL: "<<entry;
              cout<<"\n\n\t\t\t\t\t\t\t\tEnter New Hospital Code: ";
              cin>>hospital_code;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New Hospital Name: ";
              cin>>hospital_name;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New District: ";
              cin>>district;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New Address: ";
              cin>>address;
              output<<hospital_code<<','<<hospital_name<<','<<district<<','<<address<<','<<endl;
              cout<<"\n\n\n\t\t\t\t\t\t\t\tEDITED SUCCESSFULLY!"<<endl;
            }
          }
          if (!flag)
            output<<line<<'\n';
        }
      }
      input.close();
      output.close();
      remove("hospital.csv");
      rename("temp.csv", "hospital.csv");
    }

    void rem()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t|||   DELETE HOSPITAL DATA   |||\n\n";
      print_dash(170);
      string line, entry;
      cout<<"\n\t\t\t\t\t\t\t\t1. Delete by Hospital Code";
      cout<<"\n\t\t\t\t\t\t\t\t2. Delete by Hospital Name";
      cout<<"\n\t\t\t\t\t\t\t\tEnter choice: ";
      int ch;
      cin>>ch;
      fstream input("hospital.csv", ios::in|ios::binary);
      fstream output("temp.csv", ios::out|ios::binary);
      while (ch<1 && ch>2)
      {
        cout<<"Invalid choice, re-enter: ";
        cin>>ch;
      }
      if (ch == 1)
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Code: ";
        cin>>entry;
      }
      else
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Hospital Name: ";
        getline(cin, entry);
      }
      while (!input.eof())
      {
        while(getline(input, line))
        {
          stringstream lines;
          lines << line;
          string s1;
          int flag = 0;
          vector<string> s;
          while (getline(lines, s1, ','))
            s.push_back(s1);
          if (s[0] == entry || s[1] == entry)
          {
            flag = 1;
            cout<<"\n\t\t\t\t\t\t\t\t\t|||   DELETING HOSPITAL WITH   |||\n";
            cout<<"\n\t\t\t\t\t\t\t\t\tHospital ID: "<<s[0];
            cout<<"\n\t\t\t\t\t\t\t\t\tHospital Name: "<<s[1];
            cout<<"\n\t\t\t\t\t\t\t\t\tDistrict: "<<s[2];
            cout<<"\n\t\t\t\t\t\t\t\t\tAddress: "<<s[3];
            cout<<"\n\n\n\t\t\t\t\t\t\tDELETED SUCCESSFULLY!"<<endl;
          }
          if (!flag)
            output<<line<<'\n';
        }
      }
      input.close();
      output.close();
      remove("hospital.csv");
      rename("temp.csv", "hospital.csv");
    }
};

class Medicine:public Hospital
{
  protected:
    string name, category;
    long int medicine_id, up_limit, sale;
    float price;
  public:
    void add()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t\t|||   ADD MEDICINE DETAILS   |||\n\n";
      print_dash(170);
      fstream in("medicine.csv", ios::app|ios::out);
      cout<<"\n\n\t\t\t\t\t\t\t\t\tHospital Code: ";
      cin>>hospital_code;
      cout<<"\n\t\t\t\t\t\t\t\t\tMedicine Name: ";
      getline(cin, name);
      cout<<"\n\t\t\t\t\t\t\t\t\tMedicine ID: ";
      cin>>medicine_id;
      cout<<"\n\t\t\t\t\t\t\t\t\tPrice: ";
      cin>>price;
      cout<<"\n\t\t\t\t\t\t\t\t\tUp Limit: ";
      cin>>up_limit;
      in<<hospital_code<<','<<name<<','<<medicine_id<<','<<price<<','<<up_limit<<','<<endl;
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tADDED SUCCESSFULLY!"<<endl;
      in.close();
    }

    void display()
    {
    	system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t\t|||   MEDICINE DETAILS   |||\n\n";
      print_dash(170);
      cout<<"HOSPITAL ID\t\tNAME\t\t\tMEDICINE ID\t\tPRICE\t\t\tUP LIMIT\n\n";
      string line;
      fstream medicine("medicine.csv");
      while (!medicine.eof())
      {
        while(getline(medicine, line, ','))
          cout<<line<<"\t\t\t";
        cout<<'\n';
      }
      medicine.close();
    }

    void edit()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t|||   EDIT MEDICINE DATA   |||\n\n";
      print_dash(170);
      string line, entry;
      cout<<"\n\t\t\t\t\t\t\t\t1. Edit by Medicine Code";
      cout<<"\n\t\t\t\t\t\t\t\t2. Edit by Medicine Name";
      cout<<"\n\t\t\t\t\t\t\t\tEnter choice: ";
      int ch;
      cin>>ch;
      fstream in("medicine.csv", ios::in|ios::binary);
      fstream out("temp.csv", ios::out|ios::binary);
      while (ch<1 && ch>2)
      {
        cout<<"Invalid choice, re-enter: ";
        cin>>ch;
      }
      if (ch == 1)
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine Code: ";
        cin>>entry;
      }
      else
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine Name: ";
        cin>>entry;
      }
      while (!in.eof())
      {
        while(getline(in, line))
        {
          stringstream lines;
          lines << line;
          string s1;
          int flag = 0;
          while (getline(lines, s1, ','))
          {
            if (s1 == entry)
            {
              flag = 1;
              cout<<"\n\n\t\t\t\t\t\t\t\tEDITING DETAILS FOR Medicine: "<<s1;
              cout<<"\n\n\t\t\t\t\t\t\t\tEnter New Hospital Code: ";
              cin>>hospital_code;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New Medicine Name: ";
              cin>>name;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New Medicine ID: ";
              cin>>medicine_id;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New Price: ";
              cin>>price;
              cout<<"\n\t\t\t\t\t\t\t\tEnter New Upper Limit: ";
              cin>>up_limit;
              out<<hospital_code<<','<<name<<','<<medicine_id<<','<<price<<','<<up_limit<<','<<endl;
              cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEDITED SUCCESSFULLY!"<<endl;
            }
          }
          if (!flag)
            out<<line<<'\n';
        }
      }
      in.close();
      out.close();
      remove("medicine.csv");
      rename("temp.csv", "medicine.csv");
    }

    void rem()
    {
      system("cls");
      string line, entry;
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t\t|||   DELETE MEDICINE DATA   |||\n\n";
      print_dash(170);
      cout<<"\n\t\t\t\t\t\t\t\t1. Delete by Name";
      cout<<"\n\t\t\t\t\t\t\t\t2. Delete by ID";
      cout<<"\n\t\t\t\t\t\t\t\tEnter choice: ";
      int ch;
      cin>>ch;
      fstream in("medicine.csv", ios::in|ios::binary);
      fstream out("temp.csv", ios::out|ios::binary);
      string med_name;
      long int med_id;
      while (ch<1 && ch>2)
      {
        cout<<"Invalid Choice!, Re-enter: ";
        cin>>ch;
      }
      if (ch == 1)
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine Name: ";
        getline(cin, med_name);
      }
      else
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\tEnter Medicine ID: ";
        cin>>med_id;
      }

      while (!in.eof())
      {
        while(getline(in, line))
        {
          stringstream lines;
          lines << line;
          string s1;
          vector<string> s;
          int flag = 0;
          while (getline(lines, s1, ','))
            s.push_back(s1);
          if (s[1] == med_name || s[3] == to_string(med_id))
          {
            flag = 1;
            cout<<"\n\t\t\t\t\t\t\t\t\t|||   DELETING MEDICINE WITH   |||\n";
            cout<<"\n\t\t\t\t\t\t\t\t\tMedicine Name: "<<s[1];
            cout<<"\n\t\t\t\t\t\t\t\t\tMedicine ID: "<<s[2];
            cout<<"\n\t\t\t\t\t\t\t\t\tPrice: "<<s[3];
            cout<<"\n\t\t\t\t\t\t\t\t\tSafety Threshold: "<<s[4];
            cout<<"\n\n\n\t\t\t\t\t\t\t\t\tDELETED SUCCESSFULLY!"<<endl;
          }
        }
      }
      in.close();
      out.close();
      remove("medicine.csv");
      rename("temp.csv", "medicine.csv");
    }
};

class User
{
  public:
    void search()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t|||         SEARCH DATABASE         |||\n\n";
      print_dash(170);
      string s_keyword;
      cout<<"\n\t\t\t\t\t\t\t\t\tEnter search keyword: ";
      cin>>s_keyword;
      fstream hos("hospital.csv", ios::in);
      fstream med("medicine.csv", ios::in);
      vector<string> hos_results, med_results;
      string line, line2;
      while (!hos.eof())
      {
        while (getline(hos, line))
        {
          stringstream line1;
          line1 << line;
          while (getline(line1, line2, ','))
            if (line2 == s_keyword)
              hos_results.push_back(line);
        }
      }
      hos.close();
      while (!med.eof())
      {
        while (getline(med, line))
        {
          stringstream line1;
          line1 << line;
          while (getline(line1, line2, ','))
            if (line2 == s_keyword)
              med_results.push_back(line);
        }
      }
      med.close();
      int a = hos_results.size();
      int b = med_results.size();

      if (a == 0  && b == 0)
        cout<<"No search results found"<<endl;

      else if (a == 0)
      {
        cout<<"Showing search results from MEDICINE database"<<endl;
        cout<<"\n\nHOSPITAL ID\t\tNAME\t\t\tMEDICINE ID\t\tPRICE\t\t\tUP LIMIT\n\n";
        for (int i=0; i<b; i++)
        {
          stringstream t;
          t << med_results[i];
          string s;
          while (getline(t, s, ','))
            cout<<s<<"\t\t\t";
          cout<<'\n';
        }
      }

      else if (b == 0)
      {
        cout<<"Showing search results from HOSPITAL database"<<endl;
        cout<<"\n\nHOSPITAL CODE\t\tHOSPITAL NAME\t\tDISTRICT\t\t\tADDRESS\n\n";
        for (int i=0; i<b; i++)
        {
          stringstream t;
          t << hos_results[i];
          string s;
          while (getline(t, s, ','))
            cout<<s<<"\t\t\t";
          cout<<'\n';
        }
      }

      else
      {
        cout<<"Showing search results from HOSPITAL & MEDICINE database"<<endl;
        cout<<"\n\nHOSPITAL CODE\t\tHOSPITAL NAME\t\tDISTRICT\t\t\tADDRESS\n\n";
        for (int i=0; i<a; i++)
        {
          stringstream t;
          t << hos_results[i];
          string s;
          while (getline(t, s, ','))
            cout<<s<<"\t\t\t";
          cout<<'\n';
        }
        cout<<"\n\n\n\nHOSPITAL ID\t\tNAME\t\t\tMEDICINE ID\t\tPRICE\t\t\tUP LIMIT\n\n";
        for (int i=0; i<b; i++)
        {
          stringstream t;
          t << med_results[i];
          string s;
          while (getline(t, s, ','))
            cout<<s<<"\t\t\t";
          cout<<'\n';
        }
      }

      char ch;
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tReturn to menu? Y/N: ";
      cin>>ch;
      while (ch == 'N' || ch == 'n')
      {
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\tReturn to menu? Y/N: ";
        cin>>ch;
      }
      menu();
    }

    void viewdetails()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t|||         VIEW DETAILS DATABASE         |||\n\n";
      print_dash(170);
      cout<<"\n\t\t\t\t\t\t\t\t1. View Hospital Database.";
      cout<<"\n\t\t\t\t\t\t\t\t2. View Medicine Database.";
      cout<<"\n\t\t\t\t\t\t\t\t3. Exit.";
      cout<<"\n\n\t\t\t\t\t\t\t\tEnter Choice: ";
      int user_ch;
      cin>>user_ch;
      while (user_ch < 1 && user_ch > 3)
      {
        cout<<"Invalid Choice. Re-enter: ";
        cin>>user_ch;
      }
      if (user_ch == 1)
      {
        Hospital h;
        h.display();
      }
      else if (user_ch == 2)
      {
        Medicine m;
        m.display();
      }
      else
        exit(0);

      char ch;
      cout<<"\n\n\nReturn to menu? Y/N: ";
      cin>>ch;
      while (ch == 'N' || ch == 'n')
      {
        cout<<"\n\n\nReturn to menu? Y/N: ";
        cin>>ch;
      }
    }

    void usermenu()
    {
      system("cls");
      print_dash(170);
      cout<<"\n\n\t\t\t\t\t\t\t|||         GUEST USER MENU         |||\n\n";
      print_dash(170);
      cout<<"\n\t\t\t\t\t\t\t\t1. View Hospital & Medicine Database.";
      cout<<"\n\t\t\t\t\t\t\t\t2. Search through Hospital & Medicine Database.";
      cout<<"\n\t\t\t\t\t\t\t\t3. Exit";
      cout<<"\n\n\t\t\t\t\t\t\t\tEnter Choice: ";
      int user_ch;
      cin>>user_ch;
      while (user_ch < 1 || user_ch > 3)
      {
        cout<<"\n\n\t\t\t\t\t\t\t\t\tInvalid Choice! Re-enter: ";
        cin>>user_ch;
      }
      if (user_ch == 1)
        viewdetails();
      else if (user_ch == 2)
        search();
      else
        exit(0);
    }
};

int login(int choice)
{
  if (choice == 1)
  {
    fstream admin("admin.csv", ios::in|ios::binary);
    string id_temp, pass_temp, line;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter Username: ";
    cin>>id_temp;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Password: ";
    cin>>pass_temp;
    cout<<id_temp<<endl;
    cout<<pass_temp<<endl;
    int count = 0;
    while (!admin.eof())
    {
      while (getline(admin, line, ','))
      {
        cout<<line<<endl;
        cout<<(line == id_temp)<<endl;
        cout<<(line == pass_temp)<<endl;
        if (line == id_temp)
          ++count;
        if (line == pass_temp)
          ++count;
      }
    }
    admin.close();
    if (count == 2)
      return 1;
    else
      return 0;
  }

  else if (choice == 2)
  {
    fstream employee("employee.csv");
    string id_temp, pass_temp, line;
    int i;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter Username: ";
    cin>>id_temp;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Password: ";
    cin>>pass_temp;
    int count = 0;
    while (!employee.eof())
    {
      while (getline(employee, line, ','))
      {
        if (line == id_temp)
          ++count;
        if (line == pass_temp)
          ++count;
      }
    }
    employee.close();
    if (count == 2)
      return 1;
    else
      return 0;
  }

  else if (choice == 3)
  {
    User u;
    u.usermenu();
  }
}

int hospital_access()
{
  system("cls");
  cout<<'\n';
  print_dash(170);
  cout<<"\n\n\t\t\t\t\t\t\t\t|||   HOSPITAL DATABASE MANAGEMENT   |||\n\n";
  print_dash(170);
  cout<<"\n\n\n\t\t\t\t\t\t\t\t\t|||   MENU   |||\n";
  cout<<"\n\t\t\t\t\t\t\t\t\t1. Add Hospital";
  cout<<"\n\t\t\t\t\t\t\t\t\t2. Edit Hospital";
  cout<<"\n\t\t\t\t\t\t\t\t\t3. Delete Hospital";
  cout<<"\n\t\t\t\t\t\t\t\t\t4. Display Hospital";
  cout<<"\n\t\t\t\t\t\t\t\t\t5. Exit";
  cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Choice: ";
  int choice;
  cin>>choice;
  while (choice<1 && choice>5)
  {
    cout<<"\n\n\t\t\t\t\t\t\t\t\tInvalid choice entered. Re-enter: ";
    cin>>choice;
  }

  Hospital H;

  if (choice == 1)
  {
    cout<<'\n';
    print_hash(170);
    H.add();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tAdd more entries? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'Y' || ch == 'y')
    {
    	H.add();
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tAdd more entries? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 2)
  {
    cout<<'\n';
    print_hash(170);
    H.edit();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEdit more entries? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'Y' || ch == 'y')
    {
    	H.edit();
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEdit more entries? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 3)
  {
    cout<<'\n';
    print_hash(170);
    H.rem();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tRemove more entries? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'Y' || ch == 'y')
    {
    	H.rem();
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tRemove more entries? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 4)
  {
    cout<<'\n';
    print_hash(170);
    H.display();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tReturn to menu? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'N' || ch == 'n')
    {
      cout<<"\n\t\t\t\t\t\t\t\t\tReturn to menu? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 5)
    exit(0);

  return 0;
}

int medicine_access()
{
  system("cls");
  print_dash(170);
  cout<<"\n\n\t\t\t\t\t\t\t\t|||   MEDICINE DATABASE MANAGEMENT   |||\n\n";
  print_dash(170);
  cout<<"\n\n\n\t\t\t\t\t\t\t\t\t|||   MENU   |||\n";
  cout<<"\n\t\t\t\t\t\t\t\t\t1. Add Medicine";
  cout<<"\n\t\t\t\t\t\t\t\t\t2. Edit Medicine";
  cout<<"\n\t\t\t\t\t\t\t\t\t3. Delete Medicine";
  cout<<"\n\t\t\t\t\t\t\t\t\t4. Display Medicine";
  cout<<"\n\t\t\t\t\t\t\t\t\t5. Exit";
  cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Choice: ";
  int choice;
  cin>>choice;
  while (choice<1 && choice>4)
  {
    cout<<"\n\n\t\t\t\t\t\t\t\t\tInvalid choice entered. Re-enter: ";
    cin>>choice;
  }

  Medicine M;

  if (choice == 1)
  {
    cout<<'\n';
    print_hash(170);
    M.add();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tAdd more entries? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'Y' || ch == 'y')
    {
    	M.add();
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tAdd more entries? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 2)
  {
    cout<<'\n';
    print_hash(170);
    M.edit();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEdit more entries? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'Y' || ch == 'y')
    {
    	M.edit();
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEdit more entries? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 3)
  {
    cout<<'\n';
    print_hash(170);
    M.rem();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEdit more entries? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'Y' || ch == 'y')
    {
    	M.rem();
      cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEdit more entries? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 4)
  {
    cout<<'\n';
    print_hash(170);
    M.display();
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tReturn to menu? Y/N: ";
    char ch;
    cin>>ch;
    while (ch == 'N' || ch == 'n')
    {
      cout<<"\n\t\t\t\t\t\t\t\t\tReturn to menu? Y/N: ";
      cin>>ch;
    }
    menu();
  }

  else if (choice == 5)
    exit(0);

  return 0;
}

void admin_menu()
{
  system("cls");
  print_dash(170);
	cout<<"\n\n\t\t\t\t\t\t\t\t\t||| ADMIN MAIN MENU |||\n\n";
  print_dash(170);
  cout<<"\n\n\n\t\t\t\t\t\t\t\t\t1. Add/View/Edit/Remove HOSPITAL Data";
  cout<<"\n\t\t\t\t\t\t\t\t\t2. Add/View/Edit/Remove MEDICINE Data";
  cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Choice: ";
	int choice;
	cin>>choice;
  while (choice < 1 || choice > 2)
  {
    cout<<"\n\n\t\t\t\t\t\t\t\t\tInvalid Choice! Re-enter: ";
    cin>>choice;
  }
	if (choice == 1)
		hospital_access();
	else if (choice == 2)
		medicine_access();
}

void emp_menu()
{
  system("cls");
  print_dash(170);
	cout<<"\n\n\t\t\t\t\t\t\t\t\t||| EMPLOYEE MAIN MENU |||\n\n";
  print_dash(170);
  cout<<"\n\n\n\t\t\t\t\t\t\t\t\t1. Add/View/Edit/Remove MEDICINE Data";
  cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Choice: ";
	int choice;
	cin>>choice;
  while (choice != 1)
  {
    cout<<"\n\n\t\t\t\t\t\t\t\t\tInvalid Choice! Re-enter: ";
    cin>>choice;
  }
  medicine_access();
}

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
  {
    int x = login(1);
    while (x != 1)
    {
      cout<<"\n\n\t\t\t\t\t\t\t\t\tWrong Credentials! Enter again!";
      x = login(1);
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\tLogin Successful!";
    admin_menu();
  }

  else if (choice == 2)
  {
    int x = login(2);
    while (x != 1)
    {
      cout<<"\n\n\t\t\t\t\t\t\t\t\tWrong Credentials! Enter again!";
      x = login(2);
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\tLogin Successful!";
    emp_menu();
  }

  else if (choice == 3)
    login(3);

  else if (choice == 4)
    exit(0);

  else
    menu();
}

int main()
{
  system("mode 170,300");
  menu();
  return 0;
}
