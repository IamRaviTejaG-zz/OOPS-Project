string pass_input()
{
  int i=0;
  string s;
  while(1)
  {
    system("cls");
    s[i] = getch();
    for(int j=0; j<i; j++)
    cout<<'*';
    if (s[i++] == 13)
      break;
  }
  return s;
}

int login (int choice)
{
  if (choice == 1)
  {
    fstream admin("admin.csv");
    string id, id_temp, pass, pass_temp, line;
    int i;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter Username: ";
    cin>>id_temp;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Password: ";
    pass_temp = pass_input()
    while (!admin.eof())
    {
      for(i=0; line[i]!=','; i++)
        id[k++] = line[i];
      i++;
      k=0;
      for (i; line[i]!=','; i++)
        pass[k++] = line[i];
      if (pass_temp == pass &&  id_temp == id)
        return 1;
      else
        return 0;
    }
    admin.close();
  }

  else if (choice == 2)
  {
    fstream employee("employee.csv");
    string id, id_temp, pass, pass_temp, line;
    int i;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter Username: ";
    cin>>id_temp;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Password: ";
    pass_temp = pass_input()
    while (!employee.eof())
    {
      for(i=0; line[i]!=','; i++)
        id[k++] = line[i];
      i++;
      k=0;
      for (i; line[i]!=','; i++)
        pass[k++] = line[i];
      if (pass_temp == pass &&  id_temp == id)
        return 1;
      else
        return 0;
    }
    employee.close();
  }

  return 0;
}
