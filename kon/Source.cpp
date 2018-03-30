#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int getInt(char s) 
{
	switch (s)
	{
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	}
}

char getChar(int i)
{
	switch (i)
	{
	case 0:
		return 'A';
	case 1:
		return 'B';
	case 2:
		return 'C';
	case 3:
		return 'D';
	case 4:
		return 'E';
	case 5:
		return 'F';
	case 6:
		return 'G';
	case 7:
		return 'H';
	}
}

int main() 
{
	int x[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
	int y[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
	queue <pair<int, int> > q;
	pair <int, int> start, end, temp, nan = make_pair(-1, -1);
	vector <vector <pair<int, int> > > p(8, vector <pair<int, int>>(8, nan));//���� 8�8 �� ��������� ��� -1 -1
	cout << "First cell:" << endl;
	char first;
	cin >> first;
	start.first = getInt(first);
	cin >> start.second;
	start.second--;
	cout << "The last cell:" << endl;
	cin >> first;
	end.first = getInt(first);
	cin >> end.second;
	end.second--;
	q.push(start);//�������� � ������� ���� �����
	p[start.first][start.second] = start;//�������� � ������ � ��������� ������ �������� ���� �����
	while (!q.empty()) 
	{
		temp = q.front();
		q.pop();
		if (temp == end)//���� ���� ����� �����
		{
			cout << "The way is : \n";
			vector <pair <int, int> > way;
			while (temp != start) 
			{
				way.push_back(temp);
				temp = p[temp.first][temp.second];
			}
			way.push_back(start);
			for (int i = way.size() - 1; i >= 0; i--)
			{
				way[i].second++;
				cout << getChar(way[i].first) << way[i].second << endl;
			}
			return 0;
		}
		for (int i = 0; i < 8; i++) 
		{
			int nx = temp.first + x[i];//���������� ��������� ����
			int ny = temp.second + y[i];//� ������� ������
			if (nx > 0 && ny > 0 && nx < 8 && ny < 8 && p[nx][ny] == nan) //���� � ������ ���� � ��������� ������������ ����(nx, ny) �� ��� ������ ���
			{
				p[nx][ny] = temp;//�������� � ������ ������������ ���� ������ ������ �� ������� ��� �������� ���
				q.push(make_pair(nx, ny));//�������� � � ����� ������ ������ ���� ��� �������� ���
			}
		}
	}
	return 0;
}