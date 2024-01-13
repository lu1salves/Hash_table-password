"""
Esse programa em python gera a quantidade necessaria de senhas para fazermos alguns testes na nossa tabela hash    
"""

import random
import string

def generate_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choice(characters) for _ in range(length))

#altere esse número para a quantidade necessária de senhas que você preferir
num_passwords = 100
min_length = 8 #tamanho mínimo de senhas
max_length = 16 #tamanho máximo de senhas

with open('senhas.txt', 'w') as file:
    for _ in range(num_passwords):
        password_length = random.randint(min_length, max_length)
        password = generate_password(password_length)
        file.write(password + '\n')

print(f'Foram geradas {num_passwords} senhas e salvas no arquivo "senhas.txt".')
