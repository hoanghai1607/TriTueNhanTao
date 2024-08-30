#include<stdio.h>
#include<vector>


using namespace std;

int n, m;
vector<int> a[100];
//cung cap mang co 100 dinh

bool visited[100];
//kiem tra dinh da duoc duyet qua chua

void nhap() {
	printf("Nhap so dinh: "); scanf_s("%d", &n);
	printf("Nhap so canh: "); scanf_s("%d", &m);
	//n la so dinh
	//m la so canh noi cac dinh
	for (int i = 0; i < m; i++) {
		int x, y;
		printf("Nhap cap canh thu %d: ", i + 1);
		//cout << "Nhap cap canh thu " << i + 1 << ": ";
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		a[x].push_back(y);
		//x co con la y	{x,y}
		a[y].push_back(x);
		//y co cha la x	{y,x}

	}
	memset(visited, false, sizeof(visited));
	// set mac dinh cac trang thai visited la false

}

void dfs(int start, int end) {
	printf("%d ", start);
	//duyet qua dinh bat dau
	visited[start] = true;
	//duyet qua dinh start chuyen du trang thai thanh true
	for (int i : a[start]) {
		//duyet du lieu trong vector start
		if (visited[end] == true) {
			break;
			//vi mac dinh la false, nen khi dinh can tim la true thi thoat khoi vong lap
		}
		//neu dinh chua duoc tham thi de quy goi lai ham toi dinh v
		if (!visited[i]) {
			dfs(i, end);
		}
	}
}

int main() {
	nhap();
	int s, e;
	printf("Nhap dinh dau: "); scanf_s("%d", &s);
	printf("Nhap dinh cuoi: "); scanf_s("%d", &e);
	printf("Duong di can tim la: "); 
	//cout << "Nhap dinh dau: "; cin >> s;
	//cout << "Nhap dinh cuoi: "; cin >> e;
	//cout << "duong di can tim la: ";
	dfs(s, e);
	return 0;
}