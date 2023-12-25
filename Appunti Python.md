# Appunti python

Ecco un riassunto dei comandi base in Python:

**1. Variabili e Tipi di Dati:**

- `x = 5`: Assegna il valore 5 alla variabile x.

- `int`, `float`, `str`, `list`, `tuple`, `dict`, `set`: Rappresentano i diversi tipi di dati supportati in Python.

```python
var=10  
str_dinamica = f’la variabile ha valore: {var}’
#Input
res = input(‘inserisci qualcosa’)
```

## **2. Operazioni Matematiche:**

- `+`, `-`, `*`, `/`: Eseguono operazioni matematiche di addizione, sottrazione, moltiplicazione e divisione.
- `%`: Restituisce il resto della divisione.

## **3. Input/Output:**

- `print("Testo")`: Stampa il testo sulla console.
- `input("Prompt")`: Riceve l'input dall'utente tramite la console.

## **4. Costrutti di Base:**

- `if`, `elif`, `else`: Permettono di eseguire istruzioni condizionali.

```python
if condiziONE:

elif codiziTWO:

else:
    condiziTHREE
```

- `for elemento in sequenza:`: Itera attraverso gli elementi di una sequenza.

Lo statement  for chiama __iter__() e poi __next__() sull'oggetto
ritornato

```python
for i in range(10): 
    print(i)
#range(inizio, fine, intervallo)
range(0,10,2) -> 0,2,4,6,8
range(0,5) -> 0,1,2,3,4
range(5) -> 0,1,2,3,4
a = 'cio'    #Stringhe
for i in a: print(i) -> c i o 
a = set(['a','b'])    #SET
for i in a: print(i) -> a\n b\n 
a = {'key1': 1, 'key2': 2}    #Dizionari
for i in a: print(i) -> key1\n key2\n 
a = 'abc'    #Enumara la sequenza su cui si itera
for i,o in enumerate(a): print(i)#stampa (0,'a')(1,'b')(2,'c')
-> 0\n 1\n 2\n 
```

- `while condizione:`: Esegue un blocco di istruzioni finché la condizione è vera.

```python
while b<10: #funche la condizione e' vera
    b=b+1
else: #quando esce esegue 100
    b=100
```

- `break`, `continue`: Modificano il flusso di esecuzione di cicli (for/while).

`break -> interrompe un ciclo for/while
continue -> salta all'iterazione for/while successiva`

## **5. Funzioni:**

- `def nome_funzione(parametri):`: Definisce una funzione con i relativi parametri.

E’ possibile anche specificare a quale parametro ci si riferisce (keyword
arguments)

![](C:\Users\Bale\Downloads\ImgMd\2023-12-24-15-07-32-image.png)

```python
def funzione(*args, **kwargs):
#args sono tutti i parametri posizionali
#kwargs sono tutti gli argomenti dei keyword condenzati in un dizionario
a = [1,2,3,4,5]
funzione(*a) # equivale a funzione(1,2,3,4,5)
a = {a:1, b:2, c:3}#Vale anche per i Dizionario
funzione(**a) equivale a funzione(a=1,b=2,c=3)
```

- `return valore`: Restituisce un valore dalla funzione.
- `args`, `kwargs`: Parametri arbitrari in una funzione (argomenti posizionali, argomenti keyword).

## **6. Liste, Tuple, Dizionari e Set:**

- `lista = [1, 2, 3]`: Definisce una lista.
- `tupla = (1, 2, 3)`: Definisce una tupla.
- `dizionario = {'chiave': 'valore'}`: Definisce un dizionario.
- `insieme = {1, 2, 3}`: Definisce un insieme.

## **7. Gestione delle Eccezioni:**

- `try:`, `except:`, `finally:`: Gestiscono le eccezioni e i potenziali errori durante l'esecuzione del codice.

## **8. File I/O:**

- `open('file.txt', 'r')`: Apre un file in modalità lettura.
- `open('file.txt', 'w')`: Apre un file in modalità scrittura.
- `read()`, `write()`, `close()`: Metodi per leggere, scrivere e chiudere file.

## **9. Moduli e Importazioni:**

- `import nome_modulo`: Importa i moduli esterni(librerie) per utilizzarne nel codice

```python
import pandas
a = pandas.DataFrame()
```

- `from modulo import oggetto`: Importa specifici oggett(funzioni)i da un modulo.

```python
from pandas import DataFrame
a = DataFrame()
from pandas import * #importa tutte le funzioni del modulo
```

## **10. Gestione di Stringhe:**

- `len(stringa)`: Restituisce la lunghezza di una stringa.
- `stringa.lower()`, `stringa.upper()`: Modificano il case della stringa.
- `stringa.split(delimitatore)`: Suddivide una stringa in una lista di sottostringhe.

Questi sono solo alcuni dei comandi base in Python. Esistono molte altre funzioni e librerie che possono essere utilizzate per svolgere una vasta gamma di attività di programmazione. La pratica e l'esplorazione costante aiuteranno a comprendere meglio e a utilizzare appieno il linguaggio Python.
