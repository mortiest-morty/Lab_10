# include "Header.h"

int HowMuchNumbers() {
	using namespace std;
	int cnt;
	cout << "Введите количество чисел для ввода: ";
	cin >> cnt;
	while (cnt < 0 || cnt == 0) {
		cout << "Ошибка! Введите натуральное число!";
		cin >> cnt;
	}
	return cnt;
}

void Add(int data, TNode& Head) {
	TNode MyNode;
	if (Head == nullptr)
	{
		Head = new Node;
		Head->Next = nullptr;
	}
	else
	{
		MyNode = new Node;
		MyNode->Next = Head;
		Head = MyNode;
	}
	Head->data = data;
}

TNode FindTheEvenNumber(TNode Head){
	TNode q = Head;
	while (q && q->data %2!=0)
		q = q->Next;
	return q;
}

void Show(TNode Head){
	using namespace std;

	TNode MyNode;
	while (Head != nullptr)
	{
		MyNode = Head;
		cout << Head->data << " ";
		Head = Head->Next;
	}
}

void task_1() {
	using namespace std;
	TNode P1 = nullptr;
	TNode P2 = nullptr;
	int n, cnt;
	cout << "=== Заполнение 1-ого стека ===" << endl;

	cnt = HowMuchNumbers();

	for (int i = 0; i < cnt; i++) {
		cout << "Введите число: ";
		cin >> n;
		Add(n, P1);
	}
	cout << "\nСодержимое 1 стека: ";
	Show(P1);

	cout << "\n\n=== Заполнение 2-ого стека ===\n";

	cnt = HowMuchNumbers();

	for (int i = 0; i < cnt; i++){
		cout << "Введите число: ";
		cin >> n;
		Add(n, P2);
	}
	cout << "\nСодержимое 2 стека: ";
	Show(P2);

	if (FindTheEvenNumber(P1)) {
		TNode p;
		while (P1->data % 2 != 0) {
			TNode temp = P1;      
			P1 = P1->Next;      
			temp->Next = P2;       
			P2 = temp;
		}
	}
	else{
		cout << "\nЧетных чисел в первом стеке нет :(\n";
		TNode p;
		while (P1 != nullptr) {
			TNode temp = P1;
			P1 = P1->Next;
			temp->Next = P2;
			P2 = temp;
		}
	}

	cout << "\n\nСодержимое 1 стека: ";
	Show(P1);
	cout << "\nСодержимое 2 стека: ";
	Show(P2);
	
	cout << "\n\nАдрес P1: " << P1 << endl;
	cout << "Адрес P2: " << P2 << endl;
}

void AddToQueue(int data, TNode& Head, TNode &Tail) {
	TNode Temp;			
	if (Head == nullptr)
	{
		Head = new Node;
		Tail = Head;
		Head->Next = nullptr;
	}
	else
	{
		Temp = new Node;
		Tail->Next = Temp;
		Tail = Temp;
		Tail->Next = nullptr;
	}
	Tail-> data = data;
}


void task_2() {
	using namespace std;
	TNode P1 = nullptr, P2 = nullptr;
	int n, D, firstElement, cnt;

	cout << "=== Заполнение очереди ===" << endl;

	cnt = HowMuchNumbers();

	for (int i = 0; i < cnt; i++){
		cout << "Введите число: ";
		cin >> n;
		AddToQueue(n, P1, P2);
	}
	cout << "\nСодержимое очереди: ";
	Show(P1);

	cout << "\nВведите число D: ";
	cin >> D;
	
	AddToQueue(D, P1, P2);
	TNode p;
	firstElement = P1->data;
	p = P1;
	P1 = P1->Next;
	delete(p);
	cout << "Первый элемент очереди: " << firstElement;
	cout << "\nСодержимое очереди: ";
	Show(P1);
	cout << "\n\nАдрес P1: " << P1 << endl;
	cout << "Адрес P2: " << P2 << endl;
}

void ShowList(TNode& Head) {
	using namespace std;

	TNode MyNode = Head;
	while (MyNode != nullptr){
		cout << MyNode->data << " ";
		MyNode = MyNode->Next;
	}
}
void task_3() {
	using namespace std;
	TNode P1 = nullptr, Tail = nullptr, P8 = nullptr;
	int n, cnt = 1, count;

	cout << "=== Заполнение списка ===" << endl;

	count = HowMuchNumbers();
	while (count < 8) {
		cout << "Ошибка! По условию чисел должно быть => 8\nВведите количество чисел: ";
		cin >> count;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "Введите число: ";
		cin >> n;
		AddToQueue(n, P1, Tail);
	}
	cout << "\nСодержимое списка: ";
	ShowList(P1);

	P8 = P1;
	while (cnt != 8) {
		P8 = P8->Next;
		cnt++;
	}
	cout << "\nВосьмой элемент списка: " << P8->data;
}

void AddAfter4Numbers(int M, TNode Head) {
	TNode p, newp;
	p = Head;
	int cnt = 1;
	while (p != nullptr) {
		if (cnt % 4 != 0) {
			p = p->Next;
			cnt++;
		}
		else {
			newp = new Node;
			newp->data = M;
			newp->Next = p->Next;
			p->Next = newp;
			p = newp->Next;
			cnt++;
		}
	}
}

void task_4() {
	using namespace std;
	TNode P1 = nullptr, P2 = nullptr;
	int n, M, cnt;

	cout << "=== Заполнение списка ===" << endl;

	cnt = HowMuchNumbers();

	for (int i = 0; i < cnt; i++)
	{
		cout << "Введите число: ";
		cin >> n;
		AddToQueue(n, P1, P2);
	}
	cout << "\nСодержимое списка: ";
	ShowList(P1);

	cout << "\nВведите число M: ";
	cin >> M;

	AddAfter4Numbers(M, P1);
	cout << "\nСодержимое списка: ";
	ShowList(P1);
}

void sortInsert(int* m, int n){
	int j, r;
	for (int i = 1; i < n; i++)
	{
		r = m[i]; 
		j = i - 1;
		while (j >= 0 && m[j] > r)
		{
			m[j + 1] = m[j];

			j--;
		}
		m[j + 1] = r;
	}
}

void task_5() {
	using namespace std;
	string filename;
	TNode P1 = nullptr, P2 = nullptr;
	int N;

	cout << "Введите имя файла: ";
	cin >> filename;
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	
	file >> N;

	int* a = new int[N];
	for (int i = 0; i < N; i++) {
		file >> a[i];
	}
	file.close();

	sortInsert(a, N);

	for (int i = 0; i < N; i++) {
		AddToQueue(a[i], P1, P2);
	}

	cout << "\nСодержимое списка: ";
	ShowList(P1);
	cout << endl;

	delete[] a;
}

