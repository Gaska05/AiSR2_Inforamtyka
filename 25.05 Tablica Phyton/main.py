# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')
my_list = [1,2,3,4,5,6,7,8,9,10]

while True:

    print("=== MENU ===")
    print("1. Wypisz zawartosc tablicy")
    print("2. Znajdz wartosc minimalna")
    print("3. Znajdz wartosc maksymalna")
    print("4. Oblicz sume elementow")
    print("5. Oblicz srednia")
    print("6. Wprowadz nowe dane do tablicy")
    print("0. Wyjscie")

    user_input = input("Wybór opcji: ")
    match user_input:
        case "1":
            print("Zawartosc tablicy:")
            for element in my_list:
                print(element)
        case "2":
            print("Zawartosc minimalna:")
            print(min(my_list))
        case "3":
            print("Zawartosc maksymalna:")
            print(max(my_list))
        case "4":
            print("Suma elementow:")
            print(sum(my_list))
        case "5":
            print("Wartosc srednia:")
            print(sum(my_list) / 10)
        case "6":
            print("Wprowadz wartości tablicy:")
            my_list.clear()
            ile_liczb = int(input("Ile licz chcesz wprowadzic: "))
            for i in range(ile_liczb):
                nowa = int(input(f"Podaj nowa liczbe: "))
                my_list.append(nowa)
        case "0":
            print("Wyjscie")
            break
        case _:
            print("Wyjscie")





