#pragma once
#include <vector>
#include <list>
#include <string>
#include <utility>

using KeyType = std::string;
using ValueType = double;

class HashTable {
private:
    int32_t _capacity;  //!< Вместимость хеш-таблицы
    int32_t _filled;    //!< Текущее количество занятых ячеек хеш-таблицы

    //! Структура, на которой основана таблица с методом цепочек для решения коллизий
    std::vector<std::list<std::pair<KeyType, ValueType>>> table;
    //! Хеш-функция
    size_t hash_function(const KeyType &key) const;
public:
    //! Конструктор
    explicit HashTable(size_t size = 100) noexcept;
    //! Деструктор
    ~HashTable();

    //! Вставка элемента в хеш-таблицу
    //! Если при вставке обнаруживается, что LoadFactor таблицы превышает 0.75, то таблица расширяется в 2 раза.
    void insert(const KeyType &key, const ValueType &value);
    //! Поиск элемента в хеш таблице
    bool find(const KeyType &key, ValueType &value) const;
    //! Удаление элемента из хеш-таблицы
    void remove(const KeyType &key);
    //! Получение элемента по ключу
    ValueType& operator[](const KeyType &key);

    //! Загрузка хеш-таблицы. Считается как отношение количества занятых ячеек к вместимости хеш-таблицы.
    double getLoadFactor();
};