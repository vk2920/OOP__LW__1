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
	/// Базовый конструктор, создающик класс с пустой очередью
	/// </summary>
	Queue(int _editable = 0);

	/// <summary>
	/// Конструктор, создающий класс с одним элементом в очереди
	/// </summary>
	/// <param name="_data">Информационное поле</param>
	Queue(list_item_data _data, int _editable = 0);

	/// <summary>
	/// Конструктор, создающий копию существующего класса
	/// </summary>
	/// <param name="_copy"></param>
	Queue(const Queue& _copy, int _editable = 0);

	/// <summary>
	/// Метод класса для вывода значений всех полей класса
	/// </summary>
	/// <param name="_selected">Выбор полей, которые надо вывести</param>
	void print_fields(const int _selected = 0b11);

	/// <summary>
	/// Изменяет значение отдельного поля класса на переданное
	/// Для реализации создано отдельное поле класса, чтобы не нарушить работу программы
	/// </summary>
	/// <param name="_editable">Новое значение поля для объекта</param>
	void set_editable_field(const int _editable = 0);

	/// <summary>
	/// Метод класса для получения элемента из очереди
	/// </summary>
	/// <param name="_delete">Удалять ли получаемый элемент из оереди?</param>
	/// <returns>Первый элемент в очереди</returns>
	list_item_data get_item(const bool _delete = true);

	/// <summary>
	/// Метод для добавления нового элемента в очередь
	/// </summary>
	/// <param name="_data">Информационное поле для нового элемента</param>
	/// <returns>True, если элемент добавлен в очередь, иначе False</returns>
	bool add_item(list_item_data _data);

	/// <summary>
	/// Метод для добавления элемента в очередь
	/// Создаёт структуру из переданных полей и использует свою перегрузку
	/// </summary>
	/// <param name="_protons_count">Число протонов в ядре атома</param>
	/// <param name="_name">Название элемента</param>
	/// <returns>Результат вызова перегруженного метода</returns>
	bool add_item(int _protons_count, char _name[30]);

	/// <summary>
	/// Метод для очистки очереди
	/// Полностью очищает очередь, но не уничтожает объект класса
	/// </summary>
	/// <returns>True, если очередь очищена, иначе False</returns>
	bool clear_items();

	/// <summary>
	/// Метод для проверки очереди на наличие двух и более элементов с одинаковым зарядом
	/// </summary>
	/// <returns>True, если найдена хотя бы одна пара, иначе False</returns>
	bool check_queue();

	/// <summary>
	/// Деструктор объекта класса, очищает всю очередь, накопленную за время существования класса
	/// </summary>
	~Queue();
};