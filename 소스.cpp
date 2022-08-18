#include<iostream>
#include<string.h>

using namespace std;

int N, area;
int map[302][302]; 
int land_mine[302][302];
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

void dfs(int, int);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count;
		
		/*�ʱ�ȭ*/
		area = 0;
		memset(map, 0, sizeof(map));
		memset(land_mine,-1, sizeof(land_mine));

		cin >> N;

		for (int i = 1; i <= N; i++) {
			string str;
			cin >> str;

			for (int j = 1; j <= N; j++) {
				map[i][j] = str[j - 1];

			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				count = 0;

				//���ڰ� �ƴѰ�� �ֺ��� ���ڰ� � �ִ��� Ȯ��
				if (map[i][j] == '.') {
					for (int k = 0; k < 8; k++) {
						int c_x = i + dx[k];
						int c_y = j + dy[k];
						
						if (map[c_x][c_y] == '*')
							count++;
					}

					//���� ���� ����
					land_mine[i][j] = count ;
					}

				//������ ��� ���� �����ϴ� �迭�ȿ� -1 ����
				else {
					land_mine[i][j] = -1;
				}
				}
			}

		//�ֺ��� ���ڰ� �ϳ��� ���� ���� �湮���� �ʾҴٸ� �ش� ������ ũ�� Ȯ��
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (land_mine[i][j] == 0 && map[i][j] == '.') {
				
					dfs(i, j);
					area++;
				}
			}
		}

		//�ֺ��� ���ڰ� �ִ� ĭ�鸸 �����ִ°�� ĭ������ŭ ������
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == '.') {
					area++;
				}
			}
		}
		cout << '#' << test_case << ' ' << area << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void dfs(int x, int y) {

	//�湮�ߴٴ°��� ������
	map[x][y] = land_mine[x][y]+'0';

	//�ֺ� ĭ���� Ȯ���ؼ� �ֺ��� ���ڰ����� 0��ĭ�� ������ �Լ��� �ڱ��ڽ��� ȣ��
	for (int k = 0; k < 8; k++) {
		int c_x = x + dx[k];
		int c_y = y + dy[k];

		if (map[c_x][c_y] == '*') continue;
		if (land_mine[c_x][c_y] == 0 &&  map[c_x][c_y]=='.') {
			dfs(c_x, c_y);
		}
		else {
			map[c_x][c_y] = land_mine[c_x][c_y] + '0';
		}
	}

}