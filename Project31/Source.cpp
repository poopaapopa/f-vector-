//template <class T, class Allocator = Allocator<T>>
//class vector
//{
//	explicit vector(const Allocator& a = Allocator());
//	explicit vector(size_type num, const T& val = T()), const Allocator& a = Allocator();
//	vector(const vector <T, Allocator>& ob);
//	template <class InIter> vector(InIter start, InIter end, const Allocator& a = Allocator());
//};

//template <class InIter> void assign(InIter start, InIter end); �������� � ����� ������ ������������������, ������������ start � end

//void assign (size_type num, const &val) �������� num ��������� �� ��������� val

//reference at (size_type i)
//const_reference at (size_type i) const; [] � ��������� �� �������

//reference back();
//const_reference back() const; ���������� ������� �� ��������� ������� � �������

//iterator begin();
//const_iterator begin() const; ���������� �������� ��� ������� �������� � �������

//size_type capaciy() const; ������� ������� ������� �� ��������� ��� ������

//void clear();

//bool empty() const; �������� ������������� �������

//const_iterator end() const;
//iterator end; ���������� �������� ��� ����� �������

//iterator erase(iterator i); ������� �������, ���������� �������� I, ���������� �������� ��� ��������, �������������� ����� ���������.

//reference front();
//const_reference front() const; ���������� ������ �� ������ ������� �������

//allocator_type get_allocator() const; ���������� �������������� �������

//iterator insert(iterator i, const T &val=T()); ��������� �������� val ��������������� ����� ���������, �������� ���������� i, ���������� ��������
//��� ����� ��������

//void insert(iterator i, size_type num, const T &val); ��������� num ����� �������� val ��������������� ����� ���������, �������� ���������� i

//template <class InIter>
//void insert(iterator i, InIter start, InIter end); ��������� � ������ ������������������, ������������ start � end, ��������������� ����� ���������,
//�������� ���������� i

//size_type max_size() const; ���������� ������������ ����� ���������, ������� ����� ��������� ������

//reference operator[](size_type i) const;
//const_reference operator[](size_ype i) const; ���������� ������ �� �������, �������� ���������� i.

//void pop_back(); ������� ��������� ������� � �������

//void push_back(const T &val); ��������� � ����� ������� ������� �� ���������, �������� ���������� val.

//reverse_iterator rbegin();
//const_reverse_iterator rend() const; ���������� ����������� �������� ��� ������ �������

//void reverse(size_type num); ������������� ������� ������� ������ �� ����� ��������� �������� num

//void resize(size_type num, const T &val=T()); ������������� ������� ������� ������ �� ����� ��������� �������� num, ���� ������ ��� ����� �����
//��������, �� � ��� ����� ����������� �������� �� ���������, �������� ���������� val.

//size_type size() const; ���������� ������� ���������� ��������� � �������.

//void swap(deque <T, Allocator>&ob) ��������� ����� ���������� ������� ������� � ������� ob.

//void flip(); ����������� �������� ���� ����� � �������.

//static void swap(reference i, reference j); ������������ ������� ����, �������� ����������� i � j.

#include <iostream>
#include <vector>
using namespace std;

void main()
{
	//������ ������
	vector<int> vect;

	cout << "\nNumber of elements that could be stored in the vector without allocating more storage --> " << vect.capacity()
		<< "\n------------------------------------"
		//��������� ����� size() �������� ������� ���-�� ��������� � �������.
		<< "\nThe number of elements in the vector --> " << vect.size()
		<< "\n -----------------------------------";
	vect.resize(4, 0);
	cout << "\nResizing ...\n"
		<< "\nThe number of elements in the vector --> " << vect.size() << "\n";

	cout << "\nvector -->\t";
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << "\t";
	cout << "\n-----------------------------------";

	//����������� ������ �������
	//����� max_size() ���������� ���������� ����
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