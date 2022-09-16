#pragma once

typedef struct list_item_data {
	short protons_count;
	char name[30];
} list_item_data;

typedef struct list_item {
	list_item_data data;
	list_item* next;
} list_item;

class Queue {
	list_item* first;
	int editable_field;
public:
	/// <summary>
	/// ������� �����������, ��������� ����� � ������ ��������
	/// </summary>
	Queue(int _editable = 0);

	/// <summary>
	/// �����������, ��������� ����� � ����� ��������� � �������
	/// </summary>
	/// <param name="_data">�������������� ����</param>
	Queue(list_item_data _data, int _editable = 0);

	/// <summary>
	/// �����������, ��������� ����� ������������� ������
	/// </summary>
	/// <param name="_copy"></param>
	Queue(const Queue& _copy, int _editable = 0);

	/// <summary>
	/// ����� ������ ��� ������ �������� ���� ����� ������
	/// </summary>
	/// <param name="_selected">����� �����, ������� ���� �������</param>
	void print_fields(const int _selected = 0b11);

	/// <summary>
	/// �������� �������� ���������� ���� ������ �� ����������
	/// ��� ���������� ������� ��������� ���� ������, ����� �� �������� ������ ���������
	/// </summary>
	/// <param name="_editable">����� �������� ���� ��� �������</param>
	void set_editable_field(const int _editable = 0);

	/// <summary>
	/// ����� ������ ��� ��������� �������� �� �������
	/// </summary>
	/// <param name="_delete">������� �� ���������� ������� �� ������?</param>
	/// <returns>������ ������� � �������</returns>
	list_item_data get_item(const bool _delete = true);

	/// <summary>
	/// ����� ��� ���������� ������ �������� � �������
	/// </summary>
	/// <param name="_data">�������������� ���� ��� ������ ��������</param>
	/// <returns>True, ���� ������� �������� � �������, ����� False</returns>
	bool add_item(list_item_data _data);

	/// <summary>
	/// ����� ��� ���������� �������� � �������
	/// ������ ��������� �� ���������� ����� � ���������� ���� ����������
	/// </summary>
	/// <param name="_protons_count">����� �������� � ���� �����</param>
	/// <param name="_name">�������� ��������</param>
	/// <returns>��������� ������ �������������� ������</returns>
	bool add_item(int _protons_count, char _name[30]);

	/// <summary>
	/// ����� ��� ������� �������
	/// ��������� ������� �������, �� �� ���������� ������ ������
	/// </summary>
	/// <returns>True, ���� ������� �������, ����� False</returns>
	bool clear_items();

	/// <summary>
	/// ����� ��� �������� ������� �� ������� ���� � ����� ��������� � ���������� �������
	/// </summary>
	/// <returns>True, ���� ������� ���� �� ���� ����, ����� False</returns>
	bool check_queue();

	/// <summary>
	/// ���������� ������� ������, ������� ��� �������, ����������� �� ����� ������������� ������
	/// </summary>
	~Queue();
};