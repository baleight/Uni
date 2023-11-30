

Es1

```python
a = """ afwefgewgewgwegwfewf
fqwfqewfqfgqwefqfg
qfgqg
qefqfgqg """
s = list(map(lambda x: x.upper(), filter(lambda x: x not in['a','e','i','o','',''])
```



Es2

```python
from functools import reduce

a = "aaabbbbccgewgweg"

print((reduce(lamda x,y: x | {y: x.get(y, 0)+1}, a, {})))
```

Es3

```python
from functools import reduce
s = "aaaabbcdeeeffgggiiiii"
lista_s = [s for i in range(10)]
#print(lista_s)
map_f = lambda a: reduce(lamda x,y: x| { y: x.get(y, 0)+1}, a,{})
print(list(map(reduce_f, map(map_f, lista_s)))
reduce_f = lamda x,y: x | {k: x.get(k, 0}=v for k, v in y.items()}
print(reduce(reduce_f, map(map_f, lista_s))
```





Es 4

```python
a = input('inserire calcolo')
b = eval(a)
print(b)
```
