#include<iostream>
#include<vector>
#include<string>

#include "K-AVL.h"

using namespace std;


int main(int arg, char *argv[])
{
	vector<string> alldata;
	string find_data = argv[1];
	for (unsigned int i = 0; i < find_data.size(); i++)
	{
		if ((find_data[i] == '\r') || (find_data[i] == '\n'))
		{
			find_data = find_data.substr(0, i);
		}
	}

	find_data = find_data + ",";
	int p = 0, q = 0;
	while (q < find_data.size())
	{
		if (find_data[q] == ',')
		{
			if (find_data.substr(p, q - p).size() != 0) 
			{
				alldata.push_back(find_data.substr(p, q - p));
			}
			p = q + 1;
		}
		q++;
	}
	K_AVL aK_AVL(stoi(alldata[0]));
	for (int i = 1; i < alldata.size();i++)
	{
		vector<string> suballdata;
		for (unsigned int i = 0; i < alldata[i].size(); i++)
		{
			if ((alldata[i][i] == '\r') || (alldata[i][i] == '\n'))
			{
				alldata[i] = alldata[i].substr(0, i);
			}
		}

		alldata[i] = alldata[i] + " ";
		int p = 0, q = 0;
		while (q < alldata[i].size())
		{
			if (alldata[i][q] == ' ')
			{
				if (alldata[i].substr(p, q - p).size() != 0) 
				{
					suballdata.push_back(alldata[i].substr(p, q - p));
				}
				p = q + 1;
			}
			q++;
		}
		if (suballdata[0] == "insert")
		{
			aK_AVL.Insert(pair<int, int>(stoi(suballdata[1]), stoi(suballdata[2])));
		}
		else if (suballdata[0] == "search")
		{
			aK_AVL.Search(pair<int, int>(stoi(suballdata[1]), stoi(suballdata[2])));
		}
		else if (suballdata[0] == "approx_search")
		{
			aK_AVL.ApproximateSearch(pair<int, int>(stoi(suballdata[1]), stoi(suballdata[2])));
		}
		else if (suballdata[0] == "in_order")
		{
			aK_AVL.InOrderPrint();
		}
		else if (suballdata[0] == "pre_order")
		{
			aK_AVL.PreOrderPrint();
		}
		else if (suballdata[0] == "delete")
		{
			aK_AVL.Delete(pair<int, int>(stoi(suballdata[1]), stoi(suballdata[2])));
		}
	}
	return 0;
}
