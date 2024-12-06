// spiso2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
using namespace std;

#include <iostream>
#include <string>
struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* list = nullptr;
	Node* current = list;
public:
	void push_front(int data)
	{
		Node* current = new Node(data);
		current->next = head;

		if (head != nullptr)
			head->prev = current;
		if (tail == nullptr)
			tail = current;

		head = current;
		std::cout << "Число добавлено в список" << std::endl;
	};
    void push_back(int data)
    {
        Node* current = new Node(data);
        current->prev = tail;

        if (tail != nullptr)
            tail->next = current;
        if (head == nullptr)
            head = current;

        tail = current;
        std::cout << "Число добавлено в список" << std::endl;
    };
    void pop_front()
    {
        if (head != nullptr)
        {
            Node* current = head->next;

            if (current != nullptr)
                current->prev = nullptr;
            else
                tail = nullptr;

            delete head;
            head = current;
            std::cout << "Число удалено из списка" << std::endl;
        }
        else
            std::cout << "Cписок пуст" << std::endl;
    };
    void pop_back()
    {
        if (tail != nullptr)
        {
            Node* current = tail->prev;

            if (current != nullptr)
                current->next = nullptr;
            else
                head = nullptr;

            delete tail;
            tail = current;
            std::cout << "Число удалено из списка" << std::endl;
        }
        else
            std::cout << "Cписок пуст" << std::endl;
    };
    void display()
    {
        if (head != nullptr)
        {
            Node* current = head;
            while (current != nullptr)
            {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
        else
            std::cout << "Список пуст" << std::endl;
    };
    void Sort() {
        if (head == nullptr || head->next == nullptr) {
            return; // Список пуст или содержит только один элемент
        }

        bool swapped;
        Node* current;
        Node* last = nullptr;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    // Меняем местами данные
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    };

    void remove_duplicates()
    {
        if (head != nullptr)
        {
            Node* previous = head;
            Node* current = head->next;

            while (current != nullptr)
            {
                Node* comparer = head;
                while (comparer != current)
                {
                    if (comparer->data == current->data)
                    {
                        Node* merger = current->next;
                        previous->next = merger;
                        current = merger;
                        break;
                    }
                    comparer = comparer->next;
                }
                if (comparer == current)
                {
                    previous = current;
                    current = current->next;
                }
            }
            std::cout << "Все дубликаты были удалены из списка" << std::endl;
        }
        else
            std::cout << "Список пуст" << std::endl;
    };
};
int main()
{
    setlocale(LC_ALL, "");
    DoublyLinkedList list;
    while (true)
    {
        std::cout << "\nВведите цифру действия:\n" <<
            "1 - Добавить элемент в начало\n" <<
            "2 - Добавить элемент в конец\n" <<
            "3 - Удалить элемент с начала\n" <<
            "4 - Удалить элемент с конца\n" <<
            "5 - Отобразить список\n" <<
            "6 - Сортировать список\n" <<
            "7 - Удалить дубликаты\n" <<
            "8 - Выйти\n\n";
        std::string answer;
        std::getline(std::cin, answer);
        if (answer == "1")
        {
            try
            {
                std::cout << "Введите целое число: ";
                std::string number;
                std::getline(std::cin, number);
                int N = stoi(number);
                list.push_front(N);
            }
            catch (...)
            {
                std::cout << "Вводите только целые числа" << std::endl;
            }
        }
        else if (answer == "2")
        {
            try
            {
                std::cout << "Введите целое число: ";
                std::string number;
                std::getline(std::cin, number);
                int N = stoi(number);
                list.push_back(N);
            }
            catch (...)
            {
                std::cout << "Вводите только целые числа" << std::endl;
            }
        }
        else if (answer == "3")
        {
            list.pop_front();
        }
        else if (answer == "4")
        {
            list.pop_back();
        }
        else if (answer == "5")
        {
            list.display();
        }
        else if (answer == "6")
        {
            list.Sort();
            std::cout << "Сортировка выполнена" << std::endl;
        }
        else if (answer == "7")
        {
            list.remove_duplicates();
        }
        else if (answer == "8")
        {
            break;
        }
        else
        {
            std::cout << "Вводите только числа от 1 до 8" << std::endl;
        }
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
