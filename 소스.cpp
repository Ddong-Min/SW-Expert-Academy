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
		
		/*초기화*/
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

				//지뢰가 아닌경우 주변에 지뢰가 몇개 있는지 확인
				if (map[i][j] == '.') {
					for (int k = 0; k < 8; k++) {
						int c_x = i + dx[k];
						int c_y = j + dy[k];
						
						if (map[c_x][c_y] == '*')
							count++;
					}

					//지뢰 개수 저장
					land_mine[i][j] = count ;
					}

				//지뢰일 경우 개수 저장하는 배열안에 -1 저장
				else {
					land_mine[i][j] = -1;
				}
				}
			}

		//주변에 지뢰가 하나도 없고 아직 방문하지 않았다면 해당 구역의 크기 확인
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (land_mine[i][j] == 0 && map[i][j] == '.') {
				
					dfs(i, j);
					area++;
				}
			}
		}

		//주변에 지뢰가 있는 칸들만 남아있는경우 칸개수만큼 더해줌
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == '.') {
					area++;
				}
			}
		}
		cout << '#' << test_case << ' ' << area << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void dfs(int x, int y) {

	//방문했다는것을 보여줌
	map[x][y] = land_mine[x][y]+'0';

	//주변 칸들을 확인해서 주변에 지뢰개수가 0인칸이 있으면 함수가 자기자신을 호출
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