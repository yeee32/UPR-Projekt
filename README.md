# League of Legends statistiky

Program analyzuje záznamy her z League of Legends. 
Výsledek je uložen do HTML souboru a obsahuje tabulku s jednotlivými statistikami a SVG grafy.

## Překlad programu
```
mkdir build
cd build
```
```
cmake ..
```
```
make
```
## Spuštění
```
./lolstats <soubor_her> <soubor_hracu> <vystupni_soubor>
```
### Příklad spuštění
```
./lolstats matches.txt players.txt index.html
```
