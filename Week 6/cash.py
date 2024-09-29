from cs50 import get_float


def main():
    dollars = calculate_dollars()
    coins = calculate_coins(dollars)
    print(coins)


def calculate_dollars():
    while True:
        try:
            dollars = get_float("Change: ")
            if dollars >= 0:
                return round(dollars * 100)
        except:
            pass


def calculate_coins(cents):
    coins_general = [25, 10, 5, 1]
    coins = 0
    for coin in coins_general:
        coins += cents // coin
        cents %= coin
    return coins


main()
