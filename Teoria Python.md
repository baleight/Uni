# Teoria Python

#### Programmazione di ordine superiore

> Si definisce un linguaggio come di ordine superiore se consente di utilizzare
> funzioni come valori.
> Le funzioni possono essere passate ad altre funzioni
> Possono essere ritornate come risultato di altre funzioni

Es: def print_function_result(func):
            print(f’il risultato è {func()}’)

##### Closure

Se avessimo una funzione inizializzabile che poi stampi sempre lo stesso messaggio quando chiamata. si puo creare una funzione che preso il parametro di inizializzazione restituisce una funzione che stampa sempre quel messaggio.

```python
def print_msg(msg):
    def printer(): #printer accede a msg che non fa parte della funzione
        print(msg)
    return printer
```

il concetto di closure: Le funzioni innestate possono accedere alle variabili dele funzioni madri. Le variabili sono incapsulate nelle funzioni figlie in modo che possano essere utilizzate anche quando le funzioni madre termina.

##### Funzioni di esempio per gli ordini superiori:

- map()

  Prende in ingresso una funzione e una sequenza di oggetti. Esegue tale funzione e ogni oggetto e ne ritorna il risultato come lista.

```python
def quad(a)
    return a**2
#S  
map(quad, [1,2,3]) 
```

##### LAMBDA (funzione anonima)

Python permette di passare la funzione senza definirla in un altro punto del
codice.

lambda argomenti: valore di ritorno Es:map(lambda x:x**2, [1,2,3])

##### Generatori

generato ad ogni iterazione l’elemento successivo.
E come se ritornassero una serie di valori invece che un unico risultato.
Si creano attraverso il comando yield seguito dal valore da tornare

Quando una funzione contiene il comando yield, essa viene trattata da Python
come un Generatore.
Implicitamente viene dotata dei metodo __iter__ e __next__

```python
Esempio: range() fai da te!
def range(stop):
i = 0
while i < stop:
yield i
i = i + 1
```

I Generatori possono anche essere creati con una sintassi molto stringata.

Sintassi: (espressione for variabili in sequenza)
Esempioo: **(x^2 for x in range(10))**

il generatore ritornerà ad ogni iterazione il quadrato dei numeri da 0 a 9

Una sintassi simile (usando [] invece che ()) può essere usata per
generare liste in modo immediato:

a = [x**2 for x in range(10)]

a conterrà una lista dei quadrati da 0 a 9
