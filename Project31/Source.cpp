//template <class T, class Allocator = Allocator<T>>
//class vector
//{
//	explicit vector(const Allocator& a = Allocator());
//	explicit vector(size_type num, const T& val = T()), const Allocator& a = Allocator();
//	vector(const vector <T, Allocator>& ob);
//	template <class InIter> vector(InIter start, InIter end, const Allocator& a = Allocator());
//};

//template <class InIter> void assign(InIter start, InIter end); Помещает в класс вектор последовательность, определяемую start и end

//void assign (size_type num, const &val) Помещает num элементов со значением val

//reference at (size_type i)
//const_reference at (size_type i) const; [] С проверкой за границы

//reference back();
//const_reference back() const; Возвращает сссылку на последний элемент в векторе

//iterator begin();
//const_iterator begin() const; Возвращает итератор для первого элемента в векторе

//size_type capaciy() const; Текущая ёмкость вектора до выделения доп памяти

//void clear();

//bool empty() const; Проверка заполненности вектора

//const_iterator end() const;
//iterator end; Возвращает итератор для конца вектора

//iterator erase(iterator i); Удаляет элемент, адресуемый итератор I, возвращает итератор для элемента, расположенного после удалённого.

//reference front();
//const_reference front() const; Возвращает ссылку на первый элемент вектора

//allocator_type get_allocator() const; Возвращает распределитель вектора

//iterator insert(iterator i, const T &val=T()); Вставляет значение val непосредственно перед элементом, заданным параметром i, возвращает итератор
//для этого элемента

//void insert(iterator i, size_type num, const T &val); Вставляет num копий значения val непосредственно перед элементом, заданным параметром i

//template <class InIter>
//void insert(iterator i, InIter start, InIter end); Вставляет в вектор последовательность, определяемую start и end, непосредственно перед элементом,
//заданным параметром i

//size_type max_size() const; Возвращает максимальное число элементов, которое может содержать вектор

//reference operator[](size_type i) const;
//const_reference operator[](size_ype i) const; Возвращает ссылку на элемент, заданный параметром i.

//void pop_back(); Удаляет последний элемент в векторе

//void push_back(const T &val); Добавляет в конец вектора элемент со значением, заданным параметром val.

//reverse_iterator rbegin();
//const_reverse_iterator rend() const; Возвращает реверсивный итератор для начала вектора

//void reverse(size_type num); Устанавливает ёмкость вектора равной не менее заданного значения num

//void resize(size_type num, const T &val=T()); Устанавливает ёмкость вектора равной не менее заданного значения num, если вектор для этого нужно
//удлинить, то в его конец добавляются элементы со значением, заданным параметром val.

//size_type size() const; Возвращает текущее количество элементов в векторе.

//void swap(deque <T, Allocator>&ob) Выполняет обмен элементами данного вектора и вектора ob.

//void flip(); Инвертирует значение всех битов в векторе.

//static void swap(reference i, reference j); Переставляет местами биты, заданные параметрами i и j.

#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//Создаём вектор
	vector<int> vect;

	cout << "\nNumber of elements that could be stored in the vector without allocating more storage --> " << vect.capacity()
		<< "\n------------------------------------"
		//используя метод size() получаем текущее кол-во элементов в векторе.
		<< "\nThe number of elements in the vector --> " << vect.size()
		<< "\n -----------------------------------";
	vect.resize(4, 0);
	cout << "\nResizing ...\n"
		<< "\nThe number of elements in the vector --> " << vect.size() << "\n";

	cout << "\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << "\t";
	cout << "\n-----------------------------------";

	//минимальный размер вектора
	//метод max_size() возвращает количество байт
	cout << "\nThe maximum possible lenght of the vector -->"
		<< vect.max_size() / 4;
	cout << "\n-----------------------------------";

	vect.push_back(1);
	cout << "\npush_back\nvector-->\t";
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << "\t";
	cout << "\n-----------------------------------";

	vector<int>::reverse_iterator i_riterator = vect.rbegin();
	cout << "\nreverse_iterator\nvector -->\t";

	for (int i = 0; i < vect.size(); i++)
		cout << *(i_riterator + i) << "\t";

	vector<int>::iterator i_iterator = vect.end();

	vect.insert(i_iterator - 1, -1);

	cout << "\ninsert\nvector -->\t";
	for (i_iterator = vect.begin(); i_iterator != vect.end(); i_iterator++)
		cout << *(i_iterator) << '\t';
	cout << "\n-----------------------------------";

	i_iterator = vect.end();
	vect.insert(i_iterator - 1, 2, 4);
	cout << "\nInsert\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << "\t";
	cout << "\n----------------------------------";
}