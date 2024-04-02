#include <iostream>
#include <fstream>
#include "cpp/User.cpp"

int main()
{
    /*
    ios::арр 	Добавляет данные в конец файла; после каждой операции записи текущая позиция устанавливается в конец файла.
    ios::ate 	Устанавливает текущую позицию в конец файла.
    ios::trunc 	Удаляет все содержимое файла.
    ios::binary 	Разрешает выполнение двоичных операций над потоком (также может использоваться при чтении из файла).
    */

    // Создаем объект типа ifstream с именем file_reader
    std::ifstream file_reader("txt/input.txt");
    if(!file_reader.is_open())
    {
        std::cout << "Could not open file" << std::endl;
    }
    int number;
    // Проверяем успешность считывания целого числа
    if(file_reader >> number)
    {
        std::cout << number << std::endl;
    }

    /*
    iosbase::beg 	Поиск от начала файла.
    iosbase::cur 	Поиск от текущей позиции.
    iosbase::end 	Поиск от конца файла.
    */

    // Откроем файл для записи, если его не было, то он создастся
    std::ofstream file_writer("txt/helloFile.txt");
    if(!file_writer.is_open())
    {
        std::cout << "Could not open file" << std::endl;
        return 0;
    }
    // Запишем в файл строку hello, world
    file_writer << "hello world";
    // Скорректируем строку, чтобы в файле получилось 
    // строка Hello, Linux!
    file_writer.seekp(6);
    file_writer << "Linux";
    file_writer.seekp(0, std::ios_base::beg);
    file_writer << "H";
    file_writer.seekp(0, std::ios_base::end);
    file_writer << "!";



    // Запись и чтение экземпляра класса User
    fstream user_file = fstream("txt/users.txt", ios::in | ios::out);
	if (!user_file) 
		// Для создания файла используем параметр ios::trunc
        user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
	
	if (user_file) {
		User obj("Alex", "qwerty", "12345");
        // Запишем данные в файл
		user_file << obj << endl;
        // Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
        // Считываем данные из файла
		user_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}










    file_writer.close();

    return 0;
}