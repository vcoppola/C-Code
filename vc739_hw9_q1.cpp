#include<iostream>
#include<vector>
#include<cstdlib>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdlib.h>


using namespace std;
struct node
{
	int info;
	float rate;
	string name;
	int hours;
	int earning;
	struct node *next;
	struct node *prev;
}*start;


class Employee_data
{
public:
	void create_list(int value, float rate, string name);
	void add_after(int value, float rate, string name, int position);
	void display_dlist();
	void update_hour(int id, int hours);

	Employee_data()
	{
		start = NULL;
	}
};


int main()
{
	int choice, element, position, flag = 0, id;
	float rate;
	Employee_data dl;


	string name, line, s = "", t;
	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		int records = 0;
		while (getline(myfile, line))
		{
			int i = 0;
			records++;
			s = "";
			flag = 0;
			t = line;
			while (i<t.length())
			{
				if (i == t.length() - 1 || flag>1)
				{
					s = s + t[i];
					name = s;

				}
				else  if (t[i] != ' ')
				{
					s = s + t[i];

				}

				else
				{
					flag++;
					if (flag == 1)
					{
						id = stoi(s);
						s = ' ';
					}
					if (flag == 2)
					{
						rate = stof(s);
						s = "";
					}

				}

				i++;
			}
			if (records == 1)
			{
				dl.create_list(id, rate, name);
			}
			else
			{
				dl.add_after(id, rate, name, records - 1);
			}

		}
		myfile.close();
	}

	else cout << "Unable to open file";

	ifstream my("hours.txt");
	if (my.is_open())
	{
		int records = 0;
		while (getline(my, line))
		{

			int i = 0;
			int id, hours;
			string s = "";
			while (i <= line.length())
			{
				if (i == line.length())
				{
					//cout<<s;
					hours = stoi(s);
				}
				else if (line[i] == ' ')
				{

					id = stoi(s);
					s = "";
				}
				else {
					s = s + line[i];
				}

				i++;
			}
			dl.update_hour(id, hours);
		}
	}
	dl.display_dlist();

	return 0;
}

void Employee_data::create_list(int value, float rate, string name)
{
	struct node *s, *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	temp->rate = rate;
	temp->name = name;
	temp->hours = 0;
	temp->earning = 0;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		s = start;
		while (s->next != NULL)
			s = s->next;
		s->next = temp;
		temp->prev = s;
	}

}


void Employee_data::add_after(int value, float rate, string name, int pos)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		return;
	}
	struct node *tmp, *q;
	int i;
	q = start;
	for (i = 0; i < pos - 1; i++)
	{
		q = q->next;
		if (q == NULL)
		{
			cout << "There are less than ";
			cout << pos << " elements." << endl;
			return;
		}
	}
	tmp = new(struct node);
	tmp->info = value;
	tmp->rate = rate;
	tmp->name = name;
	tmp->hours = 0;
	tmp->earning = 0;
	if (q->next == NULL)
	{
		q->next = tmp;
		tmp->next = NULL;
		tmp->prev = q;
	}
	else
	{
		tmp->next = q->next;
		tmp->next->prev = tmp;
		q->next = tmp;
		tmp->prev = q;
	}

}


void Employee_data::display_dlist()
{
	struct node *q;
	if (start == NULL)
	{
		cout << "List empty,nothing to display" << endl;
		return;
	}
	q = start;
	cout << "The Doubly Link List is :" << endl;
	vector< pair <int, string> > first;
	while (q != NULL)
	{
		cout << q->info << " " << q->rate << " " << " " << q->name << " " << q->hours << " " << q->earning << endl;
		first.push_back(make_pair(q->earning, q->name.c_str()));
		q = q->next;
	}
	sort(first.rbegin(), first.rend());
	cout << endl;
	cout << "Sorted Income:" << endl;
	for (std::vector< pair <int, string> >::iterator it = first.begin(); it != first.end(); ++it) {
		cout << it->second << " " << it->first << endl;
	}

}

void Employee_data::update_hour(int id, int hours)
{
	struct node *q;
	if (start == NULL)
	{
		cout << "List empty,nothing to display" << endl;
		return;
	}
	q = start;

	while (q != NULL)
	{
		if (q->info == id)
		{
			q->hours += hours;
			q->earning = q->hours*q->rate;
		}
		q = q->next;
	}

}

