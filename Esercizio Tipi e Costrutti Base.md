###### ES5: Scrivere un programma che stampi per tutti i numeri da 0 a 100 se sono pari o dispari



###### Es4: Modificare il programma precedente in modo da non terminare finchè l’utente

# Esercizio Tipi e Costrutti Base

###### Es 1: Scrivere un programma che prenda un testo inserito dall’utente e lo mostri a video con un preambolo (es. ‘hai inserito questo: ‘)

```python
def stampa_nome(name):
    print(f'Ciao, {name}'+'!!!')

if __name__ == '__main__':
    nomeInput = input('scrivi il tuo nome?')
    stampa_nome(nomeInput) 
```

###### Es2: Scrivere un programma che prenda un valore inserito dall’utente e mostri a video il tipo che assume la variabile in cui viene inserito.

```python
valore = input("Inserisci un valore: ")  # Chiede all'utente di inserire un valore
# Utilizza la funzione type() per determinare il tipo della variabile
tipo_valore = type(valore)
# Mostra il tipo della variabile
print(f"Il tipo del valore inserito è: {tipo_valore}")
```

###### Es3: Scrivere un programma che prenda un valore inserito dall’utente Se è 1 stampa ‘red’ Se è 2 stampa ‘blue’ Se è 3 stampa ‘green' Negli altri casi stampa un messaggio di errore

```python
 while True:
        valore = input("Inserisci un valore: ")

        if valore == '1':
            print('red')
            break
        elif valore == '2':
            print('blue')
            break
        elif valore == '3':
            print('green')
            break
        else:
            print('Messaggio di errore: Valore non valido. Inserisci nuovamente.')
```

###### Es3: Modificare il programma precedente in modo da usare un solo if e nessun elif.

```python
colore_dict = {
    '1': 'red',
    '2': 'blue',
    '3': 'green'
}

valore = input("Inserisci un valore: ")

if valore in colore_dict:
    print(colore_dict[valore])
else:
    print('Messaggio di errore: Valore non valido.')

```

###### Es4: Modificare il programma precedente in modo da non terminare finchè l’utente

```python

   
def stampa_red():
        print('red')


def stampa_blue():
        print('blue')


def stampa_green():
        print('green')


colore_dict = {
        '1': stampa_red,
        '2': stampa_blue,
        '3': stampa_green
}

while True:
        valore = input("Inserisci un valore (oppure digita 'fine' per uscire): ")

        if valore == 'fine':
            break

        funzione_stampa = colore_dict.gset(valore)

        if funzione_stampa:
            funzione_stampa()
        else:
            print('Messaggio di errore: Valore non valido.')rrore: Valore non valido.')
```

###### ES5: Scrivere un programma che stampi per tutti i numeri da 0 a 100 se sono pari o dispari

```python
for numero in range(101):
    if numero % 2 == 0:
        print(f"Il numero {numero} è pari.")
    else:
        print(f"Il numero {numero} è dispari.")

```

###### Es:6 Scrivere un programma che simuli una rubrica telefonica.

###### L’utente deve poter scegliere se inserire un numero, cancellarlo o stampare l’intera rubrica. La struttura della rubrica è molto semplice ogni contatto ha un nome e un

```python
rubrica = {}  # Dizionario per memorizzare i contatti (nome: numero)

def inserisci_contatto():
    nome = input("Inserisci il nome del contatto: ")
    numero = input("Inserisci il numero di telefono: ")
    rubrica[nome] = numero
    print(f"Contatto '{nome}' con numero '{numero}' aggiunto alla rubrica.")

def cancella_contatto():
    nome = input("Inserisci il nome del contatto da cancellare: ")
    if nome in rubrica:
        del rubrica[nome]
        print(f"Contatto '{nome}' cancellato dalla rubrica.")
    else:
        print("Il contatto specificato non esiste nella rubrica.")

def stampa_rubrica():
    if rubrica:
        print("Rubrica Telefonica:")
        for nome, numero in rubrica.items():
            print(f"Nome: {nome} - Numero: {numero}")
    else:
        print("La rubrica è vuota.")

# Menu principale
while True:
    print("\n*** Menu Rubrica Telefonica ***")
    print("1. Inserisci contatto")
    print("2. Cancella contatto")
    print("3. Stampare rubrica")
    print("4. Esci")

    scelta = input("Seleziona un'opzione: ")

    if scelta == '1':
        inserisci_contatto()
    elif scelta == '2':
        cancella_contatto()
    elif scelta == '3':
        stampa_rubrica()
    elif scelta == '4':
        print("Grazie per aver utilizzato la rubrica telefonica. Arrivederci!")
        break
    else:
        print("Opzione non valida. Riprova.")

```

###### ES7: Scrivere un programma che prenda in input un testo lungo. Stampi la frequenza di ogni carattere.

```python
testo = input("Inserisci un testo: ")

frequenza_caratteri = {} #dizionario

# Calcolo della frequenza dei caratteri nel testo
for carattere in testo:
    if carattere in frequenza_caratteri:
        frequenza_caratteri[carattere] += 1
    else:
        frequenza_caratteri[carattere] = 1 #craezione

# Stampare la frequenza dei caratteri
print("Frequenza dei caratteri nel testo:")
for carattere, frequenza in frequenza_caratteri.items():
    print(f"Carattere '{carattere}': {frequenza} volte")

```




