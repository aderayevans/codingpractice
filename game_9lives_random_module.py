import random

lives = 9
words_level1 = ['eat', 'map', 'key', 'gas', 'fly', 'cry']
words_level2 = ['pizza', 'apple', 'fairy', 'shirt', 'teeth', 'plane']
words_level3 = [
    'correct', 'disable', 'measure', 'exactly', 'machine', 'quality'
]
clue = []
index = 0
difficulty = input('Choose difficulty (type 1, 2 or 3):'
                   '\n 1 Easy'
                   '\n 2 Normal'
                   '\n 3 Hard'
                   '\n My choose is ... ')
difficulty = int(difficulty)
if difficulty == 1:
    lives = 12
    secret_word = random.choice(words_level1)
elif difficulty == 2:
    lives = 9
    secret_word = random.choice(words_level2)
else:
    lives = 6
    secret_word = random.choice(words_level3)
while index < len(secret_word):
    clue.append('?')
    index = index + 1
heart_symbol = u'\u2764'
guessed_word_correctly = False
unknown_letters = len(secret_word)


def update_clue(guessed_letter, secret_word, clue, unknown_letters):
    index = 0
    while index < len(secret_word):
        if guessed_letter == secret_word[index]:
            clue[index] = guessed_letter
            unknown_letters = unknown_letters - 1
        index = index + 1
    return unknown_letters


while lives > 0:
    print(clue)
    print('Lives left: ' + heart_symbol + ' x ' + str(lives))
    guess = input('Guess a letter or the whole word: ')

    if guess == secret_word:
        guessed_word_correctly = True
        break
    if guess in secret_word:
        unknown_letters = update_clue(guess, secret_word, clue,
                                      unknown_letters)
    else:
        print('Incorrect. You lose a life')
        lives = lives - 1
    if unknown_letters == 0:
        guessed_word_correctly = True
        break
if guessed_word_correctly:
    print('You won! The secret word was ' + secret_word)
else:
    print('You lost! The secret word was ' + secret_word)
