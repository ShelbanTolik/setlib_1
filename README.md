

## Возможности
- Поддержка операций: включение, объединение, пересечение, разность, симметрическая разность, дополнение.
- Работа с битовыми массивами.
- Использование AddressSanitizer, clang-format, cppcheck.

## Сборка и запуск

```bash
make
./build/test
```

## Анализ кода

```bash
make format
make check
make valgrind
```

## Структура
- `include/set.h`: заголовок
- `src/set.c`: реализация
- `test/test.c`: тесты
- `Makefile`: сборка + анализ
